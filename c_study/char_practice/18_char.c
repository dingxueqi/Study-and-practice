#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
    int i=0,j=0,k=0,input_num = 0,sum=0,temp=0;;
    int *output=NULL;
    scanf("%d",&input_num);

    for(i=1;i<=input_num;i++)
    {
        sum += i;/*计算要存储多少个数据*/
    }
	output = (int *)malloc(sizeof(int) * sum);/*申请需要存储数据的空间大小*/
	memset(output,0,sizeof(int)*sum);
	for(i=1;i<=input_num;i++)
	{
		output[i-1]= temp +i;
		temp = output[i-1];/*计算并存储第一排中的数据*/
	}
	k=input_num;
	temp = input_num;
	for(i=1;i<=input_num;i++)
	{
		for(j=i;j<input_num;j++)
		{
			output[k] = output[k-temp+1]-1;
			k++;
		}
		temp--;
	}
	for(i=0,k=0;i<input_num;i++)
	{
		for(j=i;j<input_num;j++)
		{
			printf("%d ",output[k]);
			k++;
		}
		printf("\n");
	}
    free(output);
    return 0;
}