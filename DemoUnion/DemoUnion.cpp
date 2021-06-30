/*
1、共用体中有结构体
2、结构体中有共用体
*/

#include <iostream>

typedef struct _DATE
{
	int year;
	int month;
	int day;
}DATE, * PDATE;

typedef union STUDENT
{
	int nID;
	char szName[16];
	DATE AdmissionTime;
}STUDENT, * PSTUDENT;

typedef struct _INFORMATION
{
	STUDENT unionStu;
	char* szDate;
}INFORMATION, * PINFORMATION;

// 判断系统低位优先
typedef union _POSITION
{
	int n;
	char ch;
}POSITION, * PPOSITION;

bool IsLittleEndian()
{
	POSITION unionPosition;
	unionPosition.n = 1;
	if (unionPosition.ch == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	printf("system is %s\n", IsLittleEndian() ? "little-endian" : "big-endian");

	STUDENT unionStu = { 0 };
	unionStu.nID = 66;
	printf("sizeof union:%d\n", sizeof(unionStu));
	printf("ID:%d,Name:%s,Time:%d-%d-%d\n", unionStu.nID, unionStu.szName,
		unionStu.AdmissionTime.year, unionStu.AdmissionTime.month, unionStu.AdmissionTime.day);

	char szName[16] = "B";
	memcpy(unionStu.szName, szName, 16);
	printf("sizeof union:%d\n", sizeof(unionStu));
	printf("ID:%d,Name:%s,Time:%d-%d-%d\n", unionStu.nID, unionStu.szName,
		unionStu.AdmissionTime.year, unionStu.AdmissionTime.month, unionStu.AdmissionTime.day);

	DATE tagTime = { 66,67,68 };
	unionStu.AdmissionTime = tagTime;
	printf("sizeof union:%d\n", sizeof(unionStu));
	printf("ID:%d,Name:%s,Time:%d-%d-%d\n", unionStu.nID, unionStu.szName,
		unionStu.AdmissionTime.year, unionStu.AdmissionTime.month, unionStu.AdmissionTime.day);

	INFORMATION tagInfo = { 0 };
	tagInfo.unionStu.nID = 66;
	char* szDate = (char*)"test student";
	tagInfo.szDate = szDate;
	printf("sizeof struct:%d\n", sizeof(tagInfo));
	printf("ID:%d,Name:%s,Time:%d-%d-%d\nDate:%s\n", tagInfo.unionStu.nID, tagInfo.unionStu.szName,
		tagInfo.unionStu.AdmissionTime.year, tagInfo.unionStu.AdmissionTime.month, tagInfo.unionStu.AdmissionTime.day,
		tagInfo.szDate);

	return 0;
}
