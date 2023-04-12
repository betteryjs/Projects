#include	<time.h>

#include <stdio.h>
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */



#include	<sys/socket.h>	/* basic socket definitions */

#include	<arpa/inet.h>	/* inet(3) functions */

#include	<string.h>
#include	<sys/stat.h>	/* for S_xxx file mode constants */
#include	<unistd.h>




const unsigned short SERVER_PORT = 2356;
const char SERVER_IP[] = "0.0.0.0";


int main(int argc, char **argv)
{
    int listenfd, connfd;
    struct  sockaddr_in servaddr;
    time_t ticks;
    char buff[4096];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    servaddr.sin_family = AF_INET;

    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    servaddr.sin_port        = htons(SERVER_PORT);	/* daytime server */
    inet_pton(AF_INET, SERVER_IP, &servaddr.sin_addr.s_addr);

    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));


    listen(listenfd, 128);


    for ( ; ; ) {
		connfd = accept(listenfd, (struct  sockaddr *) NULL, NULL);

        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        write(connfd, buff, strlen(buff));

		close(connfd);
	}
    return 0;
}
