/*
题目描述
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。

输入描述:
输入一个int型整数

输出描述:
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数

示例1
输入
9876673

输出
37689
*/
#include<stdio.h>
int main(void)
{
	long input_value = 0,output=0;;
	int temp[32]={0},array[32]={0};
	int count=0,i=0,j=0,k=0,flag=0;
	scanf("%ld",&input_value);
	while(input_value/10 !=0)
	{
		temp[count] = input_value%10;
		input_value = input_value/10;
		count++;
		if(input_value < 10){
			temp[count] = input_value;
		}
	}
	count++;
	for(i=0;i<count;i++)
	{
		if(0==i){
			array[k] = temp[0];
			k++;
			continue;
		}
		for(j=0;j<k;j++)
		{
			if(temp[i]==array[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			array[k] = temp[i];
			k++;
		}
		flag = 0;
	}
	
	for(i=0;i<k;i++)
	{
		output = output*10 + array[i];
	}
	printf("%ld\n",output);
	
}