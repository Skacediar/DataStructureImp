#pragma once

/*
 * Brief:   һ�����Ա����ʽ�ṹ����ʵ��
			һ�������У���Ҫ�洢���ݣ��Լ�ָ����һ���ڵ��ָ��
 * Author:  zengxt
 * Begin:   2020��7��31�� 23:40:44
 */
template<class ElementType>
struct LnkList
{
	ElementType data;
	LnkList* next;
};

