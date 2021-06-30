/*
递归算法
*/
#include <iostream>

// 递归求阶乘
int Factorial(unsigned int num)
{
	if (num == 0 || num == 1)
	{
		return 1;
	}
	return num * Factorial(num - 1);
}

// 递归求斐波那契数列
int Fibonacci(unsigned int num)
{
	if (num == 1 || num == 2)
	{
		return 1;
	}
	return Fibonacci(num - 1) + Fibonacci(num - 2);
}

// 计算字符串长度
int GetStrLen(const char* str)
{
	/*if (str == NULL || *str == '\0')
	{
		return 0;
	}
	return mystrlen(str + 1) + 1;*/

	return (str == NULL || *str == '\0') ? 0 : GetStrLen(str + 1) + 1;
}

// 反向输出字符串
void ReversePrintf(char* string)
{
	if (string == NULL || *string == '\0')
	{
		return;
	}
	ReversePrintf(string + 1);
	printf("%c", *string);
}

// 逆置字符串
void ReverseString(char* str, int length)
{
	if (str == NULL || length == 0 || length == 1)
	{
		return;
	}
	ReverseString(str + 1, length - 2);
	char szTemp = *str;
	*str = *(str + length - 1);
	*(str + length - 1) = szTemp;
	return;
}

int main()
{
	int nNum = 6;
	printf("%d!=%d\n", nNum, Factorial(nNum));
	printf("feibo(%d)=%d\n", nNum, Fibonacci(nNum));

	char* szBuf = (char*)"hello world";
	int nLength = GetStrLen(szBuf);
	printf("buf:%s\nlength:%d\n", szBuf, nLength);
	ReversePrintf(szBuf);
	printf("\n");

	char szReverse[] = "ReverseString Test";
	printf("%s\n", szReverse);
	ReverseString(szReverse, GetStrLen(szReverse));
	printf("%s\n", szReverse);

	return 0;
}
