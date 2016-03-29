// weiy.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string.h>
int n_char(FILE *fp)
{
	int num = 0;
	char s[2000];
	while(!feof(fp))
	{
		 fscanf(fp, "%s", s); //读取字符串
		 num += strlen(s); //叠加字符数
	}
	printf("字符数（不计空格和回车）有%d个\n",num);
	rewind(fp); //绕回文件指针
	return num;
}
int n_world(FILE *fp)
{
	char s[2000];
	int n = 0, num = 0;
	while(!feof(fp))
	{
	 if(fscanf(fp, "%s", s) && !(s[0] >='0' && s[0] <='9'))
	  n++;
	 else
	  num++;
	}
	printf("单词数有%d个，数字有%d个\n",n,num);
	rewind(fp);
	return n;
}
int n_row(FILE *fp)
{
	int n = 1;
	char ch;
	while(!feof(fp))
	{
	 if((ch = fgetc(fp) == '\n'))
	  n++;
	}
	printf("有%d行\n", n);
	rewind(fp);
	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	fp = fopen("E:\\c#\\weiy\\weiy\\weiy.cpp", "r"); //打开文件
	n_char(fp);
	n_world(fp);
	n_row(fp);
	fclose(fp);
	return 0;
}

