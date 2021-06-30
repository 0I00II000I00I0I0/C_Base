/*
指针和二级指针
*/
#include <iostream>

bool IsLittleEndian()
{
	int n = 0x1;
	char* p = (char*)&n;
	if (*p == 1)
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
	int nNum = 0x000000ff;
	int* p = &nNum;
	int** pp = &p;
	//值
	printf("*p:%d\n", *p);
	printf("**pp:%d\n", **pp);
	printf("nNum:%d\n", nNum);
	//指针
	printf("p:%p\n", p);
	printf("*pp:%p\n", *pp);
	printf("&nNum:%p\n", &nNum);
	//二级指针
	printf("&p:%p\n", &p);
	printf("pp:%p\n", pp);

	char* pSigned = (char*)&nNum;
	unsigned char* pUnsigned = (unsigned char*)&nNum;
	printf("%08x\n", *pSigned);
	printf("%08x\n", *pUnsigned);
	printf("%d\n", *pSigned);
	printf("%d\n", *pUnsigned);
	printf("%u\n", *pSigned);
	printf("%u\n", *pUnsigned);

	char szBuf[] = { 'c',0,0,0,0,0,0,0 };
	char* pBuf = szBuf;
	printf("sizeof pBuf:%d,sizeof *pBuf:%d,sizeof buf:%d\n", sizeof(pBuf), sizeof(*pBuf), sizeof(szBuf));

	int* p1 = (int*)szBuf;
	short* p2 = (short*)szBuf;
	double* p3 = (double*)szBuf;
	printf("pBuf->%c\n", *pBuf);
	printf("pBuf->%s\n", pBuf);
	printf("pBuf->%08x\n", *pBuf);
	printf("p1->%d\n", *p1);
	printf("p2->%d\n", *p2);
	printf("p3->%lf\n", *p3);

	printf("%s\n", IsLittleEndian() ? "低位优先" : "高位优先");

	return 0;
}

