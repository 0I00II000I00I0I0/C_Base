/*
1、输入学生个数，输入学生成绩，求平均成绩。
2、用指针的方式使用数组。
*/
#include <iostream>

int main()
{
	int nSum = 0;
	int nTotal = 0;
	//输入学生个数
	printf("please input the student num:\n");
	scanf_s("%d", &nSum);
	if (nSum <= 0)
	{
		printf("input invalid\n");
		return 1;
	}
	//输入学生成绩
	int* pSum = (int*)malloc(nSum * sizeof(int));
	if (pSum == NULL)
	{
		printf("memory is null\n");
		return 1;
	}
	memset(pSum, 0, nSum * sizeof(int));
	for (int i = 0; i < nSum; i++)
	{
		printf("please input the score for student %d:\n", i + 1);
		scanf_s("%d", pSum + i);
	}
	//平均成绩
	for (int i = 0; i < nSum; i++)
	{
		nTotal += *(pSum + i);

	}
	printf("average score:%.2f\n", (double)nTotal / nSum);

	free(pSum);
	pSum = NULL;
	return 0;
}

