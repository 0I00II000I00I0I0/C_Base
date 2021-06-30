#pragma once
#include <iostream>
#define MAXLEN 128

typedef struct _CONFIGURE
{
	char ip[MAXLEN];
	char port[MAXLEN];
}CONFIGURE, * PCONFIGURE;

typedef struct _STUDENT
{
	int id;
	char name[MAXLEN];
}STUDENT, * PSTUDENT;

int GetConfigure(PCONFIGURE pTagConfigure, char* path);

void WriteInfo(FILE* file);
void ReadInfo(FILE* file);

void VarWriteInfo(FILE* file);
void VarReadInfo(FILE* file);
void VarQueryInfo(FILE* file);