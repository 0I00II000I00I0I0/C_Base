/*
函数指针用法
*/
#include <iostream>

int Add(int x, int y)
{
	return x + y;
}

typedef int(*pFunctionAdd)(int x, int y);

int main()
{
	int nNumA = 3;
	int nNumB = 6;
	int nRet = 0;

	printf("name = %p,addr = %p\n", Add, &Add);
	pFunctionAdd pFuncA = Add;
	nRet = pFuncA(nNumA, nNumB);
	printf("nRet=%d\n", nRet);

	pFunctionAdd pFuncB = &Add;
	nRet = pFuncB(nNumA, nNumB);
	printf("nRet=%d\n", nRet);

	int(*pFuncC)(int x, int y) = Add;
	nRet = pFuncC(nNumA, nNumB);
	printf("nRet=%d\n", nRet);

	return 0;
}