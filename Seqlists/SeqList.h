const int MaxSize = 100;
template<class DataType>
class SeqList
{
public:
	SeqList() { length = 0; }			// �޲ι��죬����һ���յ�˳���
	SeqList(DataType a[], int n);	// �вι��죬��������Ϊn��˳���
	~SeqList() {}					// ��������
	int Length(){ return length; }	// �����Ա�ĳ���
	DataType Get(int i);			// ���ĵ�i��Ԫ��
	int Locate(DataType x);         // ��ֵ����xֵ��Ԫ��
	void Insert(int i, DataType x); // ���Ԫ��
	DataType Delete(int i);			// ɾ����i��Ԫ��
	void PrintList();				// ������������������Ԫ��
private:
	DataType data[MaxSize];			// �������Ԫ�ص�����
	int length;						// ���Ա���

};

template<class DataType>
SeqList<DataType>::SeqList(DataType a[], int n)  // �вι��죬��������Ϊn��˳���
{
	if (n > MaxSize)throw "�����Ƿ�";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	PrintList();
	length = n;
};

template<class DataType>
DataType SeqList<DataType>::Get(int i) // ˳���λ�����㷨Get
{

	if (i<1 && i>length)throw "����λ�÷Ƿ�";
	else return data[i - 1];

};

template<class DataType>
int SeqList<DataType>::Locate(DataType x) // ��ֵ����xֵ��Ԫ��
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x)
			return i + 1; // �±�Ϊi��Ԫ�ص���x���������i+1
		return 0;         // �˳���ѯ����ѯʧ��
	}
};

template<class DataType>
void SeqList<DataType>::Insert(int i, DataType x)
{
	if (length >= MaxSize)throw "����";
	if (i<1 || i>length + 1) throw "λ��";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1];		// ע���j��Ԫ�ش�������j-1���±괦
	data[i - 1] = x;
	length++;
};
template<class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if (length == 0)throw "�����";
	if (i<1 || i>length)throw "λ��";
	DataType x = data[i - 1];			// ȡ��iλ�õ�Ԫ��
	for (int j = i; j < length; j++)
		// �ú�Ԫ���滻ǰԪ�أ�������һ��Ԫ��ȱʧ����������ɾ��
		data[j - 1] = data[j];         // j��Ԫ�����ڵ��±�
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