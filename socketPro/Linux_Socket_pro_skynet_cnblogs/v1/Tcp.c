#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MAXLINE 4096

int main(int argc, char** argv)
{
    int    listenfd, connfd;
    struct sockaddr_in     servaddr;
    char    buff[4096];
    int     n;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
    printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    /* Enable address reuse */
    int on,ret; 
    on = 1;
    ret = setsockopt( listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on) );


    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(7080);

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
    printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    if( listen(listenfd, 10) == -1){
    printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    printf("======waiting for client's request======\n");


    while(1)  //why this loop not work ?
    {

	    //receive data from vpn client
	    if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1)
	    {
		printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
		continue;
	    }

	    
	    n = recv(connfd, buff, MAXLINE, 0);
	    buff[n] = '\0';
	    printf("recv msg from client: %s\n", buff); 

	    sleep(1); 


 	    //receive data from vpn client  again !!!
	    // 加此句的主要目的是 open客户端 会先发 两条信息过来 
	    //并且有时间顺序 不加的话 无法显示此信息
	    
	    n = recv(connfd, buff, MAXLINE, 0);
	    buff[n] = '\0';
	    printf("recv msg from client: %s\n", buff); 

	    
	    // 此时 只能输入hold release,否则open客户端停止不动
	    // Server input something,Then send it to client
	    printf("send hold release msg to Client Now !: \n");

	    char sendline[4096];
	    fgets(sendline, 4096, stdin);

	    if( send(connfd, sendline, strlen(sendline), 0) < 0) 
	    {
	    printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
	    exit(0);
	    }
    }
    close(connfd);
    close(listenfd);
}
