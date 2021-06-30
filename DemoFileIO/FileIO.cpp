#include "FileIO.h"
#include<direct.h>

int CreateFile(char* szPath)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, szPath, "w");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	fclose(file);
	return 0;
}

int OpenFile(char* szPath)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, szPath, "r");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	fclose(file);
	return 0;
}

int CreateDirectory(char* szPath)
{
	int res = _mkdir(szPath);
	return res;
}

int BinaryIO(char* szPath)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, szPath, "w");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	fwrite("hello world!", strlen("hello world!") + 1, 1, file);
	int nNumber = 100;
	fwrite(&nNumber, sizeof(nNumber), 1, file);
	fclose(file);

	err = fopen_s(&file, szPath, "r");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	int nValue = 0;
	char szBuf[128] = { 0 };
	fread(szBuf, strlen("hello world!") + 1, 1, file);
	fread(&nValue, sizeof(nValue), 1, file);
	printf("buf:%s,value:%d\n", szBuf, nValue);
 	fclose(file);

	return 0;
}

int FormatIO(char* szPath)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, szPath, "w");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	int nNumber = 100;
	fprintf(file, "%s %d", "hello-world!", nNumber);
	fclose(file);

	err = fopen_s(&file, szPath, "r");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	int nValue = 0;
	char szBuf[128] = { 0 };
	fscanf_s(file, "%s%d", szBuf, sizeof(szBuf), &nValue);
	printf("buf:%s,value:%d\n", szBuf, nValue);
	fclose(file);

	return 0;
}

int CharIO(char* szPath)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, szPath, "w");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	const char* szHello = "hello world!";
	while (*szHello != '\0')
	{
		fputc(*szHello, file);
		szHello++;
	}
	fputc('\0', file);
	fclose(file);

	err = fopen_s(&file, szPath, "r");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	while (!feof(file))
	{
		char ch = fgetc(file);
		printf("%c", ch);
	}
	printf("\n");
	fclose(file);

	return 0;
}

int StringIO(char* szPath)
{
	FILE* file = NULL;
	errno_t err = fopen_s(&file, szPath, "w");
	if (err != 0 || file == NULL)
	{
		return 1;
	}
	const char* strDate[3] =
	{
		"hello\n",
		"world!\n",
		"hello world!\n"
	};
	for (int i = 0; i < 3; i++)
	{
		fputs(strDate[i], file);
	}
	fclose(file);

	err = fopen_s(&file, szPath, "r");
	if (err != 0 || file == NULL)
	{
		return -1;
	}
	while (!feof(file))
	{
		char szBuf[128] = { 0 };
		char* p = fgets(szBuf, 128, file);
		if (p == NULL)
		{
			break;
		}
		printf("buf:%s", szBuf);
	};
	fclose(file);

	return 0;
}


