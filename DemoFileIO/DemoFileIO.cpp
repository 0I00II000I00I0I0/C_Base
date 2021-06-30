/*
文件读写操作
*/
#include "FileIO.h"

int main()
{
	char* szPath = (char*)"Test.txt";
	int nRet = CreateFile(szPath);
	if (nRet == 0)
	{
		printf("file create success\n");
	}
	else
	{
		printf("file create failed\n");
	}

	nRet = OpenFile(szPath);
	if (nRet == 0)
	{
		printf("file open success\n");
	}
	else
	{
		printf("file open failed\n");
	}

	szPath = (char*)"TestDir";
	nRet = CreateDirectory(szPath);
	if (nRet == 0)
	{
		printf("dir create success\n");
	}
	else
	{
		printf("dir create failed\n");
	}

	szPath = (char*)"BinaryIO.txt";
	BinaryIO(szPath);
	szPath = (char*)"FormatIO.txt";
	FormatIO(szPath);
	szPath = (char*)"CharIO.txt";
	CharIO(szPath);
	szPath = (char*)"StringIO.txt";
	StringIO(szPath);

	return 0;
}

