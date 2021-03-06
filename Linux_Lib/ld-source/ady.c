/************************************/
/* 文件名称: ady.c                  */
/* 功能描述: 动态链接库高级应用示范 */
/* 程序编写: 纵横软件制作中心雨亦奇 */
/* 编写时间: 2002-03-08             */
/************************************/

#include	"stdio.h"	/* 包含标准输入输出文件 */
#include	"adatetime.h"	/* 包含用户接口文件 */

main()
{
 DATETYPE	d;
 TIMETYPE	t;

 puts("动态链接库高级应用示范");

 getdate(&d);			/* 调用此共享函数 */
 printf("当前日期: %04d-%02d-%02d\n",d.year,d.mon,d.day);
 
 gettime(&t);			/* 调用此共享函数 */
 printf("当前时间: %02d:%02d:%02d\n",t.hour,t.min,t.sec);

 exit(0);			/* 成功返回 */

} 
