#pragma once
template <class DataType>
struct Node
{
	DataType data;			 // 数据
	Node<DataType>* next;	 // 下一个的指针域
};