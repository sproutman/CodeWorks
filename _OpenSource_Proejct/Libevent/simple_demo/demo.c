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


     struct event listen_ev;   //�������¼��ṹ
     base = event_base_new();  //�����¼�����ȫ�ֱ�����������պ��ɷ������������IO�¼�����Ϣ

	 //��listen_en����¼�����sock��������ֵĶ�����(�ͻ��˷�������ʱ),������Ϣ�����ǵ���on_accept����
     event_set(&listen_ev, sock, EV_READ|EV_PERSIST, on_accept, NULL); 

     //��listen_evע�ᵽbase����¼��У��൱�ڸ��ߴ���IO�Ĺܼ��������ҵ�listen_ev�ϵ��¼�
     event_base_set(base, &listen_ev);

	 //�൱�ڸ��ߴ���IO�Ĺܼң������ҵ��¼�����ʱ��֪ͨ��(�����ҵ�on_accept����)
     event_add(&listen_ev, NULL);

	 //����libevent���¼�������ƣ�ʹϵͳ��������
     event_base_dispatch(base);

     return 0;
 }
