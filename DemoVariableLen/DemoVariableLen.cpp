/*
使用结构体实现变长的字符串管理
*/
#include <iostream>

typedef struct _STUDENTA
{
	int nID;
	char szName[16];
}STUDENTA, * PSTUDENTA;

typedef struct _STUDENTB
{
	int nID;
	char* szName;
}STUDENTB, * PSTUDENTB;

typedef struct _STUDENTC
{
	int nID;
	int nLength;
	char szName[0];
}STUDENTC, * PSTUDENTC;

int main()
{
	char* szName = (char*)"xiaoxin";
	int nLen = strlen(szName) + 1;

	STUDENTA tagStuA = { 666,"xiaoxin" };
	printf("sizeof tagStuA:%d,ID:%d,Name:%s\n", sizeof(tagStuA), tagStuA.nID, tagStuA.szName);

	STUDENTB tagStuB = { 0 };
	tagStuB.nID = 777;
	tagStuB.szName = (char*)malloc(nLen);
	if (tagStuB.szName == NULL)
	{
		free(tagStuB.szName);
		return 1;
	}
	strcpy_s(tagStuB.szName, nLen, szName);
	printf("sizeof tagStuB:%d,ID:%d,Name:%s\n", sizeof(tagStuB), tagStuB.nID, tagStuB.szName);

	STUDENTC tagStuC = { 0 };
	tagStuC.nID = 888;
	tagStuC.nLength = nLen;
	strcpy_s(tagStuC.szName, nLen, szName);
	printf("sizeof tagStuC:%d,ID:%d,Name:%s\n", sizeof(tagStuC), tagStuC.nID, tagStuC.szName);

	int nSize = sizeof(STUDENTC) + tagStuC.nLength;
	char* szInfo = (char*)malloc(nSize);
	memcpy(szInfo, &tagStuC, nSize);
	PSTUDENTC tagStu = (PSTUDENTC)szInfo;
	printf("sizeof tagStu:%d,ID:%d,Name:%s\n", sizeof(tagStu), tagStu->nID, tagStu->szName);

	free(tagStuB.szName);
	return 0;
}

