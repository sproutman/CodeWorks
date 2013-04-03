/* a simple socket server , run it first ,then open a telnet clinet and there is a result*/
/* 1 ./server */
/* 2 telnet 127.0.0.1 25431 */

#include <event.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>



#define PORT 25341
#define BACKLOG 5
#define MEM_SIZE 1024

 struct event_base* base;


 void on_accept(int sock, short event, void* arg)
    {
	 	 sleep(5);
	 	 printf("Now Callback function is exeute!!! \n");
    }



 int main(int argc, char* argv[])
 {
     struct sockaddr_in my_addr;
     int sock;

     sock = socket(AF_INET, SOCK_STREAM, 0);
     int yes = 1;
     setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
     memset(&my_addr, 0, sizeof(my_addr));
     my_addr.sin_family = AF_INET;
     my_addr.sin_port = htons(PORT);
     my_addr.sin_addr.s_addr = INADDR_ANY;
     bind(sock, (struct sockaddr*)&my_addr, sizeof(struct sockaddr));
     listen(sock, BACKLOG);


     struct event listen_ev;   //定义监控事件结构
     base = event_base_new();  //创建事件处理全局变量，负责接收和派发所有输入输出IO事件的信息

	 //在listen_en这个事件监听sock这个描述字的读操作(客户端发起连接时),当读消息到达是调用on_accept函数
     event_set(&listen_ev, sock, EV_READ|EV_PERSIST, on_accept, NULL); 

     //将listen_ev注册到base这个事件中，相当于告诉处理IO的管家请留意我的listen_ev上的事件
     event_base_set(base, &listen_ev);

	 //相当于告诉处理IO的管家，当有我的事件到达时你通知我(调用我的on_accept函数)
     event_add(&listen_ev, NULL);

	 //启动libevent的事件处理机制，使系统运行起来
     event_base_dispatch(base);

     return 0;
 }
