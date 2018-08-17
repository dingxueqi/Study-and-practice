#include<stdio.h>
#include<math.h>

#define true 1
#define false 0

int a[20]={0};
int b[9] = {1,2,3,4,5,6,7,8,9};
int a_val=0,flag=0,count=0,x,y,divisor,dividend,flag1;
double tmp;

void array_sort(int ii,int jj,int kk){
	int i,j,v;
	flag1=true;
	while(ii > 0)
	{
		a[a_val]=ii%10;
		ii=ii/10;
		a_val++;
	}
	while(jj > 0)
	{
		a[a_val]=jj%10;
		jj=jj/10;
		a_val++;
	}
	while(kk > 0)
	{
		a[a_val]=kk%10;
		kk=kk/10;
		a_val++;
	}
	 //排序主体
    for(i = 0; i < 20 - 1; i ++)
	{
        for(j = i+1; j < 20; j ++)
        {
            if(a[i] > a[j])//如前面的比后面的大，则交换。
            {
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
	}
	if(a_val!=9)
		flag1=false;
	a_val=0;
}

int func(int orig,int sep_count){
	int i,j;
	x = orig;
	y = x;;

	while( y > 0)
	{
		divisor = pow(10,(8+sep_count)/2);
		while(divisor > 0)
		{
			dividend = pow(10,(8-sep_count)/2);

			while(dividend > 0)
			{

				tmp = (double)divisor/(double)dividend;
				if((double)x==((double)y+tmp))
				{
		
					array_sort(y,divisor,dividend);
					if(false==flag1)
						break;
					for(i=0;i<9;i++)
					{
						if(a[i]==b[i])
						{
							flag+=1;
							continue;
						}
					}
					if(9==flag){
						count++;
						printf("%d=%d+%d/%d\n",orig,y,divisor,dividend);
					}
					flag=0;
					flag1=0;
				}
				dividend--;
			}
			divisor--;
		}
		y--;
	}
	return count;

}

int main(void)
{
	int i=0,j,val,input_num;

	loop:
		printf("pls input a num:");
		scanf("%d",&x);
	if(x < 0||x >= 1000000)
	{
		printf("pls input valid num!!!!\n");
		goto loop;
	}
	input_num=x;
	while(x > 0 && x < 1000*1000)
	{
		do{
			i++;
			x=x/10;
		}while(x/10!=0);
	}
	//printf("输入的是%d个位数\n",i);
	
	val = func(input_num,i);
	printf("val =%d\n",val);
    return 0;
}