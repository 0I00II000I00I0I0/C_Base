// struse_demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
void printstr(const char* str);
void reversestr(const char* str);

char str1[] = "hello world 1";// 静态区.data

int main()
{
	const char* str2 = "hello world 2";// 静态常量区.rdata
	char str3[] = "hello world 3";// 静态常量区拷贝到栈上

	char* str4 = (char*)malloc(128);
	if (str4 == NULL)
	{
		return 0;
	}
	memset(str4, 0, 128);
	strcpy_s(str4, 128, "hello world 4");// 堆上

	printf("%s\n%s\n%s\n%s\n", str1, str2, str3, str4);
	printf("\n");

	str1[0] = 'H';
	str3[0] = 'H';
	str4[0] = 'H';
	printf("%s\n%s\n%s\n%s\n", str1, str2, str3, str4);
	printf("\n");

	free(str4);

	while (*str2 != '\0')
	{
		printf("%c", *str2);
		str2++;
	}
	printf("\n");

	str2 = "hello world 2";
	for (; *str2 != '\0'; str2++)
	{
		printf("%c", *str2);
	}
	printf("\n");

	str2 = "hello world 2";
	for (int i = 0; str2[i] != '\0'; i++)
	{
		printf("%c", str2[i]);
	}
	printf("\n");

	printstr(str2);// 自定义函数
	printstr("你好");

	reversestr(str2);

	return 0;
}

void printstr(const char* str)
{
	if (str == NULL)
	{
		return;
	}
	while (*str != '\0')
	{
		printf("%c", *str);
		str++;
	}
	printf("\n");
}

void reversestr(const char* str)
{
	if (str == NULL)
	{
		return;
	}

	int index = 0;
	while (*str != '\0')
	{
		str++;
		index++;
	}

	str--;
	while (index)
	{
		printf("%c", *str);
		str--;
		index--;
	}
	printf("\n");


}
