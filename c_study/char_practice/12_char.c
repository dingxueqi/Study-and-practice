/*
题目描述
描述：
输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001

输入描述:
输入一个int整数

输出描述:
将这个整数以字符串的形式逆序输出

示例1
输入
1516000

输出
0006151
*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int input_value = 0,count=0,temp;
	char *string = (char *)malloc(100);
	scanf("%d",&input_value);
	
	while(input_value/10 != 0)
	{ 
		string[count] = 48 + (input_value%10);//数字转到字符要加上48
		input_value/=10;
		count++;
	}
	string[count] = 48+input_value;
	count++;
	string[count]='\0';
	printf("%s",string);
	
	free(string);
	return 0;
}