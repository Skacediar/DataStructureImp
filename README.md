# DataStructureImp
Brief: 个人数据结构学习记录以及各类型数据结构基础实现

## 线性表
Brief: 线性表特点及算法特性总结

### 一. 顺序表
	1. 数据密度为100%，具有随机存储特性，即表示其查找的时间复杂度为O(1)；
	2. 插入删除算法复杂度为O(n)；

### 二. 单链表
	0. 把存储数据信息的域称为数据域，把存储后继元素位置的域称为指针域。指针域中存储的信息被称为指针或链。数据域和指针域组成一个元素的存储映像，称之为节点；
	1. 当访问过一个节点后，只能接着访问其后继节点，而无法访问其前驱节点。该特点将深刻影响到单链表的算法设计（比如在需要释放其中某个节点时，需要采用多个指针进行配合操作）；
	2. 单链表查找的时间复杂度为O(n)；
	3. 插入节点和删除节点只需要修改相关节点的指针域，而不需要移动节点，时间复杂度为O(1)；
	4. 单链表可以带有头结点（虚拟节点），从头结点的后继节点开始存储数据。带有头结点的单链表中，第一个节点的操作和所有节点的操作同一，且空表和非空表的操作统一；
	5. 建立单链表的方法通常有两种：头插法和尾插法。前者仅需一个指针，将节点插入已有节点和头结点之间，生成的单链表和数据的逻辑顺序相反，而后者需要两个指针，单链表和数据的逻辑顺序相同；

