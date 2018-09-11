/*
题目描述
写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。

输入描述:
输入一个正浮点数值

输出描述:
输出该数值的近似整数值

示例1
输入
5.5

输出
6
*/

#include<stdio.h>

int main(void)
{
    float num = 0.0;
    int temp = 0,val=0;
    scanf("%f",&num);
    num *= 10.0;
	temp = (int)num;
    while(temp/10 != 0){
		val = temp%10;
		temp/=10;
    }
	if(temp < 10)
		val = (int)num%10;
    if(val >= 5)
        val = (int)(num/10.0 + 1);
    else
        val = (int)(num/10.0);
    printf("%d\n",val);
}