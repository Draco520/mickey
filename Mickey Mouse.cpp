#include<stdio.h>
#include<windows.h>
#include<iostream>

#define WEIGHT 151 
#define HEIGHT 49 
//�ĳ�ת���ַ���ʱ��ĳ��Ϳ�
#define N WEIGHT*HEIGHT

void show(char* str);
char ch[N];
FILE *fp;
//�뽫txt�ļ��н�ѹ��C�̸�Ŀ¼���Ա�����ȡ�ļ�



int main()
{
	char name[57]="c:\\\\TXT\\ASCII-Mickey Mouse 001.txt";
	//�ĳ����Լ����ļ���
	int i;
	for(i=1;i<999;i++)
	{
		name[27]=i/100+48;
		name[28]=(i%100)/10+48;
		name[29]=i%10+48;
//���ָĳ��ļ����б仯����λ����λ��
		show(name);
		Sleep(1);
		system("cls");
	}
	return 0;
}


void show(char* str)
{
	if((fp=fopen(str,"r"))==NULL)
	{
		printf("null pointer\n");
	}
	else
	{
		while(fgets(ch,N,fp)!=NULL)
		{
			printf("%s",ch);
		}
	}

}
