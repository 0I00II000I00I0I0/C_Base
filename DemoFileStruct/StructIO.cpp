#pragma once
#include "StructIO.h"
#include <iostream>

int GetConfigure(PCONFIGURE pTagConfigure, char* path)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, path, "r");
	if (err != 0 || file == NULL)
	{
		return 1;
	}

	while (!feof(file))
	{
		char* pConfigure = NULL;
		char szBuf[128] = { 0 };
		fgets(szBuf, 128, file);

		if (strstr(szBuf, "ip=") != NULL)
		{
			pConfigure = strstr(szBuf, "ip=") + 3;
			strcpy_s(pTagConfigure->ip, 128, pConfigure);
		}

		if (strstr(szBuf, "port=") != NULL)
		{
			pConfigure = strstr(szBuf, "port=") + 5;
			strcpy_s(pTagConfigure->port, 128, pConfigure);
		}
	}
	fclose(file);

	return 0;
}

void WriteInfo(FILE* file)
{
	STUDENT tagStudent = { 0 };
	while (1)
	{
		printf("please input id:");
		scanf_s("%d", &tagStudent.id);
		if (tagStudent.id == 0)
		{
			break;
		}
		printf("please input name:");
		scanf_s("%s", tagStudent.name, MAXLEN);
		fwrite(&tagStudent, sizeof(tagStudent), 1, file);
	}
}

void ReadInfo(FILE* file)
{
	STUDENT tagStudent = { 0 };
	while (!feof(file))
	{
		int nReadSize = fread(&tagStudent, sizeof(tagStudent), 1, file);
		if (nReadSize == 0)
		{
			break;
		}
		printf("id:%d,name:%s\n", tagStudent.id, tagStudent.name);
	}
}

void VarWriteInfo(FILE* file)
{
	STUDENT tagStudent = { 0 };
	while (1)
	{
		printf("please input id:");
		scanf_s("%d", &tagStudent.id);
		if (tagStudent.id == 0)
		{
			break;
		}
		printf("please input name:");
		scanf_s("%s", tagStudent.name, MAXLEN);
		int nLength = strlen(tagStudent.name);
		fwrite(&tagStudent.id, sizeof(tagStudent.id), 1, file);
		fwrite(&nLength, sizeof(nLength), 1, file);
		fwrite(tagStudent.name, nLength, 1, file);
	}
}

void VarReadInfo(FILE* file)
{
	while (!feof(file))
	{
		STUDENT tagStudent = { 0 };
		int nLength = 0;
		int nReadSize = fread(&tagStudent.id, sizeof(tagStudent.id), 1, file);
		if (nReadSize == 0)
		{
			break;
		}
		fread(&nLength, sizeof(nLength), 1, file);
		fread(tagStudent.name, nLength, 1, file);
		printf("id:%d,name:%s\n", tagStudent.id, tagStudent.name);
	}
}

void VarQueryInfo(FILE* file)
{
	int id = 0;
	bool bRet = false;
	printf("please input query id:");
	scanf_s("%d", &id);

	while (!feof(file))
	{
		STUDENT stu = { 0 };
		int length = 0;

		int count = fread(&stu.id, sizeof(stu.id), 1, file);
		if (count == 0)
		{
			break;
		}
		fread(&length, sizeof(length), 1, file);
		fread(stu.name, length, 1, file);

		if (stu.id == id)
		{
			printf("find id:%d,name:%s\n", stu.id, stu.name);
			bRet = true;
			break;
		}
	}

	if (bRet == false)
	{
		printf("id not find\n");
	}
}

