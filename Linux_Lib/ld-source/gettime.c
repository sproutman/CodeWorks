/* gettime.c */

#include	"time.h"
#include	"adatetime.h"

int gettime(TIMETYPE *t)
{
 long		ti;
 struct tm	*tm;
 time(&ti);
 tm=localtime(&ti);
 t->hour=tm->tm_hour;
 t->min=tm->tm_min;
 t->sec=tm->tm_sec;
}

