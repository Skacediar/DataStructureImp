#pragma once

#include <iostream>
#include <stdlib.h>

#define MAXSIZE 20		 // �洢�ռ��ʼ���䳤��
typedef int ElementType; // ElementType�ݶ�Ϊint����

/*
 * Brief:	һ�����Ա��˳��ṹ����ʵ��
 * Author:  zengxt
 * Begin:   2020��7��30�� 22:30:37
 */
struct SeqList
{
	ElementType data[MAXSIZE];
	int			length;
};

/**
 * Brief:	  ���崴��˳���
 * Method:    CreateList
 * Returns:   void
 * Parameter: SeqList * L		˳����ָ��
 * Parameter: ElementType a[]	Դ����
 * Parameter: int n				����a�ĳ���
 */
void CreateList(SeqList* L, ElementType a[], int n)
{
	L = (SeqList*)malloc(sizeof(SeqList));
	for (int i = 0; i < n; ++i)
		L->data[i] = a[i];
	L->length = n;
}

/**
 * Brief:	  ��ʼ��˳���
 * Method:    InitList
 * Returns:   void
 * Parameter: SeqList * L
 */
void InitList(SeqList* L)
{
	L = (SeqList*)malloc(sizeof(SeqList));
	L->length = 0;
}

/**
 * Brief:	  ����˳���
 * Method:    DestorySeqList
 * Returns:   void
 * Parameter: SeqList * L
 */
void DestorySeqList(SeqList* L)
{
	free(L);
}

/**
 * Brief:	  �ж�˳����Ƿ�Ϊ��
 * Method:    ListEmpty
 * Returns:   bool
 * Parameter: SeqList * L
 */
bool ListEmpty(SeqList* L)
{
	return (L->length == 0);
}

/**
 * Brief:	  ��ȡ˳�����
 * Method:    ListLength
 * Returns:   int
 * Parameter: SeqList * L
 */
int ListLength(SeqList* L)
{
	return L->length;
}

/**
 * Brief:	  չʾ˳��������Ԫ��
 * Method:    DispList
 * Returns:   void
 * Parameter: SeqList * L
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
 * Brief:	  ��˳����е�i��Ԫ�ص�ֵ�������������e
			  ���㷨��ʱ�临�Ӷ�ΪO(1)��������˳���������ȡ����
 * Method:    GetElement
 * Returns:   bool
 * Parameter: SeqList * L
 * Parameter: int i				�߼����
 * Parameter: ElementType & e	�������
 */
bool GetElement(SeqList* L, int i, ElementType& e)
{
	if (i<1 || i > L->length) return false;
	e = L->data[i - 1];
	return true;
}

/**
 * Brief:	  ���ҵ�һ��ֵΪe��Ԫ�ص��߼�λ����������Ԫ�ز����ڣ��򷵻�ֵΪ0
 * Method:    LocateElement
 * Returns:   int
 * Parameter: SeqList * L
 * Parameter: ElementType e
 */
int LocateElement(SeqList* L, ElementType e)
{
#if 1
	for (int i = 0; i < L->length; ++i)
	{
		if (L->data[i] == e)
			return i + 1; // �߼�λ�� = �±� + 1
	}
	return 0;
#else
	int i = 0;
	while (i < L->length && L->data[i] != e)
		++i;
	if (i >= L->length)
		return 0;
	else
		return i + 1; // �߼�λ�� = �±� + 1
#endif
}

/**
 * Brief:	  ˳������ڵ�i���߼�λ�����һ��Ԫ��
			  ���㷨��ʱ�临�Ӷ�ΪO(n)
 * Method:    ListInsert
 * Returns:   bool
 * Parameter: SeqList * L
 * Parameter: int i
 * Parameter: ElementType e
 */
bool ListInsert(SeqList* L, int i, ElementType e)
{
	if (i < 1 || i > L->length + 1 || L->length == MAXSIZE) // length+1������length+1�����Բ����λ��
		return false;

	--i; // ���߼�λ��ת��Ϊ����λ�򣨼��±꣩
	if (i != L->length + 1) // �жϲ���λ���Ƿ��ڱ�β
	{
		for (int j = L->length - 1; j >= i; --j) // j��ΪL�ĽǱ꣬��β����ǰ������i
			L->data[j + 1] = L->data[j]; // ��ʼ�жϹ�˳���ĳ����Ƿ�ﵽ������Դ˴�����Խ��
	}
	L->data[i] = e; // ����Ԫ��e
	L->length++;

	return true;
}

/**
 * Brief:	  ɾ��˳������߼�λ��Ϊi��Ԫ��
			  ���㷨��ʱ�临�Ӷ�ΪO(n)
 * Method:    ListDelete
 * Returns:   bool
 * Parameter: SeqList * L
 * Parameter: int i
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
