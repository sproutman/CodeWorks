#include <stdio.h>

typedef  void( *FunType)(int);  // 定义函数指针类型



void myFun1( int x )
{
	printf(" I am myFun1  %d !!!\n", x);
}

void myFun2( int x )
{
	printf(" I am myFun2 %d !!!\n", x);
}



void callMyfun(FunType fp,int x)
{
	fp(x);
}


int main()
{
	const FunType   f1 = myFun1;  //  const FunType 即定义函数指针常量 此指针不可再指向其它的函数
	callMyfun( f1, 8 );

	// 如何这时候 更改函数指针常量  就有问题了
	f1 = myFun2;
	callMyfun( f1, 9 );

	return 0;
}
