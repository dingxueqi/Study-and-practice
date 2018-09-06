/*题目描述
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）

输入描述:
输入一个十六进制的数值字符串。

输出描述:
输出该数值的十进制字符串。

示例1
输入
0xA

输出
10
*/
#include <stdio.h>
#include <stdio.h>
 
char sample[30] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','A','B','C','D','E','F'};

static count = 0; 
int string_is_valid(char *string){
	int i=2,j=0,flag=1;;
	while(string[i]!='\0' && flag == 1)
	{
		flag = 0;
		for(j=0;j<22;j++)
		{
			if(string[i]==sample[j]){
				flag=1;
				count++;
				break;
			}
		}
		i++;
	}
	return flag;
}
 
int main(void)
{
	char *str = (char *)malloc(500);
	int len=0,digital;
	int old=0;
	while(1){
		gets(str);
		if(str[0]!='0'&&(str[1]!='x' || str[1]!='X')){
			printf("unvalid data(hex)!\n");
			free(str);
			return -1;
		}
		if(!string_is_valid(str)){
			printf("unvalid data\n");
			free(str);
			return -1;
		}
		for (len = 2; len < count+2; len++)
		{
			old=digital;
			if (str[len] >= 'a' && str[len] <= 'f')
			{
				digital = (str[len] - 87);
			}
			else if (str[len] >= 'A' && str[len] <= 'F')
			{
				digital = (str[len] - 55) ;
			}
			else if (str[len] >= '0' && str[len] <= '9')
			{
				digital = (str[len] - 48) ;
			}
			else
			{
				break;
			}
			digital = old*16+digital;
		}
		printf("%d\n", digital);
		memset(str,0,500);
		count=0;
		digital=0;
	}
	return 0;
}