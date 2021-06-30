/*
1、枚举类型
2、兑奖
*/
#include <iostream>

typedef enum _AWARD
{
	noAward = 0,
	firstAward,
	secondAward,
	thirdAward,
	specialAward = 6
}AWARD, * PAWARD;

int main()
{
	AWARD enumAward = (AWARD)6;
	printf("sizeof AWARD:%d,sizeof enumAward:%d,sizeof noAward:%d\n", sizeof(AWARD), sizeof(enumAward), sizeof(noAward));

	switch (enumAward)
	{
	case 0:
		printf("谢谢惠顾\n");
		break;
	case 1:
		printf("一等奖\n");
		break;
	case 2:
		printf("二等奖\n");
		break;
	case 3:
		printf("三等奖\n");
		break;
	case 6:
		printf("特等奖\n");
		break;
	default:
		printf("兑奖号码不正确\n");
		break;
	}

	return 0;
}

