#pragma once
template <class DataType>
struct Node
{
	DataType data;			 // ����
	Node<DataType>* next;	 // ��һ����ָ����
};