/*
1、函数参数传值
2、函数参数传指针
3、函数参数传引用
4、函数参数传数组
5、函数参数传二级指针
*/
#include <iostream>

void SwapA(int x, int y)
{
	int nTemp = x;
	x = y;
	y = nTemp;
}

void SwapB(int* x, int* y)
{
	int nTemp = *x;
	*x = *y;
	*y = nTemp;
}

void SwapC(int& x, int& y)
{
	int nTemp = x;
	x = y;
	y = nTemp;
}

int FuncA(char a[])
{
	int nSize = sizeof(a);
	return nSize;
}

int FuncB(char& a)
{
	int nSize = sizeof(a);
	return nSize;
}

int FuncC(char(&a)[11])
{
	int nSize = sizeof(a);
	return nSize;
}

int main()
{
	int nNumA = 1;
	int nNumB = 2;
	printf("a=%d,b=%d\n", nNumA, nNumB);
	SwapA(nNumA, nNumB);
	printf("a=%d,b=%d\n", nNumA, nNumB);
	SwapB(&nNumA, &nNumB);
	printf("a=%d,b=%d\n", nNumA, nNumB);
	SwapC(nNumA, nNumB);
	printf("a=%d,b=%d\n", nNumA, nNumB);

	char szBuf[] = "test param";
	printf("sizeof=%d\n", FuncA(szBuf));
	printf("sizeof=%d\n", FuncB(*szBuf));
	printf("sizeof=%d\n", FuncC(szBuf));

	return 0;
}
