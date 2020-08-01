#pragma once

#include <iostream>
#include <stdlib.h>

typedef int ElementType;

/*
 * brief:   单链表的节点结构【一个单链表节点中，需要存储数据，以及指向后继节点的指针，其中所有参数L为头结点】
 * author:  zengxt
 * begin:   2020年7月31日23:40:44
 */
struct LnkListNode
{
	ElementType  data; // 数据域
	LnkListNode* next; // 指针域
};
typedef LnkListNode LnkList;

/**
* brief:    头插法建表
* method:   CreateListF
* param:    LnkList * L      创建的单链表，输出参数
* param:    ElementType a[]  存储源数据的数组
* param:    int n            数组a的长度
* return:   void
*/
void CreateListF(LnkList* L, ElementType a[], int n)
{
	/*LnkList* L = (LnkList*)malloc(sizeof(LnkList));*/
	L->next = NULL; // 将L置为头节点，其指针域初始化为NULL

	for (int i = 0; i < n; ++i)
	{
		LnkList* ptr = (LnkList*)malloc(sizeof(LnkList));
		ptr->data = a[i];
		ptr->next = L->next;
		L->next = ptr;
	}
}

/**
* brief:    尾插法建表
* method:   CreateListR
* param:    LnkList * L      创建的单链表，输出参数
* param:    ElementType a[]  存储源数据的数组
* param:    int n            数组a的长度
* return:   void
*/
void CreateListR(LnkList* L, ElementType a[], int n)
{
	/*L = (LnkList*)malloc(sizeof(LnkList));*/
	L->next = NULL; // 将L置为头节点，其指针域初始化为NULL


	LnkList* pEnd = L; // 指向表尾节点的指针，先指向头结点
	for (int i = 0; i < n; ++i)
	{
		LnkList* ptr = (LnkList*)malloc(sizeof(LnkList));
		ptr->data = a[i];
		pEnd->next = ptr;
		pEnd = ptr;
	}
	pEnd->next = NULL; // 最后将尾节点的next置空，重要
}

/**
* brief:    初始化单链表
* method:   InitList
* param:    LnkList * L
* return:   void
*/
void InitList(LnkList* L)
{
	/*LnkList* */L = (LnkList*)malloc(sizeof(LnkList));
	L->next = NULL;
}

/**
* brief:    需要销毁所有节点的空间
* method:   DestoryList
* param:    LnkList * L
* return:   void
*/
void DestoryList(LnkList* L)
{
	LnkList* first = L->next;

	while (first != NULL)
	{
		LnkList* second = first->next;
		free(first);
		first = second;
	}
	L->next = NULL;
}

/**
* brief:    判断单链表是否为空
* method:   ListEmpty
* param:    LnkList * L
* return:   bool
*/
bool ListEmpty(LnkList* L)
{
	return (L->next == NULL);
}

/**
* brief:    获取单链表的长度
* method:   ListLength
* param:    LnkList * L
* return:   bool
*/
bool ListLength(LnkList* L)
{
	LnkList* ptr = L->next;

	int count = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		++count;
	}

	return count;
}

/**
* brief:    输出单链表的所有元素
* method:   DispList
* param:    LnkList * L
* return:   void
*/
void DispList(LnkList* L)
{
	LnkList* ptr = L->next;

	while (ptr != NULL)
	{
		std::cout << ptr->data << std::endl;
		ptr = ptr->next;
	}
}

/**
* brief:    求单链表中逻辑位序（不包括头结点）为i的数据元素
* method:   GetElement
* param:    LnkList * L
* param:    int i           从头开始找，第i个位置
* param:    ElementType & e 输出参数，找到元素后赋给e
* return:   bool
*/
bool GetElement(LnkList* L, int i, ElementType& e)
{
	if (i < 0) return false; // 位置索引错误

	LnkList* ptr = L;
#if 1
	for (int n = 0; n < i; ++n)
	{
		if (ptr == NULL)
			break;
		ptr = ptr->next;
	}
#else
	int n = 0;
	while (n < i && ptr != NULL)
	{
		++n;
		ptr = ptr->next;
	}
#endif
	if (ptr != NULL)
	{
		e = ptr->data;
		return true;
	}
	else
	{
		return false;
	}
}

/**
* brief:    查找第一个值为e的元素的逻辑位序（不包括头结点），若这样的元素不存在，则返回值为0
* method:   LocateElement
* param:    LnkList * L
* param:    const ElementType e
* return:   int
*/
int LocateElement(LnkList* L, const ElementType& e)
{
	LnkList* ptr = L->next;
	int i = 0;
	while (ptr != NULL)
	{
		++i;
		if (ptr->data == e)
			return i;
		ptr = ptr->next;
	}
	return 0;
}

/**
* brief:    单链表中在第i的逻辑位序（不包括头结点）插入一个元素【该算法的时间复杂度为O(n)】
* method:   ListInsert
* param:    LnkList * L
* param:    int i
* param:    ElementType e
* return:   bool
*/
bool ListInsert(LnkList* L, int i, ElementType e)
{
	if (i < 1)
		return false;

	LnkList* ptr = L;
	// 找到原本逻辑位序为i-1的元素，此时n的初始值为1
	int n = 1;
	while (ptr->next != NULL && n < i)
	{
		ptr = ptr->next;
		++n;
	}

	if (ptr == NULL)
		return false;

	LnkList* ins = (LnkList*)malloc(sizeof(LnkList));
	ins->data = e;
	// 将e插入到该位置
	ins->next = ptr->next;
	ptr->next = ins;

	return true;
}

/**
* brief:    删除顺序表中逻辑位序（不包括头结点）为i的元素【该算法的时间复杂度为O(n)】
* method:   ListDelete
* param:    LnkList * L
* param:    int i
* param:    ElementType & e
* return:   bool
*/
bool ListDelete(LnkList* L, int i, ElementType& e)
{
	if (i < 1)
		return false;

	LnkList* ptr = L;
	// 找到原本逻辑位序为i-1的元素，此时n的初始值为1
	int n = 1;
	while (ptr->next != NULL && n < i)
	{
		ptr = ptr->next;
		++n;
	}

	if (ptr == NULL)
		return false;

	LnkList* pDlt = ptr->next;
	e = pDlt->data; // 将要删除的元素的data作为输出参数
	ptr->next = ptr->next->next;
	free(pDlt);

	return true;
}
