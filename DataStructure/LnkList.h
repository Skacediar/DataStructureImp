#pragma once

/*
 * Brief:   一个线性表的链式结构具体实现
			一个链表中，需要存储数据，以及指向下一个节点的指针
 * Author:  zengxt
 * Begin:   2020年7月31日 23:40:44
 */
template<class ElementType>
struct LnkList
{
	ElementType data;
	LnkList* next;
};

