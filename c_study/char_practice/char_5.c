/*
题目描述
明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），
对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，
按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，希望大家能正确处理)。

Input Param
n              输入随机数的个数
inputArray      n个随机整数组成的数组

Return Value
OutputArray    输出处理后的随机整数
注：测试用例保证输入参数的正确性，答题者无需验证。测试用例不止一组。

输入描述:
输入多行，先输入随机整数的个数，再输入相应个数的整数

输出描述:
返回多行，处理后的结果

示例1
输入

11
10
20
40
32
67
40
20
89
300
400
15
输出

10
15
20
32
40
67
89
300
400
*/
#include<stdio.h>
#include<stdlib.h>
#define USE_GETS_INPUT
#define  true 1
#define  false 0
char sample[11] = {'0','1','2','3','4','5','6','7','8','9',' '};
int convert_array[1000] = {0};
static int count = 0,input_data_num=0,flag1 = 0;
/*
解析一段字符串，第一个为要输入的个数，以空格为分隔符，把char数字转化成Int存到数组中
如输入5 32 98 87 3 2 
返回5，32 98 87 3 2 分别存在convert_array数组中
*/
int string_to_int(char *string){
	int i=0,j=0,flag=0,data=0,digital=0,flag2=0;
	int blank = true;
	while(string[i]!='\0')
	{
		flag = -1;
		data=digital;
		for(j=0;j<11;j++)
		{
			if(string[i] == sample[j]){
				flag = 1;
				blank=true;
				break;
			}
		}
		if(string[i]!= ' ')
		{
			digital = string[i]-48;
		}
		if(string[i]==' '){
			flag = 2;
		}else if (flag == 1){
			flag = 1;
		}else {
			flag2 = 1;
		}
		if(flag == 1)
		{
			digital = data*10+digital;
		} else if (flag == -1){
			blank = false;
			digital = 0;
		}else if(flag == 2){
			if(blank){
				if(count ==0 && flag1 ==0)
				{
					input_data_num = digital;
					flag1 = 1;
				}else {
					if(flag2!=1){
						convert_array[count] = digital;
						count++;
					}
				}
				flag2 = 0;
				blank = false;
			}
			digital = 0;
		}
		i++;
	}

	return count;
}


void norepeat_sort(int sort[],int array_num)
{
	int i=0,j=0,count=0,flag=0,temp=0;
	int *outputarray=NULL;
	outputarray=(int *)malloc(array_num*sizeof(int));
	for(i=0;i<array_num;i++)
    {
		if(0==i){
			outputarray[0]=sort[0];
			count++;
			continue;
		}
		for(j=0;j < i ;j++)
		{
			if(outputarray[j]==sort[i]){
				flag=1;
				break;
			}
		}
		if(1==flag)
		{
			flag=0;
		}else{
			outputarray[count]=sort[i];
			count++;
		}
	}
	for(i=0;i < count-1;i++)
	{
		for(j=i+1;j < count;j++)
		{
			if(outputarray[i] > outputarray[j])
			{
				temp = outputarray[i];
				outputarray[i] = outputarray[j];
				outputarray[j] = temp;
			}
		}	
	}
	for(i=0;i<count;i++)
	{
		printf("%d \n",outputarray[i]);
	}
	//printf("\n");
	free(outputarray);
	return;
}


int main(void)
{
	#if defined(USE_GETS_INPUT)
	char * inputArray = NULL;
	int i=0,ret_val=0;
	inputArray = (int *)malloc(sizeof(int)*1000);
	gets(inputArray);
	ret_val = string_to_int(inputArray);
	norepeat_sort(convert_array,ret_val);
	free(inputArray);
	#else
	int input_Num=0,i=0;
	int * inputArray = NULL;
	scanf("%d",&input_Num);
	inputArray = (int *)malloc(sizeof(int)*input_Num);

	for(i=0;i<input_Num;i++)
	{
		scanf("%d",&inputArray[i]);
	}
	norepeat_sort(inputArray,input_Num);
	free(inputArray);
	#endif
	return 0;
}