/*
文件操作结构体数据
*/
#include <iostream>
#include "StructIO.h"

int main()
{
	char* szPath = (char*)"configure.txt";
	FILE* file = NULL;
	errno_t err = fopen_s(&file, szPath, "w");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	fputs("ip=192.168.0.99\n", file);
	fputs("port=6666\n", file);
	fclose(file);

	CONFIGURE tagConfigure = { 0 };
	int nRet = GetConfigure(&tagConfigure, szPath);
	printf("ip=%sport=%s", tagConfigure.ip, tagConfigure.port);

	char* szFile = (char*)"student.bat";
	err = fopen_s(&file, szFile, "w");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	VarWriteInfo(file);
	fclose(file);

	err = fopen_s(&file, szFile, "r");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	VarReadInfo(file);
	rewind(file);
	VarQueryInfo(file);
	fclose(file);

	return 0;
}

