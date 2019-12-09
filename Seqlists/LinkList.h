#pragma once
#include "Node.h"
template <class DataType>
class LinkList
{
public:
	LinkList();                       // 无参构造
	LinkList(DataType a[], int n);    // 有参构造，建立有n个元素的链表
	~LinkList();                      // 析构函数
	int Length();                     // 求单链表的长度
	DataType Get(int i);              // 获取指定位置的值
	int Locate(DataType x);           // 按值查找
	void Insert(int i,DataType x);    // 插入元素
	DataType Delete(int i);           // 删除元素
	void PrintList();                 // 打印输出链表

private:
	Node<DataType>* first;            // 单链表的头指针
};

template <class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType>* p = first->next; // 初始化指针
	while (p!=NULL) 
	{
		cout << p->data;
		p = p->next;
	}
};
template <class DataType>
int LinkList<DataType>::Length()
{
	Node<DataType>* p = first->next;                  // 工作指针p
	int count = 0;                    // 累加器初始化   
	while (p!=NULL)
	{
		p = p->next;
		count++;
	}
	return count;                    // 注意count 的初始化和返回值之间的关系  
};

template <class DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType>* p = first->next;                      // 工作指针p
	int count = 1;                        // 累加器初始化   
	while (p!=NULL&&count<i) 
	{
		p = p->next;                      // 指向下一个域
		count++;
	}
	if (p == NULL)throw "位置";          // 抛出异常
	else return p->data;
};
template<class DataType>
int LinkList<DataType>::Locate(DataType x) // 按值查找位置
{
	Node<DataType>* p = first->next;
	int count = 1;
	while (p != NULL)
	{
		if (p->data == x) return count;
		p = p->next;
		count++;
	}
	return 0;
};

template <class DataType>
void LinkList<DataType>::Insert(int i, DataType x)
{
	Node<DataType>* p = first;
	int count = 0;
	while (p != NULL && count < i - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)throw "位置";
	else
	{
		Node<DataType>* s = new Node<DataType>;               // 申请一个节点
		s->data = x;                // 给节点赋值   
		s->next = p->next;          // s的下个节点是p原来的节点
		p->next = s;                // p原来的下个节点指向s ，以此做到插入
	}
};

template<class DataType>
LinkList<DataType>::LinkList() 
{
	first = new Node<DataType>;          // 生成头节点
	first->data = NULL;        // 头节点的指针域置空
}

	/**
	头插法建立单链表
	**/
template<class DataType>
LinkList<DataType>::LinkList(DataType a[],int n) 
{
	first = new Node<DataType>;                  // 建立链表
	first->next = NULL;                 // 初始化空链表
	for (int i = 0; i < n; i++)
	{
		Node<DataType>* s = new Node<DataType>;
		s->data = a[i];                // 为每个数组元素建立一个节点
		s->next = first->next;         // 节点s的下个域继承first的，也就是替换
		first->next = s;               // 将节点s放在表头之后
	}
}
/**
	尾插法建立单链表
	**/
/**
template <class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	first = new Node;                      // 生成头节点
	Node<DataType>* r = first;             // 尾节点指针初始化
	for(int i = 0; i < n; i++)
	{
		Node<DataType>* s = new Node;
		s->data = a[i];                    // 为每个数组建立一个节点
		r->next = s;
		r = s;							   // 将每个节点s插入到终端节点之后
	}
	r->next = NULL;
}
**/
template <class DataType>
DataType LinkList<DataType>::Delete(int i)
{
	Node<DataType>* p = first;
	int count = 0;
	while (p!=NULL&&count<i-1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL)throw "位置";
	else
	{
		Node<DataType>* q = p->next;
		DataType x = q->data;
		p->next = q->next;
		delete q;
		return x;
	}
}

template <class DataType>
 LinkList<DataType>::~LinkList()
{
	 while (first != NULL)              // 释放每个链表的存储空间
	 {
		 Node<DataType>* q = first;     // 暂存空间节点
		 first = first->next;           //  first指向被释放的下个节点
		 delete q;
	 }
}