/*
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。 
输入描述:
一行字符串，非空，长度小于5000。

输出描述:
整数N，最后一个单词的长度。

输入
hello world

输出
5
*/
#include<stdio.h>
int main(void){
    int i=0,j=0,count_blank=0;
    char *str = (char *)malloc(5000);
    gets(str);
    
    while((int)str[i]!=0)
    {
		i++;
        j++;
        if(str[i]==' ' || str[i]=='\t')
        {
            j=0;
            count_blank++;
        }
    }
    if(0==count_blank)
        j=i+1;
    free(str);
    printf("%d\n",j-1);
}