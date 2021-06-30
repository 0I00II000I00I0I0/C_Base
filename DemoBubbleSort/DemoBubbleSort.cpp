/*
1、使用数组实现冒泡排序算法
2、求第二大值和第二小值
*/
#include <iostream>

void PrintfArray(int* nArray, int nLength)
{
	for (int i = 0; i < nLength; i++)
	{
		printf("%d ", *(nArray + i));
	}
	printf("\n");
}

int main()
{
	int aryTest[] = { 66,5,23,99,6,18 };
	int nLength = sizeof(aryTest) / sizeof(aryTest[0]);
	printf("原数组：");
	PrintfArray(aryTest, nLength);

	int nMax = 0;
	int nMin = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = nLength - 1; j > i; j--)
		{
			if (aryTest[j] > aryTest[j - 1])
			{
				nMax = aryTest[j];
				aryTest[j] = aryTest[j - 1];
				aryTest[j - 1] = nMax;
			}
		}
	}
	printf("the second max:%d\n", aryTest[1]);

	for (int i = 0; i < 2; i++)
	{
		for (int j = nLength - 1; j > i; j--)
		{
			if (aryTest[j] < aryTest[j - 1])
			{
				nMin = aryTest[j];
				aryTest[j] = aryTest[j - 1];
				aryTest[j - 1] = nMin;
			}
		}
	}
	printf("the second min:%d\n", aryTest[1]);


	int nTemp = 0;
	for (int i = 0; i < nLength - 1; i++)
	{
		for (int j = nLength - 1; j > i; j--)
		{
			if (aryTest[j] < aryTest[j - 1])
			{
				nTemp = aryTest[j];
				aryTest[j] = aryTest[j - 1];
				aryTest[j - 1] = nTemp;
			}
		}
		printf("第%d次冒泡排序：\n", i + 1);
		PrintfArray(aryTest, nLength);
	}

	return 0;
}
