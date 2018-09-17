/*
题目描述
给定n个字符串，请对n个字符串按照字典序排列。

输入描述:
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。

输出描述:
数据输出n行，输出结果为按照字典序排列的字符串。
示例1
输入
9
cap
to
cat
card
two
too
up
boat
boot

输出
boat
boot
cap
card
cat
to
too
two
up
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct word{
	char words[100];
	struct word *next;
}LinkList_Word;

LinkList_Word *creat(int num)
{
	int i = 0;
	LinkList_Word *head=NULL,*node=NULL,*end=NULL;
	head = malloc(sizeof(LinkList_Word));
	memset(head,0,sizeof(LinkList_Word));
	end = head;
	
	for(i = 0;i < num;i++)
	{
		node = malloc(sizeof(LinkList_Word));
		memset(node,0,sizeof(LinkList_Word));
		scanf("%s",&node->words);
		end -> next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}
void dict_sort(LinkList_Word *list)
{
	LinkList_Word *head = NULL,*pre = NULL,*cur = NULL,*next = NULL,*end = NULL,*temp = NULL;
	int i = 0;
	head = list;
	end = NULL;
	if((list -> next == NULL) || (list -> next -> next == NULL))
    {
        return;
    }

	while(head->next != end){
        for(pre = head, cur = pre -> next, next = cur -> next; next != end; pre = pre -> next, cur = cur -> next, next = next -> next)
        {
            //相邻的节点比较
            while(cur -> words[i] !='\0' && next -> words[i] !='\0')
            {
				if((cur -> words[i] > next -> words[i]) \
                   || ((cur -> words[i] == next -> words[i]) && next->words[i+1]=='\0')){
					cur -> next = next -> next;
					pre -> next = next;
					next -> next = cur;
					temp = next;
					next = cur;
					cur = temp;
					break;
				}else if((cur -> words[i] < next -> words[i]) \
                ||((cur -> words[i] == next -> words[i]) && cur->words[i+1]=='\0')){
					break;
				}
				i++;
            }
			i = 0;
        }
        end = cur;
	}
}
void printf_word(LinkList_Word * list)
{
	list = list->next;
	while(list!=NULL)
	{
		printf("%s\n",list->words);
		list= list->next;
	}
}
void Free_LinkList(LinkList_Word * list)
{
	LinkList_Word *temp = NULL;
	while(list!=NULL)
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
	int input_num = 0;
	LinkList_Word *list = NULL;
	scanf("%d",&input_num);
	if(input_num < 1 && input_num > 1000)
		return -1;
	list = creat(input_num);
	dict_sort(list);
	//printf("################\n");
	printf_word(list);
	Free_LinkList(list);
	return 0;
}