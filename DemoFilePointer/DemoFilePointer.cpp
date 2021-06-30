/*
文件指针操作
*/
#include <iostream>

int SeekIO(char* path)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, path, "w");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	fwrite("hello world!", strlen("hello world!") + 1, 1, file);
	fclose(file);

	err = fopen_s(&file, path, "r");
	if (err != 0 || file == NULL)
	{
		return 1;
	}

	char buf[128] = { 0 };
	fseek(file, 6, SEEK_SET);
	fread(buf, 128, 1, file);
	printf("buf:%s\n", buf);

	fseek(file, -3, SEEK_CUR);
	fread(buf, 128, 1, file);
	printf("buf:%s\n", buf);

	rewind(file);
	fread(buf, 128, 1, file);
	printf("buf:%s\n", buf);
	fclose(file);

	return 0;
}

long GetFileSize(char* path)
{
	if (path == NULL)
	{
		return 0;
	}
	FILE* file = NULL;
	errno_t err = fopen_s(&file, path, "r");
	if (err != 0 || file == NULL)
	{
		return 0;
	}
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fclose(file);

	return size;
}

int Rename(char* desPath, char* sourPath)
{
	int res = rename(desPath, sourPath);
	return res;
}

int Remove(char* path)
{
	int res = remove(path);
	return res;
}

int main()
{
	char* szPath = (char*)"SeekIO.txt";
	int nRet = SeekIO(szPath);
	if (nRet == 0)
	{
		printf("file seek success\n");
	}
	else
	{
		printf("file seek failed\n");
	}
	long size = GetFileSize(szPath);
	printf("size:%d\n", size);

	char* szRename = (char*)"Rename.txt";
	nRet = Rename(szPath, szRename);
	if (nRet == 0)
	{
		printf("file rename success\n");
	}
	else
	{
		printf("file rename failed\n");
	}
	nRet = Remove(szPath);
	//nRet = Remove(szRename);
	if (nRet == 0)
	{
		printf("file remove success\n");
	}
	else
	{
		printf("file remove failed\n");
	}

	return 0;
}

