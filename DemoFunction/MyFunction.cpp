#include "MyFunction.h"

int Add(int x, int y)
{
	int nSum = 0;
	nSum = x + y;
	return nSum;
}

int GetMax(int x, int y)
{
	return x > y ? x : y;
}

void MySwap(int& x, int& y)
{
	int nTemp = x;
	x = y;
	y = nTemp;
}

int GetLength(const char* str)
{
	int nLen = 0;
	while (*str != '\0')
	{
		nLen++;
		str++;
	}
	return nLen;
}

char MyTolower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		ch += 'a' - 'A';
	}
	return ch;
}

void ReverseString(char* str, int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		char cTemp = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = cTemp;
	}
}

void ReverseWord(char* str, int length)
{
	ReverseString(str, length);

	int nWord = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			int nLen = i - nWord;
			ReverseString(&str[nWord], nLen);
			/*for (int j = 0; j < nLen / 2; j++)
			{
				char cTemp = str[nWord + j];
				str[nWord + j] = str[i - 1 - j];
				str[i - 1 - j] = cTemp;
			}*/
			nWord = i + 1;
		}
	}
}

bool IsLeapYear(int year)
{
	return (year % 4 == 0) && (year % 100 || year % 400 == 0);
}
