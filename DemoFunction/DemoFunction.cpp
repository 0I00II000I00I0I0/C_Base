#include <iostream>
#include "MyFunction.h"

int main()
{
	int nNumA = 3;
	int nNumB = 6;

	printf("nNumA=%d,nNumB=%d\n", nNumA, nNumB);
	printf("AndNum=%d\n", Add(nNumA, nNumB));
	printf("MaxNum=%d\n", GetMax(nNumA, nNumB));
	MySwap(nNumA, nNumB);
	printf("nNumA=%d,nNumB=%d\n", nNumA, nNumB);

	char* string = (char*)"Hello World 123!";
	while (*string != '\0')
	{
		printf("%c", MyTolower(*string));
		string++;
	}
	printf("\n");

	char szTestA[] = "Hello World 123!";
	char szTestB[] = "Hello World 123!";
	int nLen = GetLength(szTestA);

	ReverseString(szTestA, nLen);
	printf("%s\n", szTestA);
	ReverseWord(szTestB, nLen);
	printf("%s\n", szTestB);

	int year = 2100;
	printf("%d %s a leap year\n", year, IsLeapYear(year) ? "is" : "is not");

	return 0;
}

