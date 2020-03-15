#include<stdio.h>
#include<windows.h>
#include<iostream>

#define WEIGHT 151 
#define HEIGHT 49 
//改成转换字符好时候的长和宽
#define N WEIGHT*HEIGHT

void show(char* str);
char ch[N];
FILE *fp;
//请将txt文件夹解压到C盘根目录，以便程序读取文件



int main()
{
	char name[57]="c:\\\\TXT\\ASCII-Mickey Mouse 001.txt";
	//改成你自己的文件名
	int i;
	for(i=1;i<999;i++)
	{
		name[27]=i/100+48;
		name[28]=(i%100)/10+48;
		name[29]=i%10+48;
//数字改成文件名中变化的三位数的位置
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
