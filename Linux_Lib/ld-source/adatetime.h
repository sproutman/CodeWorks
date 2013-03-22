/* adatetime.h :  2002-03-06. */

#ifndef __DATETIME_H

#define __DATETIME_H

/* 日期结构 */
typedef struct
{
 int    year;
 int    mon;
 int    day;
}DATETYPE;

/* 时间结构 */
typedef struct
{
 char   hour;
 char   min;
 char   sec;
}TIMETYPE;

int     getdate(DATETYPE *d); /* 取当前日期 */
int     gettime(TIMETYPE *t); /* 取当前时间 */

#endif

