//链式栈的简单实现
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*pNode;

typedef struct stack
{
	pNode pTop;
	pNode pButtom;
}Stack,*pStack;

void initStack(pStack pS);
void push(pStack pS,int value);
int pop(pStack pS);
void travelStack(pStack pS);
bool is_empty(pStack pS);

int main()
{
	Stack S;
	//此处只能穿进去地址，如果使用
	//pStack pS;
	//initStack(pS);
	//这是标准的野指针的使用 
	initStack(&S);
	push(&S,7);
	push(&S,1);
	push(&S,3);
	push(&S,9);
	printf("被pop掉的元素是%d\n",pop(&S));
	travelStack(&S);
} 

void initStack(pStack pS)
{
	pS->pTop = (pNode)malloc(sizeof(Node));
	
	if(pS->pTop == NULL)
	{
		printf("内存分配失败，退出程序\n");
		exit(-1);
	}	
	else
	{
		pS->pButtom = pS->pTop;
		pS->pTop->pNext = NULL;
		printf("内存分配成功\n");
	}
}

void push(pStack pS,int value)
{
	pNode pNew = (pNode)malloc(sizeof(Node));
	
	pNew->data = value;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
	
	return;
}

int pop(pStack pS)
{
	
	if(is_empty(pS))
	{
		return NULL;
	}
	else
	{
		int value = pS->pTop->data;
		pS->pTop = pS->pTop->pNext;
		return value;
	}	
}

bool is_empty(pStack pS)
{
	if(pS->pButtom == pS->pTop)
		return true;
	return false;
}

void travelStack(pStack pS)
{
	pNode pNew = (pNode)malloc(sizeof(Node));
	pNew = pS->pTop;
	while(pNew != pS->pButtom)
	{
		printf("%d ",pNew->data);
		pNew = pNew->pNext;
	}
}
