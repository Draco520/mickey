
#include<stdio.h>
#include<windows.h>
#include<iostream>
#include<time.h>

#define ENER 23
#define EMOT 28
#define INTE 33

void show(long bir);
void result(int re,int cycle);
int leap(int b,int n);
int isleap(int year);


int main()
{
	printf("*****欢迎来到人体节律计算系统*****\n");
	printf("*        输入您的生日            *\n");
	printf("*        例如19870311            *\n");
	printf("**********************************\n");
	long birth;
	scanf("%d",&birth);
	printf("\n\n");
	show(birth);
	printf("您可以根据计算结果，合理安排工作学习计划\n");
	printf("感谢您的使用，祝您身体健康万事如意\n");
	system("pause");
	return 0;
}

void show(long bir)
{
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(isleap(bir/10000))
		month[1]=29;
	int i,day=0;;
	int bdays=bir%10000/100;
	for(i=0;i<bdays-1;i++)
	{
		day+=month[i];
	}
	day+=bir%100;
	time_t timep;
    struct tm *p;
    time(&timep);
    p=gmtime(&timep);
	int current_year=1900+p->tm_year;
	int leaps=leap(bir/10000,current_year);
	printf("闰年数\t%d 现在到1,1\t%d 生日到1,1\t%d\n",leaps,(p->tm_yday+1),day);
	int sum=(current_year-bir/10000)*365+leaps-day+(p->tm_yday);
	int ener=sum%ENER;		//体力
	int emot=sum%EMOT;		//情绪
	int inte=sum%INTE;		//智力
	printf("体力情况：");
	result(ener,ENER);
	printf("情绪情况：");
	result(emot,EMOT);
	printf("智力情况：");
	result(inte,INTE);
	printf("\n\n");
	printf("结果说明:\n");
	printf("周期日:\t周期日是每个周期的开始日,为期一天.周期日时,人体正处在转换之中,新思想,新行动易在此时产生,虽思维活跃,但辨别力差,身心起伏不定,盲目易动\n");
	printf("高潮期:\t高潮期是能量释放阶段,");
	printf("临界日:\t临界日是高潮期与低潮期相互过渡的交替日子.临界日时,人体由高潮期向低潮期转换,此时身体各部机能处于调节之中\n");
	printf("低潮期:\t低潮期是能量蓄积补充阶段\n");
	printf("\n\n");
}

int leap(int b,int n)
{
	int count=0;
	for(b;b<n;b++)
	{
		if(isleap(b))
		{
			count++;
		}
	}
	return count;
}

int isleap(int year)
{
	if(!(year%4)&&(year%100)||!(year%400))
	{
	
		return 1;
	}
	else
		return 0;
}

void result(int re,int cycle)
{

	if(re==0)
		printf("周期日\n");
	else if(re==(cycle+1)/2)
		printf("临界日\n");
	else if(re<(cycle+1)/2)
		printf("高潮期\n");
	else if(re>(cycle+1)/2)
		printf("低潮期\n");
	else 
		printf("结果有误\n");
}
