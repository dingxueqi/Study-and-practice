/*
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述:
输入N个字符

输出描述:
输出该字符串反转后的字符串

示例1
输入
abcd

输出
dcba
*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int count=0,i=0;
	char *string = (char *)malloc(1000);
	char temp = 0;
	gets(string);
	
	while(string[count]!='\0')
	{ 
		count++;
	}	
	for(i=0;i< count/2;i++)
	{
		temp = string[i];
		string[i] = string[count-1-i];
		string[count-1-i]=temp;
		
	}
	printf("%s\n",string);
	
	free(string);
	return 0;
}