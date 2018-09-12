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

typedef struct student{
	int index;
	int value;
	struct student *next;
} LinkList;

LinkList *creat(int n){
	LinkList *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = malloc(sizeof(LinkList));//分配地址
	end = head;         //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++) {
		node = malloc(sizeof(LinkList));
		
		scanf("%d", &node->index);
		scanf("%d", &node->value);
		
		end->next = node;
		end = node;
	}
	end->next = NULL;//结束创建
	return head;
}

void deal_with_re_index(LinkList *list,int n) {
	LinkList *t = list;
	int i = 0,j  =0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(t->next!=NULL){
				if(t->index == t->next->index)
				{
					t->value= t->value + t->next->value;
					delet(t,j+1)
				}
				t=t->next;
			}
		}
	}
	return;
}



void delet(LinkList *list, int n) {
	LinkList *t = list, *in;
	int i = 0;
	while (i < n && t != NULL) {
		in = t;
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in->next = t->next;
		free(t);
	}
	else {
		printf("nodes is not exist!\n");
	}
	return;
}

int main(void)
{
	LinkList * key_value = NULL;
	int input_num = 0;
	scanf("%d\n",&input_num);
	
	key_value = creat(input_value);
	
}