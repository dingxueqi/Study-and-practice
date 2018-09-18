/*
题目描述
开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，
从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。

输入：
合法坐标为A(或者D或者W或者S) + 数字（两位以内）
坐标之间以;分隔。
非法坐标点需要进行丢弃。如AA10;  A1A;  $%$;  YAD; 等。
下面是一个简单的例子 如：
A10;S20;W10;D30;X;A1A;B10A11;;A10;

处理过程：
起点（0,0）
+   A10   =  （-10,0）
+   S20   =  (-10,-20)
+   W10  =  (-10,-10)
+   D30  =  (20,-10)
+   x    =  无效
+   A1A   =  无效
+   B10A11   =  无效
+  一个空 不影响
+   A10  =  (10,-10)
结果 （10， -10）


输入描述:
一行字符串

输出描述:
最终坐标，以,分隔

示例1
输入

A10;S20;W10;D30;X;A1A;B10A11;;A10;
输出

10,-10
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    
	int i=0,temp = 0;
    long x=0,y=0;
	char *string = (char *)malloc(10000);
	
	while(scanf("%s",string) != EOF){
        x=y=i=temp=0;
        while(string[i] != '\0')
        {
            if(string[i]=='A'&&(i==0 ||string[i-1]==';'))
            {
                ++i;
                if(string[i] >= '0' &&string[i] <= '9')
                {
                    temp = string[i]-48;
                    ++i;
                    if(string[i] >= '0' &&string[i] <= '9')
                    {
                        temp = temp*10 +string[i]-48;
                        x = x-temp;
                    }else if(string[i]==';'){
                        x = x-temp;
                    }
                }
            }else if(string[i]=='D'&&(i==0 ||string[i-1]==';')){
                ++i;
                if(string[i] >= '0' &&string[i] <= '9')
                {
                    temp = string[i]-48;
                    ++i;
                    if(string[i] >= '0' &&string[i] <= '9')
                    {
                        temp = temp*10 +string[i]-48;
                        x = x+temp;
                    }else if(string[i]==';'){
                        x = x+temp;
                    }
                }	
            }else if(string[i]=='W'&&(i==0 ||string[i-1]==';')){
                ++i;
                if(string[i]>='0' &&string[i ]<= '9')
                {
                    temp = string[i]-48;
                    ++i;
                    if(string[i]>='0' &&string[i]<='9')
                    {
                        temp = temp*10 +string[i]-48;
                        y = y+temp;
                    }else if(string[i]==';'){
                        y = y+temp;
                    }
                }
            }else if(string[i]=='S'&&(i==0 ||string[i-1]==';')){
                ++i;
                if(string[i]>='0' &&string[i]<='9')
                {
                    temp = string[i]-48;
                    ++i;
                    if(string[i]>='0' &&string[i] <= '9')
                    {
                        temp = temp*10 +string[i]-48;
                        y = y-temp;
                    }else if(string[i]==';'){
                        y = y-temp;
                    }
                }
            }else{
                //UNDO
            }
            i++;
        }
        printf("%lld,%lld\n",x,y);
    }
	free(string);
	return 0;
}