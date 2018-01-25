//线性表的简单实现 
#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>//exit(-1)

struct Arr
{
	//数组第一个元素的指针 
	int *psd;
	int max;
	int cnt;
};

//功能列表 
void init(struct Arr *parr,int length);
bool append(struct Arr *parr,int value);
bool insert(struct Arr *parr,int index,int value);
bool deletes(struct Arr *parr,int index);
void get(struct Arr *arr,int index);
bool is_empty(struct Arr *parr);
bool is_full(struct Arr *parr);
void show(struct Arr *parr);
void sort(struct Arr *parr);

int main()
{
	int length = 10;
	struct Arr arr;
	init(&arr,length);
	//show(&arr);
	insert(&arr,1,30);
	insert(&arr,2,40);
	append(&arr,2);
	append(&arr,0);
	append(&arr,100);
	sort(&arr);
	show(&arr);
//	append(&arr,1);
//	append(&arr,2);
//	append(&arr,3);
//	append(&arr,4);
//	append(&arr,5);
//	show(&arr);
	return 0;	
} 

//*arr赋值给parr 
void init(struct Arr *parr,int length)
{
	parr->psd = (int*)malloc(sizeof(int) * length);
	if(NULL == parr->psd)
	{
		printf("内存分配失败!\n");
		exit(-1);
	}
	else
	{
		parr->max = length;
		parr->cnt = 0;
	}
}

bool is_empty(struct Arr *parr)
{
	if(parr->cnt == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void show(struct Arr *parr)
{
	if(is_empty(parr))
	{
		printf("数组为空！\n");
	}
	else
	{
		printf("数组为：");
		for(int i = 0; i < parr->cnt; i++)
		{
			printf("%d ",parr->psd[i]);	
		} 
		printf("\n");
	}
}

bool is_full(struct Arr *parr)
{
	if(parr->cnt == parr->max)
	{
		return true;
	}
	else
		return false;
} 

bool append(struct Arr *parr,int value)
{
	if(is_full(parr))
	{
		printf("数组已满,数值%d插入失败\n",value);
		return false;
	}
	else
	{
		printf("数值%d插入成功\n",value);
		parr->psd[parr->cnt] = value;
		(parr->cnt)++;
		return true;
	}
}

bool insert(struct Arr *parr,int index,int value)
{
	if(is_full(parr))
	{
		printf("数组已满，数值%d无法插入",value);
		return false;
	}
	else if(index < 1 || index > parr->cnt + 1)
	{
		printf("数值%d插入失败\n",value);
		return false;
	}
	else
	{
		printf("数值%d插入成功\n",value);
		for(int i = parr->cnt-1; i >= index-1; i--)
		{
			parr->psd[i+1] = parr->psd[i];
		}
		parr->psd[index-1] = value;
		parr->cnt++;
		return true;
	}
}

bool deletes(struct Arr *parr,int index) 
{
	if(is_empty(parr))
	{
		printf("数组已为空，不可删除元素\n");
		return false;
	}
	else if(index > parr->cnt)
	{
		printf("此位无元素，不可删除\n");
		return false;
	}
	else
	{
		printf("第%d个元素删除成功\n",index);
		for(int i = index; i <= parr->psd[index-1]; i++)
		{
			parr->psd[index-1] = parr->psd[index]; 
		}
		parr->cnt--;
		return true;
	}
}

void get(struct Arr *parr,int index)
{
	if(parr->cnt > index)
	{
		printf("此位置没有元素");
	}
	else
	{
		printf("此位置的元素为：%d\n",parr->psd[index-1]);
	}
}

void sort(struct Arr *parr)
{
	for(int i = 0; i < parr->cnt; i++)
	{
		for(int j = 0; j < parr->cnt-1; j++)
		{
			if(parr->psd[j] > parr->psd[j+1])
			{
				int temp;
				temp = parr->psd[j];
				parr->psd[j] = parr->psd[j+1];
				parr->psd[j+1] = temp;
			}
		}
	}
	printf("排序后");
	void show(struct Arr *parr); 
}







