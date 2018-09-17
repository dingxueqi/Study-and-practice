/*
题目描述
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”
所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

接口说明


 * 反转句子
 * 
 * @param sentence 原句子
 * @return 反转后的句子

public String reverse(String sentence);

输入描述:
将一个英文语句以单词为单位逆序排放。

输出描述:
得到逆序的句子

示例1
输入
I am a boy

输出
boy a am I
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * reverse(char *string)
{
	int count=0,i=0,j=0,k=0,word=0;
	char *str = NULL;
	while(string[count]!='\0')
	{
		count++;
	}
	str = (char *)malloc(count+1);
	memset(str,0,count+1);

	for(i=count-1;i>=0;i--)
	{
		if(string[i] == ' ' || i == 0)
		{
			if(i == 0)
			{
				word++;
				for(j=0;j<word;j++){
					str[k]=string[i+j];
					k++;
				}
				word = 0;
			}else{
				for(j=0;j < word;j++)
				{
					str[k]=string[i+j+1];
					k++;
				}
				str[k]= ' ';
				k++;
				word = 0;
			}
		}
		if(string[i] != ' ')
			word++;
		if(i == 0){
			str[k+1]='\0';
		}
	}
	return str;
}
int main(void)
{
	char *string = (char *)malloc(10000);
	char *out_str = NULL;
	gets(string);
	
	out_str=reverse(string);
	
	printf("%s\n",out_str);
	
	free(out_str);
	free(string);
	return 0;
}