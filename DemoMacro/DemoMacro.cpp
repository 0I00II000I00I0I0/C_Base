/*
1、预处理命令
2、宏定义
3、关于字符串的宏定义
*/
#include <iostream>
//调试状态
#define DEBUG 1
//PI值
#define PI 3.14f
//字符串，给a加双引号
#define STR(a) #a
//连接AB
#define COMBINE(A,B) A##B
//求最大值
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
//交换值
#define EXCHANGE(X,Y) {X^=Y;Y^=X;X^=Y;}
//求最大值
#define GETMAX(a,b) ((a)+(b)+abs((a)-(b)))/2
//求数组大小
#define ARRAYSIZE(a) sizeof(a)/sizeof(a[0])
//求结构体成员偏移
#define OFFSETOF(s,m) (size_t)(&(((s*)0)->m))

typedef struct _TESTSTRUCT
{
	int i;
	char c;
}TESTSTRUCT, * pTESTSTRUCT;

double  GetCircleArea(double dbRadius)
{
	return PI * dbRadius * dbRadius;
}

int main()
{
#if defined DEBUG
	printf("%s\n", STR(123));
	printf("%d\n", COMBINE(3, 6));
	printf("%s\n", COMBINE("debug", "true"));
#else
	printf("%s\n", COMBINE("debug", "false"));
#endif

	int a = 3;
	int b = 6;
	printf("a=%d,b=%d\n", a, b);
	EXCHANGE(a, b);
	printf("a=%d,b=%d\n", a, b);
	printf("Max=%d\n", MAX(a, b));
	printf("Max=%d\n", GETMAX(a, b));
	printf("Area:%.2f\n", GetCircleArea(6.6f));

	char szBuf[] = "test macro";
	printf("sizeof=%d\n", ARRAYSIZE(szBuf));
	printf("i:%d,ch:%d\n", OFFSETOF(TESTSTRUCT, i), OFFSETOF(TESTSTRUCT, c));

	return 0;
}
