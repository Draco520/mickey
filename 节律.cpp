
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
	printf("*****��ӭ����������ɼ���ϵͳ*****\n");
	printf("*        ������������            *\n");
	printf("*        ����19870311            *\n");
	printf("**********************************\n");
	long birth;
	scanf("%d",&birth);
	printf("\n\n");
	show(birth);
	printf("�����Ը��ݼ������������Ź���ѧϰ�ƻ�\n");
	printf("��л����ʹ�ã�ף�����彡����������\n");
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
	printf("������\t%d ���ڵ�1,1\t%d ���յ�1,1\t%d\n",leaps,(p->tm_yday+1),day);
	int sum=(current_year-bir/10000)*365+leaps-day+(p->tm_yday);
	int ener=sum%ENER;		//����
	int emot=sum%EMOT;		//����
	int inte=sum%INTE;		//����
	printf("���������");
	result(ener,ENER);
	printf("���������");
	result(emot,EMOT);
	printf("���������");
	result(inte,INTE);
	printf("\n\n");
	printf("���˵��:\n");
	printf("������:\t��������ÿ�����ڵĿ�ʼ��,Ϊ��һ��.������ʱ,����������ת��֮��,��˼��,���ж����ڴ�ʱ����,��˼ά��Ծ,���������,�����������,äĿ�׶�\n");
	printf("�߳���:\t�߳����������ͷŽ׶�,");
	printf("�ٽ���:\t�ٽ����Ǹ߳�����ͳ����໥���ɵĽ�������.�ٽ���ʱ,�����ɸ߳�����ͳ���ת��,��ʱ����������ܴ��ڵ���֮��\n");
	printf("�ͳ���:\t�ͳ����������������׶�\n");
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
		printf("������\n");
	else if(re==(cycle+1)/2)
		printf("�ٽ���\n");
	else if(re<(cycle+1)/2)
		printf("�߳���\n");
	else if(re>(cycle+1)/2)
		printf("�ͳ���\n");
	else 
		printf("�������\n");
}
