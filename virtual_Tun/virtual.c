//  虚拟网卡程序   建立虚拟网卡的程序
//  setup a vitual tun dev

#include <unistd.h>   
#include <stdio.h>   
#include <curses.h>   
#include <string.h>   
#include <assert.h>   
#include <sys/types.h>   
#include <sys/socket.h>   
#include <netinet/in.h>   
#include <signal.h>   
#include <unistd.h>   
#include <linux/if_tun.h>   
#include <netinet/in.h>   
#include <sys/ioctl.h>   
#include <sys/time.h>   
#include <linux/if.h>   
#include <netinet/in.h>   
#include <arpa/inet.h>   
#include <errno.h>   
#include <fcntl.h>     
 int tun_creat(char *dev,int flags)   
   {   
    struct ifreq ifr;   
    int fd,err;   
    assert(dev != NULL);   
    if((fd = open ("/dev/net/tun",O_RDWR))<0) //you can replace it to tap to create tap device.   
    return fd;   
    memset(&ifr,0,sizeof (ifr));   
   ifr.ifr_flags|=flags;   
   if(*dev != '\0')   
   strncpy(ifr.ifr_name,dev,IFNAMSIZ);   
    if((err = ioctl(fd,TUNSETIFF,(void *)&ifr))<0)   
  {   
    close (fd);   
     return err;   
  }   
    strcpy(dev,ifr.ifr_name);   
   return fd;   
  }   
  
  int main()   
   {   
   int tun,ret;   
    char tun_name[IFNAMSIZ];   
   unsigned char buf[4096];   
    tun_name[0]='\0';   
    tun = tun_creat(tun_name,IFF_TUN|IFF_NO_PI);//如果需要配置tun设备，则把"IFF_TAP"改成“IFF_TUN”   
    if(tun<0)   
   {   
     perror("tun_create");   
    return 1;   
  }   
    printf("TUN name is %s\n",tun_name);   
           while (1) {   
                  unsigned char ip[4];   
  
                  ret = read(tun, buf, sizeof(buf));   
                 if (ret < 0)   
                          break;   
                   memcpy(ip, &buf[12], 4);   
                   memcpy(&buf[12], &buf[16], 4);   
                  memcpy(&buf[16], ip, 4);   
                  buf[20] = 0;   
                 *((unsigned short*)&buf[22]) += 8;   
                  printf("read %d bytes\n", ret);   
                  ret = write(tun, buf, ret);   
                 printf("write %d bytes\n", ret);   
         }   
    return 0;   
  }  
