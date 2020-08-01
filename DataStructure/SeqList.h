#pragma once

#include <iostream>
#include <stdlib.h>

#define MAXSIZE 20       // 存储空间初始分配长度
typedef int ElementType; // ElementType暂定为int类型

/*
 * brief:   一个线性表的顺序结构具体实现
 * author:  zengxt
 * begin:   2020年7月30日22:30:37
 */
struct SeqList
{
	ElementType data[MAXSIZE];
	int			length;
};

/**
* brief:    整体创建顺序表
* method:   CreateList
* param:    SeqList * L      顺序表的指针
* param:    ElementType a[]  源数组
* param:    int n            数组a的长度
* return:   void
*/
void CreateList(SeqList* L, ElementType a[], int n)
{
	L = (SeqList*)malloc(sizeof(SeqList));
	for (int i = 0; i < n; ++i)
		L->data[i] = a[i];
	L->length = n;
}

/**
* brief:    初始化顺序表
* method:   InitList
* param:    SeqList * L
* return:   void
*/
void InitList(SeqList* L)
{
	L = (SeqList*)malloc(sizeof(SeqList));
	L->length = 0;
}

/**
* brief:    销毁顺序表
* method:   DestorySeqList
* param:    SeqList * L
* return:   void
*/
void DestorySeqList(SeqList* L)
{
	free(L);
}

/**
* brief:    判断顺序表是否为空
* method:   ListEmpty
* param:    SeqList * L
* return:   bool
*/
bool ListEmpty(SeqList* L)
{
	return (L->length == 0);
}

/**
* brief:    获取顺序表长度
* method:   ListLength
* param:    SeqList * L
* return:   int
*/
int ListLength(SeqList* L)
{
	return L->length;
}

/**
* brief:    展示顺序表的所有元素
* method:   DispList
* param:    SeqList * L
* return:   void
*/
void DispList(SeqList* L)
{
	if (ListEmpty(L)) return;

	for (int i = 0; i < L->length; ++i)
	{
		std::cout << L->data[i] << std::endl;
	}
}

/**
* brief:    求顺序表中第i个元素的值，存入输出参数e【该算法的时间复杂度为O(1)，体现了顺序表的随机存取特性】
* method:   GetElement
* param:    SeqList * L
* param:    int i           逻辑序号
* param:    ElementType & e 输出参数
* return:   bool
*/
bool GetElement(SeqList* L, int i, ElementType& e)
{
	if (i<1 || i > L->length) return false;
	e = L->data[i - 1];
	return true;
}

/**
* brief:    查找第一个值为e的元素的逻辑位序，若这样的元素不存在，则返回值为0
* method:   LocateElement
* param:    SeqList * L
* param:    ElementType e
* return:   int
*/
int LocateElement(SeqList* L, ElementType e)
{
#if 1
	for (int i = 0; i < L->length; ++i)
	{
		if (L->data[i] == e)
			return i + 1; // 逻辑位序 = 下标 + 1
	}
	return 0;
#else
	int i = 0;
	while (i < L->length && L->data[i] != e)
		++i;
	if (i >= L->length)
		return 0;
	else
		return i + 1; // 逻辑位序 = 下标 + 1
#endif
}

/**
* brief:    顺序表中在第i的逻辑位序插入一个元素【该算法的时间复杂度为O(n)】
* method:   ListInsert
* param:    SeqList * L
* param:    int i
* param:    ElementType e
* return:   bool
*/
bool ListInsert(SeqList* L, int i, ElementType e)
{
	if (i < 1 || i > L->length + 1 || L->length == MAXSIZE) // length+1代表有length+1个可以插入的位置
		return false;

	--i; // 将逻辑位序转换为物理位序（即下标）
	if (i != L->length + 1) // 判断插入位置是否在表尾
	{
		for (int j = L->length - 1; j >= i; --j) // j即为L的角标，从尾部向前遍历至i
			L->data[j + 1] = L->data[j]; // 开始判断过顺序表的长度是否达到最大，所以此处不会越界
	}
	L->data[i] = e; // 插入元素e
	L->length++;

	return true;
}

/**
* brief:    删除顺序表中逻辑位序为i的元素【该算法的时间复杂度为O(n)】
* method:   ListDelete
* param:    SeqList * L
* param:    int i
* param:    ElementType & e
* return:   bool
*/
bool ListDelete(SeqList* L, int i, ElementType& e)
{
	if (i<1 || i>L->length) return false;

	--i;
	e = L->data[i];
	if (i != L->length - 1)
	{
		for (int j = i; j < L->length - 1; ++j)
			L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}
