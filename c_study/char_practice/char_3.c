/*
题目描述
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。

输入描述:
输入一个有字母和数字以及空格组成的字符串，和一个字符。

输出描述:
输出输入字符串中含有该字符的个数。

示例1
输入

ABCDEF A

输出

1
*/
#include<stdio.h>

int main(void)
{
	int i=0,count=0;
	char *str = (char *)malloc(1000);
	char target = ' ';
	
	gets(str);
    scanf("%c",&target);
	while(str[i] != '\0'){
		if(str[i] == ' ')
			break;
		if(target >= 'a' && target <= 'z')
		{
			if(target == str[i] || (target - 32) == str[i])
				count++;
		}else if(target >= 'A' && target <= 'Z'){
			if(target == str[i] || (target + 32) == str[i])
				count++;			
		}else{
			if(target == str[i])
				count++;			
		}
		i++;
	}
    free(str);
	printf("%d\n",count);
}