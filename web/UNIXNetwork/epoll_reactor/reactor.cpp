//反应堆简单版
#include "wrap.h"
#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>


const short _BUF_LEN_ = 1024;
const short _EVENT_SIZE_ = 1024;
const int _ServerPort_ = 8000;


//全局epoll树的根
int gepfd = 0;

//事件驱动结构体
struct xx_event {
    int fd;
    int events;

    void (*call_back)(int fd, int events, void *arg);

    void *arg;
    char buf[1024];
    int buflen;
    int epfd;
};

xx_event myevents[_EVENT_SIZE_ + 1];

void readData(int fd, int events, void *arg);

//添加事件
//eventadd(lfd,EPOLLIN,initAccept,&myevents[_EVENT_SIZE_-1],&myevents[_EVENT_SIZE_-1]);
void eventadd(int fd, int events, void (*call_back)(int, int, void *), void *arg, xx_event *ev) {
    ev->fd = fd;
    ev->events = events;
    //ev->arg = arg;//代表结构体自己,可以通过arg得到结构体的所有信息
    ev->call_back = call_back;

    struct epoll_event epv;
    epv.events = events;
    epv.data.ptr = ev;                        //核心思想
    epoll_ctl(gepfd, EPOLL_CTL_ADD, fd, &epv);//上树
}

//修改事件
//eventset(fd,EPOLLOUT,senddata,arg,ev);
void eventset(int fd, int events, void (*call_back)(int, int, void *), void *arg, xx_event *ev) {
    ev->fd = fd;
    ev->events = events;
    //ev->arg = arg;
    ev->call_back = call_back;

    struct epoll_event epv;
    epv.events = events;
    epv.data.ptr = ev;
    epoll_ctl(gepfd, EPOLL_CTL_MOD, fd, &epv);//修改
}

//删除事件
void eventdel(xx_event *ev, int fd, int events) {
    printf("begin call %s\n", __FUNCTION__);

    ev->fd = 0;
    ev->events = 0;
    ev->call_back = NULL;
    memset(ev->buf, 0x00, sizeof(ev->buf));
    ev->buflen = 0;

    struct epoll_event epv;
    epv.data.ptr = NULL;
    epv.events = events;
    epoll_ctl(gepfd, EPOLL_CTL_DEL, fd, &epv);//下树
}

//发送数据
void senddata(int fd, int events, void *arg) {
    printf("begin call %s\n", __FUNCTION__);

    xx_event *ev = reinterpret_cast<xx_event *>(arg);
    Write(fd, ev->buf, ev->buflen);
    eventset(fd, EPOLLIN, readData, arg, ev);
}

//读数据
void readData(int fd, int events, void *arg) {
    printf("begin call %s\n", __FUNCTION__);
    xx_event *ev = reinterpret_cast<xx_event *>(arg);

    ev->buflen = Read(fd, ev->buf, sizeof(ev->buf));
    if (ev->buflen > 0)//读到数据
    {
        //void eventset(int fd,int events,void (*call_back)(int ,int ,void *),void *arg,xevent *ev)
        eventset(fd, EPOLLOUT, senddata, arg, ev);

    } else if (ev->buflen == 0)//对方关闭连接
    {
        Close(fd);
        eventdel(ev, fd, EPOLLIN);
    }
}

//新连接处理
void initAccept(int fd, int events, void *arg) {
    printf("begin call %s,gepfd =%d\n", __FUNCTION__, gepfd);//__FUNCTION__ 函数名

    int i;
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int cfd = Accept(fd, (struct sockaddr *) &addr, &len);//是否会阻塞？

    //查找myevents数组中可用的位置
    for (i = 0; i < _EVENT_SIZE_; i++) {
        if (myevents[i].fd == 0) {
            break;
        }
    }

    //设置读事件
    eventadd(cfd, EPOLLIN, readData, &myevents[i], &myevents[i]);
}

int main(int argc, char *argv[]) {
    //创建socket
    int lfd = Socket(AF_INET, SOCK_STREAM, 0);

    //端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    //绑定
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(_ServerPort_);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    Bind(lfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    //监听
    Listen(lfd, 128);

    //创建epoll树根节点
    gepfd = epoll_create(1024);
    printf("gepfd === %d\n", gepfd);

    struct epoll_event events[1024];

    //添加最初始事件，将侦听的描述符上树
    eventadd(lfd, EPOLLIN, initAccept, &myevents[_EVENT_SIZE_], &myevents[_EVENT_SIZE_]);
    //void eventadd(int fd,int events,void (*call_back)(int ,int ,void *),void *arg,xevent *ev)

    while (1) {
        int nready = epoll_wait(gepfd, events, 1024, -1);
        if (nready < 0)//调用epoll_wait失败
        {
            perr_exit("epoll_wait error");

        } else if (nready > 0)//调用epoll_wait成功,返回有事件发生的文件描述符的个数
        {
            int i = 0;
            for (i = 0; i < nready; i++) {
                xx_event *xe = reinterpret_cast<xx_event *>(events[i].data.ptr);//取ptr指向结构体地址
                printf("fd=%d\n", xe->fd);

                if (xe->events & events[i].events) {
                    xe->call_back(xe->fd, xe->events, xe);//调用事件对应的回调
                }
            }
        }
    }

    //关闭监听文件描述符
    Close(lfd);

    return 0;
}