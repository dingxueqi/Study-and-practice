#include<stdio.h>
#include<math.h>

#define true 1
#define false 0

int a[9]={0};
int b[9] = {1,2,3,4,5,6,7,8,9};
int a_val=0,count=0,x,y,divisor=0,dividend=0,flag=0,flag1=0;
double tmp;
/*
对输入数据存放在一个数组中
并对数据判断是否为1~9这9个数
*/
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
    for(i = 0; i < 9 - 1; i ++)
	{
        for(j = i+1; j < 9; j ++)
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

/*

判断一个整数数据分离后，是否有交集
如果有则返回1，否则返回0

如123  145则返回1，123  876则返回1

*/
int num_sep_compare(int ii,int jj){
	int i=0,j=0,v=0,i_val=0,j_val=0;
	int a[6]={0};
	int b[6]={0};
	int tmp=0;
	while(ii > 0)
	{
		a[i_val]=ii%10;
		ii=ii/10;
		i_val++;
	}

	while(jj > 0)
	{
		b[j_val]=jj%10;
		jj=jj/10;
		j_val++;
	}
	
	//排序主体 从大到小
    for(i = 0; i < i_val-1; i ++)
	{
        for(j = i+1; j < i_val; j ++)
        {
            if(a[i] < a[j])//如前面的比后面的小，则交换。
            {
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
	}
	
	for(i = 0; i < j_val-1; i ++)
	{
        for(j = i+1; j < j_val; j ++)
        {
            if(b[i] < b[j])//如前面的比后面的小，则交换。
            {
                v = b[i];
                b[i] = b[j];
                b[j] = v;
            }
        }
	}
	#if 0
	i=0;
	while(i<9){
		printf("a[%d]=%d\n",i,a[i]);
		i++;
	}
	
		i=0;
	while(i<9){
		printf("b[%d]=%d\n",i,b[i]);
		i++;
	}
	#endif
	tmp=j_val;
	for(i_val;i_val--;i_val>0){
		j_val=tmp;
		for(j_val;j_val--;j_val>0)
		{

			//printf("判断i_val=%d  j_val=%d\n",i_val,j_val);
			if(a[i_val]==b[j_val]){
				i_val=0;
				j_val=0;
				return 1;
			}
				
		}
	}
	return 0;
}
/*

判断一个整数内是否有重复的数字
如果有则返回1，否则返回0

如123则返回0，122则返回1

*/
int num_is_double(int ii){
	int i=0,j=0,v=0,v_val=0;
	int a[10]={0};
	while(ii > 0)
	{
		a[v_val]=ii%10;
		ii=ii/10;
		v_val++;
	}
	
	//排序主体 从大到小
    for(i = 0; i < v_val-1; i ++)
	{
        for(j = i+1; j < v_val; j ++)
        {
            if(a[i] < a[j])//如前面的比后面的小，则交换。
            {
                v = a[i];
                a[i] = a[j];
                a[j] = v;
            }
        }
	}
	#if 0
	i=0;
	while(i<9){
		printf("a[%d]=%d\n",i,a[i]);
		i++;
	}
	#endif
	while(v_val!=1&&v_val > 1){
		if(a[v_val-1]==a[v_val-2])
		{
			v_val=0;
			return 1;
		}
		v_val--;	
	}
	return 0;
}
/*
判断一个数是由几个位组成
如1234，则返回4，12则返回2
*/
int sep_number(int value){
	int v_val=0,count=0;
	while(value > 0)
	{
		value=value/10;
		v_val++;
	}
	count=v_val;
	return count;
}
/*
判断一个数中是否有0
如12340，则返回1，12则返回0
*/
int is_num_zero(int value)
{
	volatile int i=0,v_val=0,count=0,num_array[6]={0};
	while(value > 0)
	{
		num_array[v_val]=value%10;
		value=value/10;
		v_val++;
	}

	for(i=0;i<v_val;i++)
	{
		//printf("a[%d]=%d\n",i,num_array[i]);
		if(num_array[i]==0)
			return 1;
	}
	return 0;
}

int func(int orig,int sep_count){
	int y_sep=0,d_sep=0,i=0;
	x = orig;
	y = x;;
	int temp1,temp2;
	while( y > 0)
	{
		while(is_num_zero(y)||num_is_double(y))
		{
			y--; /*过滤加数中带0和重复的数据*/
		}

		divisor = pow(10,(8+sep_count)/2);
		y_sep = sep_number(y);
		while(divisor > 0)
		{
			while(num_is_double(divisor)||is_num_zero(divisor)||num_sep_compare(y,divisor))
			{
				/*过滤分数中重复、带0或者和加数相同的数据*/
				divisor--;
				if(divisor==1)
					break;
			}
			if(divisor<10)
				break;

			d_sep = sep_number(divisor);
			temp2 = pow(10,9-y_sep-d_sep);
			temp1 = pow(10,9-y_sep-d_sep-1);
			dividend = temp2-1;


			if(divisor > 987654){
				divisor--;			
				continue;
			}

			if(divisor < dividend){
				divisor--;			
				continue;
			}
			
			while(dividend > temp1 && dividend < temp2)
			{ 
				
				while(num_is_double(dividend)|| is_num_zero(dividend)||num_sep_compare(y,dividend)||num_sep_compare(divisor,dividend))
				{
					/*过滤分母中重复、带0或者和加数相同的数据*/
					dividend--;
				}
				/*如下为判断数据是否符合 x = y + m/n 的要求，其中y,m,n为1~9中9个数据的组合*/
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