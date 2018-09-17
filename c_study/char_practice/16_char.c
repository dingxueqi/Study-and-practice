/*
题目描述
输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。

输入描述:
 输入一个整数（int类型）

输出描述:
 这个数转换成2进制后，输出1的个数

示例1
输入
5

输出
2
*/
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int input_num = 0,i = 0,count = 0;
	scanf("%d",&input_num);
	
	for(i=0;i < sizeof(int)*8;i++)
	{
		if((input_num & 0x1) == 1)
			count++;
		input_num >>=1;
	}
	printf("%d\n",count);
	return 0;
}