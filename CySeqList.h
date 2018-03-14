#include<stdio.h>
#include<assert.h>
#include<windows.h>
#include<stdlib.h>

typedef int DataType;

typedef struct SeqList
{
	DataType _data;
	struct SeqList* _next;
}SeqList;

void SeqListInit(SeqList** pphead)//初始化
{
	*pphead = (SeqList*)malloc(sizeof(SeqList));
	assert(*pphead);
	(*pphead)->_next = *pphead;
}
SeqList* BuyHead(DataType data)
{
	SeqList* head =(SeqList*)malloc(sizeof(SeqList));
	assert(head);
	head->_data = data;
	head->_next = head;
	return head;
}
void SeqListPrint(SeqList* phead)
{
	assert(phead);
	SeqList* cur = phead;
	while (cur->_next != phead)
	{
		cur = cur->_next;
		printf("%d ", cur->_data);
	}
}
void SeqListPushBack(SeqList** pphead, DataType data)
{
	assert(*pphead);
	SeqList* NewHead = BuyHead(data);
	SeqList* front = *pphead;//头指针
	SeqList* cur = *pphead;//移动指针
	if ((*pphead)->_next == front)
	{
		(*pphead)->_next = NewHead;
		NewHead->_next = front;
	}
	else
	{
		while (cur->_next != front)
			cur= cur->_next;
		NewHead->_next = front;
		cur->_next = NewHead;
	}
}

void SeqListPopBack(SeqList** pphead)
{
	assert(*pphead);
	SeqList* front = *pphead;//头结点
	SeqList* cur = *pphead;
	SeqList* prev = *pphead;
	if ((*pphead)->_next == front)
		return;
	else
	{
		while (cur->_next != front)
		{
			prev = cur;
			cur = cur->_next;
		}
		prev->_next = front;
		free(cur);
	}
}
void SeqListPushFront(SeqList** pphead, DataType data)
{
	assert(*pphead);
	SeqList* NewHead = BuyHead(data);
	SeqList* cur = (*pphead)->_next;//记录头结点的下一个位置
	NewHead->_next = cur;
	(*pphead)->_next = NewHead;
}
void SeqListPopFront(SeqList** pphead)
{
	assert(*pphead);
	if ((*pphead)->_next == *pphead)
		return;
	else
	{
		SeqList* cur = (*pphead)->_next;
		(*pphead)->_next = cur->_next;
		free(cur);
	}
}
SeqList* SeqListFind(SeqList* phead, DataType data)
{
	if (phead->_next == phead)
		return 0;
	else
	{
		SeqList* front = phead;
		while (phead->_next != front)
		{
			phead = phead->_next;
			if (phead->_data == data)
				return phead;
		}
		return -1;
	}
}
int SeqListLength(SeqList* phead)
{
	if (phead->_next == phead)
		return 0;
	else
	{
		int count = 0;
		SeqList* front = phead;
		while (phead->_next != front)
		{
			count++;
			phead = phead->_next;
		}
		return count;
	}
}
//////////////////////////////////////////////////////////////////////
//查找链表的中间元素
SeqList* SeqListMid(SeqList* phead)
{
	assert(phead);
	SeqList* fast = phead;
	SeqList* slow = phead;
	if (phead->_next == phead)
		return 0;
	if ((phead->_next->_next == phead) || (phead->_next->_next->_next == phead))
		return phead->_next;
	else
	{
		while (fast->_next != phead)
		{
			fast = fast->_next->_next->_next;
			slow = slow->_next->_next;
		}
		return slow;
	}
}
//判断是否是循环链表
int SeqListFloyd(SeqList* phead)
{
	assert(phead);
	SeqList* fast = phead;
	SeqList* slow = phead;
	if (phead->_next == NULL)
		return -1;
	if (phead->_next == phead)
		return 1;
	else
	{
		while ((slow != NULL) && (fast != NULL) && (fast->_next != NULL))
		{
			if (fast == slow || fast->_next == slow)
				return 1;
			fast = fast->_next->_next;
			slow = slow->_next;	
		}
		return -1;
	}
}

 