/*
题目描述
数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。

输入描述:
先输入键值对的个数
然后输入成对的index和value值，以空格隔开

输出描述:
输出合并后的键值对（多行）

示例1

输入
4
0 1
0 2
1 2
3 4

输出
0 3
1 2
3 4
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	int index;
	int value;
	struct student *next;
} LinkList;
/*创建链表并动态申请空间存储index-value*/
LinkList *creat(int n){
	LinkList *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = malloc(sizeof(LinkList));//分配地址
	memset(head,0,sizeof(LinkList));
	//scanf("%d", &head->index);
	//scanf("%d", &head->value);
	
	end = head;         //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++) {
		node = malloc(sizeof(LinkList));
		memset(node,0,sizeof(LinkList));
		scanf("%d", &node->index);
		scanf("%d", &node->value);
		
		end->next = node;
		end = node;
	}
	end->next = NULL;//结束创建
	return head;
}
/*冒泡对index进行从小到大排序*/
void bubbleSort(LinkList *list)
{
    if((list -> next == NULL) || (list -> next -> next == NULL))
    {
        return;
    }

    LinkList *head, * pre, * cur, *next, * end, * temp;
    head = list;
    end = NULL;
    while(head -> next != end)
    {
        for(pre = head, cur = pre -> next, next = cur -> next; next != end; pre = pre -> next, cur = cur -> next, next = next -> next)
        {
            //相邻的节点比较
            if(cur -> index > next -> index)
            {
                cur -> next = next -> next;
                pre -> next = next;
                next -> next = cur;
                temp = next;
                next = cur;
                cur = temp;
            }
        }
        end = cur;
    }
}
/*去掉重复的index并把index中值相加保存*/
void norepeat(LinkList *list,int n) {
	LinkList *temp = NULL,*cur=NULL,*pre = NULL;
	int i = 0,j  =0,k=0;
	pre = list;
	
	for(i=1;i < n;i++)
	{
		cur = pre->next;
		for(j=i;j < n;j++)
		{	
			if(cur->next!=NULL){
				if(pre->next->index == cur->next->index)
				{
					pre->next->value =  pre->next->value + cur->next->value;
					if(cur->next->next != NULL)
						temp = cur->next->next;
					else
						temp = NULL;
					free(cur->next);
					cur->next=temp;
					n--;
					j--;
					continue;
				}
				cur=cur->next;
			} 
		}
		pre=pre->next;
	}

	return;
}
/*打印节点中的index-value*/
void printf_LinkList(LinkList *list)
{
	list = list->next;
	while(list != NULL)
	{
		printf("%d %d\n",list->index,list->value);
		list = list->next;
	}
}
/*释放申请空间*/
void Free_LinkList(LinkList *list)
{
	LinkList *temp = list;
	while(list != NULL)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	temp = NULL;
	
	return;
}

int main(void)
{
	LinkList * key_value = NULL;
	int input_num = 0;
	scanf("%d\n",&input_num);
	
	key_value = creat(input_num);
	norepeat(key_value,input_num);
	bubbleSort(key_value);
	printf_LinkList(key_value);
	Free_LinkList(key_value);
	return 0;
	
}