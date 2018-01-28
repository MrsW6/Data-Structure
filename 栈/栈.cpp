//��ʽջ�ļ�ʵ��
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
	//�˴�ֻ�ܴ���ȥ��ַ�����ʹ��
	//pStack pS;
	//initStack(pS);
	//���Ǳ�׼��Ұָ���ʹ�� 
	initStack(&S);
	push(&S,7);
	push(&S,1);
	push(&S,3);
	push(&S,9);
	printf("��pop����Ԫ����%d\n",pop(&S));
	travelStack(&S);
} 

void initStack(pStack pS)
{
	pS->pTop = (pNode)malloc(sizeof(Node));
	
	if(pS->pTop == NULL)
	{
		printf("�ڴ����ʧ�ܣ��˳�����\n");
		exit(-1);
	}	
	else
	{
		pS->pButtom = pS->pTop;
		pS->pTop->pNext = NULL;
		printf("�ڴ����ɹ�\n");
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
