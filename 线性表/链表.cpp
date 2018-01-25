#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}Node,*pNode; 

pNode creat_list();
void travel_list(pNode pHead);
bool is_empty(pNode pHead);
int length_list(pNode pHead);
bool insert_list(pNode pHead,int index,int value);
bool delete_list(pNode pHead,int index);
void sort_list(pNode pHead);
int get_list(pNode pHead,int index);

int main()
{
	//创建头指针
	pNode pHead = NULL;
	pHead = creat_list();	
	printf("链表的长度为：%d\n",length_list(pHead));
	travel_list(pHead);
	printf("%d\n",get_list(pHead,1));
}

pNode creat_list()
{
	int len;
	int value;
	pNode pHead = (pNode)malloc(sizeof(pNode));
	pNode pTail = pHead;
	pTail->pNext = NULL;
	if(pHead == NULL)
	{
		printf("内存分配失败，程序终止");
		exit(-1);
	}
	else
	{
		printf("请输入您需要链表节点的个数len= ");
		scanf("%d",&len);
		for(int i = 0; i < len; i++)
		{
			printf("请输入第%d个节点的值:",i+1);
			scanf("%d",&value);
			pNode pNew = (pNode)malloc(sizeof(pNode));
			if(pNew == NULL)
			{
				printf("内存分配失败，程序终止");
				exit(-1);
			}
			pNew->data = value;
			pTail->pNext = pNew;
			pNew->pNext = NULL;
			pTail = pNew;
		}
		return pHead;
	}
}

//遍历链表 
void travel_list(pNode pHead)
{
	pNode p = pHead->pNext;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->pNext;
	}
	printf("\n");
}

bool is_empty(pNode pHead)
{
	if(pHead->pNext == NULL)
	{
		return true;
	}
	return false;
}

int length_list(pNode pHead)
{
	int count = 0;
	pNode p = pHead->pNext;
	while(p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
}

bool insert_list(pNode pHead,int index,int value)
{
	int length = length_list(pHead);
	pNode p;
	p = pHead;
	if(index > length+1 || index < 1)
	{
		printf("无法在此位置插入元素\n");
	}
	else
	{
		pNode pNew = (pNode)malloc(sizeof(pNode));
		if(NULL == pNew)
		{
			printf("动态内存分配失败\n");
			exit(-1);
		}	
		else
		{
			while(index > 1)
			{
				p = p->pNext;
				index--;
			}
			pNode q = p->pNext;
			pNew->data = value;	
			pNew->pNext = q;
			p->pNext = pNew;
		}
	} 
}

bool delete_list(pNode pHead,int index)
{
	pNode p;
	p = pHead; 
	int length = length_list(pHead);
	if(index < 1 || index > length)
	{
		printf("此处无数值，无法删除\n");
	}
	else if(index == 1)
	{
		pHead->pNext = pHead->pNext->pNext;
	}
	else
	{
		while(index > 1)
		{
			p = p->pNext;
			index--;
		}
		pNode q = p->pNext->pNext;
		p->pNext = q;
	}
}

void sort_list(pNode pHead)
{
	int i,j;
	int length = length_list(pHead);
	pNode q;
	for(i = 0; i < length - 1; i++)
	{
		for(j = 0,q = pHead->pNext; j < length - 1; j++,q = q->pNext)
		{
			if(q->data > q->pNext->data)
			{
				int temp = q->data;
				q->data = q->pNext->data;
				q->pNext->data = temp;
			}
		}
	}
}

int get_list(pNode pHead,int index)
{
	pNode p = pHead;
	while(index >0)
	{
		p = p->pNext;
		index--;
	}
	return p->data;
}



