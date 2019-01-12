#include <iostream>
using namespace std;

const int MAXSIZE = 100;
template <class DataType>
class SeqList {
public:
	SeqList() {length = 0;}
	SeqList(DataType a[], int n);
	~SeqList(){}  //析构
	int Getlength() {return length;}  //获得线性表的长度
	bool listempty();      //判断线性表是否为空
	DataType GetElem(int i);   //获得第i个位置的元素
	int LocateElem(DataType e); //查找与给定值e相等的元素，找到则返回下标，否则返回0
	void Insert(int i, DataType e);  //在给定位置i插入元素e
	DataType Delete(int i);  //删除给定位置i的元素,并返回该值
	void PrintList(); //打印线性表
private:
	DataType data[MAXSIZE];
	int length;
};

template <class DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
	if (n > MAXSIZE)
		cout << "Excess length" << endl;
	for (int i = 0; i < n; ++i)
		data[i] = a[i];
	length = n;
}

template <class DataType>
bool SeqList<DataType>::listempty() {
	return length == 0;
}

template<class DataType>
DataType SeqList<DataType>::GetElem(int i) {
	if (i > length || i < 1 || length == 0)
		throw "wrong Location";
	return data[i - 1];
}

template <class DataType>
int SeqList<DataType>::LocateElem(DataType e) {
	if (length == 0)
		return 0;
	for (int i = 0; i < length; ++i) {
		if (data[i] == e)
			return i + 1;
	}
	return 0;
}

template <class DataType>
void SeqList<DataType>::Insert(int i, DataType e) {
	if (length >= MAXSIZE)
		throw "Overflow";
	if (i < 1 || i > length + 1)
		throw "wrong Location";
	if (i <= length) {
		for (int j = length; j >= i; --j)
			data[j] = data[j - 1];
	}
	data[i - 1] = e;
	++length;
}

template <class DataType>
DataType SeqList<DataType>::Delete(int i) {
	if (length == 0)
		throw "Underflow";
	if (i < 1 || i > length)
		throw "wrong Location";
	int tmp = data[i - 1];
	if (i < length) {
		for (int j = i - 1; j < length - 1; ++j)
			data[j] = data[j + 1];
	}
	--length;
	return tmp;
}

template <class DataType>
void SeqList<DataType>::PrintList() {
	if (length == 0)
		throw "list empty";
	for (int i = 0; i < length; ++i)
		cout << data[i] << " ";
	cout << endl;
}

int main(int argc, char** argv) {
	SeqList<int> q;
	if (q.listempty())
		cout << "list empty" << endl;
	else
		cout << "list not empty" << endl;

	int i, num;
	cin >> i >> num;
	q.Insert(1,1);
	q.Insert(2,2);
	q.Insert(3,5);
	q.Insert(4,4);
	q.Insert(5,8);
	cout << "The length of SeqList: " << q.Getlength() << endl;
	cout << "The " << i << "-th element: " << q.GetElem(i) << endl;
	if (q.LocateElem(num))
		cout << "num " << num << " locate " << q.LocateElem(num) << "-th" << endl;
	else
		cout << "locate wrong" << endl;
	q.PrintList();
	q.Delete(2);
	q.PrintList();
	return 0;
}
