/*
字符串操作
*/
#include <iostream>
#include <tchar.h>

int main()
{
	const char* szStrA = "hello world 1";
	const wchar_t* szStrB = L"hello world 2";
	const TCHAR* szStrC = _T("hello world 3");

	// 打印
	size_t nLenA = strlen(szStrA);
	size_t nLenB = wcslen(szStrB);
	size_t nLenC = _tcslen(szStrC);
	printf("str:%s,size:%d\n", szStrA, nLenA);
	printf("str:%ws,size:%d\n", szStrB, nLenB);
	_tprintf(_T("str:%s,size:%d\n"), szStrC, nLenC);

	// 拷贝，strncpy_s(),wcsncpy_s(),_tcsncpy_s()需要判断最小长度，sizeof(buf) > len ? len : sizeof(buf) - 1;
	char szBufA[128] = { 0 };
	wchar_t szBufB[128] = { 0 };
	TCHAR szBufC[128] = { 0 };
	strcpy_s(szBufA, 128, szStrA);
	wcscpy_s(szBufB, 128, szStrB);
	_tcscpy_s(szBufC, 128, szStrC);
	printf("buf:%s\n", szBufA);
	printf("buf:%ws\n", szBufB);
	_tprintf(_T("buf:%s\n"), szBufC);

	const char* szStrTest = "Hello World 1";
	// 比较
	if (strcmp(szStrTest, szStrA) == 0)
	{
		printf("%s == %s\n", szStrTest, szStrA);
	}
	else
	{
		printf("%s != %s\n", szStrTest, szStrA);
	}

	// 忽略大小写
	if (_stricmp(szStrTest, szStrA) == 0)
	{
		printf("%s == %s\n", szStrTest, szStrA);
	}
	else
	{
		printf("%s != %s\n", szStrTest, szStrA);
	}

	// 比较前n个字符
	if (strncmp(szStrTest, szStrA, 6) == 0)
	{
		printf("%s == %s\n", szStrTest, szStrA);
	}
	else
	{
		printf("%s != %s\n", szStrTest, szStrA);
	}

	// 比较前n个字符忽略大小写
	if (_strnicmp(szStrTest, szStrA, 6) == 0)
	{
		printf("%s == %s\n", szStrTest, szStrA);
	}
	else
	{
		printf("%s != %s\n", szStrTest, szStrA);
	}

	// 拼接字符串
	char path[100] = "c:\\xxx\\string\\";
	char* filename = (char*)"DemoString.exe";
	strcat_s(path, 100, filename);
	printf("path:%s\n", path);

	// 字符串中查找字符位置
	char* szBuf = strchr(path, '\\');
	if (szBuf == NULL)
	{
		printf("NO FIND\n");
	}
	else
	{
		printf("FIND:%s,%d\n", szBuf, szBuf - path);
	}

	// 从右向左查找
	szBuf = strrchr(path, '.');
	if (szBuf == NULL)
	{
		printf("NO FIND\n");
	}
	else
	{
		printf("FIND:%s,%d\n", szBuf, szBuf - path);
	}

	// 字符串中查找字符串
	szBuf = strstr(path, ".exe");
	if (szBuf == NULL)
	{
		printf("NO FIND\n");
	}
	else
	{
		printf("FIND:%s,%d\n", szBuf, szBuf - path);
	}

	// 拆分字符串
	printf("%s\n", path);
	char* next = NULL;
	char* delim = (char*)"\\";
	szBuf = strtok_s(path, delim, &next);
	while (szBuf != NULL)
	{
		printf("%s\n", szBuf);
		szBuf = strtok_s(NULL, delim, &next);
	}

	// 字符串，整数，浮点数转换
	const char* szNum = "3.14";
	const char* szNumA = "99";
	const wchar_t* szNumB = L"99";
	double dbNum = atof(szNum);
	int nNumA = atoi(szNumA);
	int nNumB = _ttol(szNumB);
	printf("dbNum:%lf\nnNumA:%d\nnNumB:%d\n", dbNum, nNumA, nNumB);

	return 0;
}

