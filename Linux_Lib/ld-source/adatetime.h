/* adatetime.h :  2002-03-06. */

#ifndef __DATETIME_H

#define __DATETIME_H

/* ���ڽṹ */
typedef struct
{
 int    year;
 int    mon;
 int    day;
}DATETYPE;

/* ʱ��ṹ */
typedef struct
{
 char   hour;
 char   min;
 char   sec;
}TIMETYPE;

int     getdate(DATETYPE *d); /* ȡ��ǰ���� */
int     gettime(TIMETYPE *t); /* ȡ��ǰʱ�� */

#endif

