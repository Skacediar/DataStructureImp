#pragma once

#include <iostream>
#include <stdlib.h>

typedef int ElementType;

/*
 * brief:   ������Ľڵ�ṹ��һ��������ڵ��У���Ҫ�洢���ݣ��Լ�ָ���̽ڵ��ָ�룬�������в���LΪͷ��㡿
 * author:  zengxt
 * begin:   2020��7��31��23:40:44
 */
struct LnkListNode
{
	ElementType  data; // ������
	LnkListNode* next; // ָ����
};
typedef LnkListNode LnkList;

/**
* brief:    ͷ�巨����
* method:   CreateListF
* param:    LnkList * L      �����ĵ������������
* param:    ElementType a[]  �洢Դ���ݵ�����
* param:    int n            ����a�ĳ���
* return:   void
*/
void CreateListF(LnkList* L, ElementType a[], int n)
{
	/*LnkList* L = (LnkList*)malloc(sizeof(LnkList));*/
	L->next = NULL; // ��L��Ϊͷ�ڵ㣬��ָ�����ʼ��ΪNULL

	for (int i = 0; i < n; ++i)
	{
		LnkList* ptr = (LnkList*)malloc(sizeof(LnkList));
		ptr->data = a[i];
		ptr->next = L->next;
		L->next = ptr;
	}
}

/**
* brief:    β�巨����
* method:   CreateListR
* param:    LnkList * L      �����ĵ������������
* param:    ElementType a[]  �洢Դ���ݵ�����
* param:    int n            ����a�ĳ���
* return:   void
*/
void CreateListR(LnkList* L, ElementType a[], int n)
{
	/*L = (LnkList*)malloc(sizeof(LnkList));*/
	L->next = NULL; // ��L��Ϊͷ�ڵ㣬��ָ�����ʼ��ΪNULL


	LnkList* pEnd = L; // ָ���β�ڵ��ָ�룬��ָ��ͷ���
	for (int i = 0; i < n; ++i)
	{
		LnkList* ptr = (LnkList*)malloc(sizeof(LnkList));
		ptr->data = a[i];
		pEnd->next = ptr;
		pEnd = ptr;
	}
	pEnd->next = NULL; // ���β�ڵ��next�ÿգ���Ҫ
}

/**
* brief:    ��ʼ��������
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
* brief:    ��Ҫ�������нڵ�Ŀռ�
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
* brief:    �жϵ������Ƿ�Ϊ��
* method:   ListEmpty
* param:    LnkList * L
* return:   bool
*/
bool ListEmpty(LnkList* L)
{
	return (L->next == NULL);
}

/**
* brief:    ��ȡ������ĳ���
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
* brief:    ��������������Ԫ��
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
* brief:    ���������߼�λ�򣨲�����ͷ��㣩Ϊi������Ԫ��
* method:   GetElement
* param:    LnkList * L
* param:    int i           ��ͷ��ʼ�ң���i��λ��
* param:    ElementType & e ����������ҵ�Ԫ�غ󸳸�e
* return:   bool
*/
bool GetElement(LnkList* L, int i, ElementType& e)
{
	if (i < 0) return false; // λ����������

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
* brief:    ���ҵ�һ��ֵΪe��Ԫ�ص��߼�λ�򣨲�����ͷ��㣩����������Ԫ�ز����ڣ��򷵻�ֵΪ0
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
* brief:    ���������ڵ�i���߼�λ�򣨲�����ͷ��㣩����һ��Ԫ�ء����㷨��ʱ�临�Ӷ�ΪO(n)��
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
	// �ҵ�ԭ���߼�λ��Ϊi-1��Ԫ�أ���ʱn�ĳ�ʼֵΪ1
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
	// ��e���뵽��λ��
	ins->next = ptr->next;
	ptr->next = ins;

	return true;
}

/**
* brief:    ɾ��˳������߼�λ�򣨲�����ͷ��㣩Ϊi��Ԫ�ء����㷨��ʱ�临�Ӷ�ΪO(n)��
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
	// �ҵ�ԭ���߼�λ��Ϊi-1��Ԫ�أ���ʱn�ĳ�ʼֵΪ1
	int n = 1;
	while (ptr->next != NULL && n < i)
	{
		ptr = ptr->next;
		++n;
	}

	if (ptr == NULL)
		return false;

	LnkList* pDlt = ptr->next;
	e = pDlt->data; // ��Ҫɾ����Ԫ�ص�data��Ϊ�������
	ptr->next = ptr->next->next;
	free(pDlt);

	return true;
}
