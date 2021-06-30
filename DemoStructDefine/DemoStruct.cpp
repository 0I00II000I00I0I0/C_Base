/*
1、结构体定义
2、结构体初始化
3、结构体赋值
4、结构体变量
5、结构体指针变量
*/
#include <iostream>
#define NAMELEN 128
#define MAXLEN 512

typedef struct _DATE
{
	int year;
	int month;
	int day;
}DATE, * PDATE;

typedef struct _STUDENT
{
	int nID;
	char chGender;
	char szName[NAMELEN];
	char* szAddress;
	DATE tagBirthday;
	PDATE pTagAdmissionTime;
}STUDENT, * PSTUDENT;

int main()
{
	STUDENT  tagStudent = { 666 };
	tagStudent.chGender = 'M';
	strcpy_s(tagStudent.szName, NAMELEN, "xiaoxin");

	tagStudent.szAddress = (char*)malloc(MAXLEN);
	if (tagStudent.szAddress == NULL)
	{
		free(tagStudent.szAddress);
		return 1;
	}
	memset(tagStudent.szAddress, 0, MAXLEN);
	strcpy_s(tagStudent.szAddress, MAXLEN, "xxx_xxx_xxx");

	DATE tagBirthday = { 2020,1,1 };
	tagStudent.tagBirthday = tagBirthday;

	tagStudent.pTagAdmissionTime = (PDATE)(char*)malloc(sizeof(DATE));
	if (tagStudent.pTagAdmissionTime == NULL)
	{
		free(tagStudent.pTagAdmissionTime);
		return 1;
	}
	memset(tagStudent.pTagAdmissionTime, 0, sizeof(DATE));
	tagStudent.pTagAdmissionTime->year = 2022;
	tagStudent.pTagAdmissionTime->month = 2;
	tagStudent.pTagAdmissionTime->day = 2;

	printf("Student:%p\n", &tagStudent);
	printf("ID:%d\nGender:%c\nName:%s\nAddress:%s\nBirthday:%d年%d月%d日\nAdmissionTime:%d年%d月%d日\n",
		tagStudent.nID, tagStudent.chGender, tagStudent.szName, tagStudent.szAddress,
		tagStudent.tagBirthday.year, tagStudent.tagBirthday.month, tagStudent.tagBirthday.day,
		tagStudent.pTagAdmissionTime->year, tagStudent.pTagAdmissionTime->month, tagStudent.pTagAdmissionTime->day);

	PSTUDENT pTagStudent = (PSTUDENT)malloc(sizeof(STUDENT));
	if (pTagStudent == NULL)
	{
		free(pTagStudent);
		return 1;
	}
	memset(pTagStudent, 0, sizeof(STUDENT));
	memcpy(pTagStudent, &tagStudent, sizeof(STUDENT));

	printf("Student:%p\n", pTagStudent);
	printf("ID:%d\nGender:%c\nName:%s\nAddress:%s\nBirthday:%d年%d月%d日\nAdmissionTime:%d年%d月%d日\n",
		pTagStudent->nID, pTagStudent->chGender, pTagStudent->szName, pTagStudent->szAddress,
		pTagStudent->tagBirthday.year, pTagStudent->tagBirthday.month, pTagStudent->tagBirthday.day,
		pTagStudent->pTagAdmissionTime->year, pTagStudent->pTagAdmissionTime->month, pTagStudent->pTagAdmissionTime->day);

	free(pTagStudent);
	pTagStudent = NULL;
	free(tagStudent.pTagAdmissionTime);
	tagStudent.pTagAdmissionTime = NULL;
	free(tagStudent.szAddress);
	tagStudent.szAddress = NULL;

	return 0;
}

