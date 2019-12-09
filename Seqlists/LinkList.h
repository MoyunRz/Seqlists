#pragma once
#include "Node.h"
template <class DataType>
class LinkList
{
public:
	LinkList();                       // �޲ι���
	LinkList(DataType a[], int n);    // �вι��죬������n��Ԫ�ص�����
	~LinkList();                      // ��������
	int Length();                     // ������ĳ���
	DataType Get(int i);              // ��ȡָ��λ�õ�ֵ
	int Locate(DataType x);           // ��ֵ����
	void Insert(int i,DataType x);    // ����Ԫ��
	DataType Delete(int i);           // ɾ��Ԫ��
	void PrintList();                 // ��ӡ�������

private:
	Node<DataType>* first;            // �������ͷָ��
};

template <class DataType>
void LinkList<DataType>::PrintList()
{
	Node<DataType>* p = first->next; // ��ʼ��ָ��
	while (p!=NULL) 
	{
		cout << p->data;
		p = p->next;
	}
};
template <class DataType>
int LinkList<DataType>::Length()
{
	Node<DataType>* p = first->next;                  // ����ָ��p
	int count = 0;                    // �ۼ�����ʼ��   
	while (p!=NULL)
	{
		p = p->next;
		count++;
	}
	return count;                    // ע��count �ĳ�ʼ���ͷ���ֵ֮��Ĺ�ϵ  
};

template <class DataType>
DataType LinkList<DataType>::Get(int i)
{
	Node<DataType>* p = first->next;                      // ����ָ��p
	int count = 1;                        // �ۼ�����ʼ��   
	while (p!=NULL&&count<i) 
	{
		p = p->next;                      // ָ����һ����
		count++;
	}
	if (p == NULL)throw "λ��";          // �׳��쳣
	else return p->data;
};
template<class DataType>
int LinkList<DataType>::Locate(DataType x) // ��ֵ����λ��
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
	if (p == NULL)throw "λ��";
	else
	{
		Node<DataType>* s = new Node<DataType>;               // ����һ���ڵ�
		s->data = x;                // ���ڵ㸳ֵ   
		s->next = p->next;          // s���¸��ڵ���pԭ���Ľڵ�
		p->next = s;                // pԭ�����¸��ڵ�ָ��s ���Դ���������
	}
};

template<class DataType>
LinkList<DataType>::LinkList() 
{
	first = new Node<DataType>;          // ����ͷ�ڵ�
	first->data = NULL;        // ͷ�ڵ��ָ�����ÿ�
}

	/**
	ͷ�巨����������
	**/
template<class DataType>
LinkList<DataType>::LinkList(DataType a[],int n) 
{
	first = new Node<DataType>;                  // ��������
	first->next = NULL;                 // ��ʼ��������
	for (int i = 0; i < n; i++)
	{
		Node<DataType>* s = new Node<DataType>;
		s->data = a[i];                // Ϊÿ������Ԫ�ؽ���һ���ڵ�
		s->next = first->next;         // �ڵ�s���¸���̳�first�ģ�Ҳ�����滻
		first->next = s;               // ���ڵ�s���ڱ�ͷ֮��
	}
}
/**
	β�巨����������
	**/
/**
template <class DataType>
LinkList<DataType>::LinkList(DataType a[], int n)
{
	first = new Node;                      // ����ͷ�ڵ�
	Node<DataType>* r = first;             // β�ڵ�ָ���ʼ��
	for(int i = 0; i < n; i++)
	{
		Node<DataType>* s = new Node;
		s->data = a[i];                    // Ϊÿ�����齨��һ���ڵ�
		r->next = s;
		r = s;							   // ��ÿ���ڵ�s���뵽�ն˽ڵ�֮��
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
	if (p == NULL || p->next == NULL)throw "λ��";
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
	 while (first != NULL)              // �ͷ�ÿ������Ĵ洢�ռ�
	 {
		 Node<DataType>* q = first;     // �ݴ�ռ�ڵ�
		 first = first->next;           //  firstָ���ͷŵ��¸��ڵ�
		 delete q;
	 }
}