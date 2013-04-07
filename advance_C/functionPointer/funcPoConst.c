#include <stdio.h>

typedef  void( *FunType)(int);  // ���庯��ָ������



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
	const FunType   f1 = myFun1;  //  const FunType �����庯��ָ�볣�� ��ָ�벻����ָ�������ĺ���
	callMyfun( f1, 8 );

	// �����ʱ�� ���ĺ���ָ�볣��  ����������
	f1 = myFun2;
	callMyfun( f1, 9 );

	return 0;
}
