/*
 * a simple c function pointer code
 * functionP.c
 * @date 2013-03-28
 */

#include <stdio.h>
#include <stdlib.h>

typedef void(*FunType)(int);    // define Funtype 函数指针类型

void callMyFun( FunType fp,int x )
{
	fp(x);
}



void MYFun1(int x)
{
	printf(" hanshu myFun1  %d \n", x);
}

void MYFun2(int x)
{
	printf(" hanshu myFun2  %d \n", x);
}
void MYFun3(int x)
{
	printf(" hanshu myFun3  %d \n", x);
}


int main()
{
	callMyFun(MYFun3,30);
	return 0;
}
