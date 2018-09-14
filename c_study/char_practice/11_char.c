/*
题目描述
编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。

输入描述:
输入N个字符，字符在ACSII码范围内。

输出描述:
输出范围在(0~127)字符的个数。

示例1
输入
abc

输出
3
*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char * string = NULL;
	string = (char *)malloc(5000);
	char ascll[128]={0};
	int i=0,j=0,k=0,flag =0;
	gets(string);
	while(string[i]!='\0')
	{

		if(0==i)
		{
			ascll[k]=string[i];
			i++;
			k++;
			continue;
		}else{
			for(j=0;j<k;j++)
			{
				if(ascll[j]==string[i]){
					flag = 1;
					break;
				}
			}
			if(0==flag){
				ascll[k]=string[i];
				k++;
			}
			flag = 0;
			i++;
		}
	}
	free(string);
	printf("%d\n",k);
	
}