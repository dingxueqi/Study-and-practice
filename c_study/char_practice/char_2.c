/*
题目描述
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组； 
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。 

输入描述:
连续输入字符串(输入2次,每个字符串长度小于100)

输出描述:
输出到长度为8的新字符串数组

示例1
abc
123456789

输出
abc00000
12345678
90000000
*/
#include<stdio.h>
char temp[8] = {0};
int main(void)
{
    int i=0,j=0,k=0,count=0,str_cnt=0,str_cnt1=0;
    char *str = (char *)malloc(100);
    char *str1 = (char *)malloc(100);
    gets(str);
    gets(str1);
    while((str[i] != '\0')||(str1[j] != '\0'))
    {
        if(str[i]!='\0')
            i++;
        if(str1[j] != '\0')
            j++;
    }
	str_cnt=i;
	str_cnt1=j;
	i=j=0;
    while(str[i]!='\0'){
		if(str_cnt>=8)
		{
            for(k=0;k<8;k++,i++){
                temp[k] = str[i];
            }
			printf("%s\n",temp);
		} else {
			count = str_cnt%8;
			for(k=0;k<count;k++,i++)
			{
				temp[k] = str[i];
			}
			for(;k<8;k++)
			{
				temp[k] = '0';
			}
			printf("%s\n",temp);
			break;
		}
		str_cnt-=8;
    }

    while(str1[j]!='\0'){
		if(str_cnt1>=8)
		{
            for(k=0;k<8;k++){
                    temp[k] = str1[j];
					j++;
             } 
			printf("%s\n",temp);
		} else {
			count = str_cnt1%8;
			for(k=0;k<count;k++)
			{
				temp[k] = str1[j];
				j++;
			}
			for(;k<8;k++)
			{
				temp[k] = '0';
			}
			printf("%s\n",temp);
			break;
		}
		str_cnt1 -= 8;
    }
}