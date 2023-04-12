
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>	/* sockaddr_in{} and other Internet defns */



#include	<sys/socket.h>	/* basic socket definitions */

#include	<arpa/inet.h>	/* inet(3) functions */

#include	<string.h>

#include	<unistd.h>

#define	MAXLINE		4096	/* max text line length */



int main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;


	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){

        printf("socket error");
        return -1;

    }

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(2356);	/* daytime server */
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    connect(sockfd, (struct sockaddr *)  & servaddr, sizeof(servaddr));


    n = read(sockfd, recvline, sizeof(recvline));
    write(STDOUT_FILENO, recvline, n);



    return 0;
}
