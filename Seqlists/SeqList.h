const int MaxSize = 100;
template<class DataType>
class SeqList
{
public:
	SeqList() { length = 0; }			// 无参构造，建立一个空的顺序表
	SeqList(DataType a[], int n);	// 有参构造，建立长度为n的顺序表
	~SeqList() {}					// 析构函数
	int Length(){ return length; }	// 求线性表的长度
	DataType Get(int i);			// 求表的第i个元素
	int Locate(DataType x);         // 按值查找x值的元素
	void Insert(int i, DataType x); // 添加元素
	DataType Delete(int i);			// 删除第i个元素
	void PrintList();				// 遍历操作，按序号输出元素
private:
	DataType data[MaxSize];			// 存放数据元素的数组
	int length;						// 线性表长度

};

template<class DataType>
SeqList<DataType>::SeqList(DataType a[], int n)  // 有参构造，建立长度为n的顺序表
{
	if (n > MaxSize)throw "参数非法";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	PrintList();
	length = n;
};

template<class DataType>
DataType SeqList<DataType>::Get(int i) // 顺序表按位查找算法Get
{

	if (i<1 && i>length)throw "查找位置非法";
	else return data[i - 1];

};

template<class DataType>
int SeqList<DataType>::Locate(DataType x) // 按值查找x值的元素
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x)
			return i + 1; // 下标为i的元素等于x，返回序号i+1
		return 0;         // 退出查询，查询失败
	}
};

template<class DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
	if (length >= MaxSize)throw "上溢";
	if (i<1 || i>length + 1) throw "位置";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1];		// 注意第j个元素存在数组j-1的下标处
	data[i - 1] = x;
	length++;
};
template<class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if (length == 0)throw "下溢出";
	if (i<1 || i>length)throw "位置";
	DataType x = data[i - 1];			// 取出i位置的元素
	for (int j = i; j < length; j++)
		// 用后元素替换前元素，进而有一个元素缺失，即可做到删除
		data[j - 1] = data[j];         // j是元素所在的下标
	length--;
	return x;
}

template<class DataType>
void SeqList<DataType>::PrintList()
{
	for (int i = 0; i < length; i++)
		cout << data[i]<<" ";
	cout <<endl;
}