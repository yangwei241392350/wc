// weiy.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<string.h>
int n_char(FILE *fp)
{
	int num = 0;
	char s[2000];
	while(!feof(fp))
	{
		 fscanf(fp, "%s", s); //��ȡ�ַ���
		 num += strlen(s); //�����ַ���
	}
	printf("�ַ��������ƿո�ͻس�����%d��\n",num);
	rewind(fp); //�ƻ��ļ�ָ��
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
	printf("��������%d����������%d��\n",n,num);
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
	printf("��%d��\n", n);
	rewind(fp);
	return n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	fp = fopen("E:\\c#\\weiy\\weiy\\weiy.cpp", "r"); //���ļ�
	n_char(fp);
	n_world(fp);
	n_row(fp);
	fclose(fp);
	return 0;
}

