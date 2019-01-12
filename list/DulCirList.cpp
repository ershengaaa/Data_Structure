#include <iostream>
using namespace std;

template <class DataType>
struct DulCirNode {
	DataType data;
	DulCirNode<DataType> *prior,*next;
};

template <class DataType>
class DulCirLinkList {
public:
	DulCirLinkList();
	DulCirLinkList(DataType a[], int n);
	~DulCirLinkList();   //析构
	int Getlength();  //获得双向循环链表的长度
	bool listempty();      //判断双向循环链表是否为空
	DataType GetElem(int i);   //获得第i个位置的元素
	int LocateElem(DataType e); //查找与给定值e相等的元素，找到则返回下标，否则返回0
	void Insert(int i, DataType e);  //在给定位置i插入元素e
	DataType Delete(int i);  //删除给定位置i的元素,并返回该值
	void PrintList(); //打印双向链表
private:
	DulCirNode<DataType> *first;
};

template <class DataType>
DulCirLinkList<DataType>::DulCirLinkList() {
	first = new DulCirNode<DataType>;
	first->prior = first;
	first->next = first;
}

template <class DataType>
DulCirLinkList<DataType>::DulCirLinkList(DataType a[], int n) {
	first = new DulCirNode<DataType>;
	first->prior = first;
	first->next = first;
	for (int i = 0; i < n; ++i) {
		DulCirNode<DataType> *s = new DulCirNode<DataType>;
		s->data = a[i];
		s->next = first->next;
		first->next = s;
		first->next->prior = s;
		s->prior = first;
	}
}


template <class DataType>
DulCirLinkList<DataType>::~DulCirLinkList() {
	while (first->next != first) {
		DulCirNode<DataType> *p = first;
		first->prior->next = first->next;
		first = first->next;
		delete p;
	}
	delete first;
}

template <class DataType>
int DulCirLinkList<DataType>::Getlength() {
	DulCirNode<DataType> *p = first->next;
	int count = 0;
	while (p != first) {
		++count;
		p = p->next;
	}
	return count;
}

template <class DataType>
bool DulCirLinkList<DataType>::listempty() {
	return first->next == first;
}

template<class DataType>
DataType DulCirLinkList<DataType>::GetElem(int i) {
	DulCirNode<DataType> *p = first->next;
	int count = 1;
	while (p != first && count < i) {
		p = p->next;
		++count;
	}
	if (p == first && count != 1)
		throw "wrong Location";
	else
		return p->data;
}

template <class DataType>
int DulCirLinkList<DataType>::LocateElem(DataType e) {
	DulCirNode<DataType> *p = first->next;
	int count = 1;
	while (p != first) {
		if (p->data == e)
			return count;
		p = p->next;
		++count;
	}
	return 0;
}

template <class DataType>
void DulCirLinkList<DataType>::Insert(int i, DataType e) {
	DulCirNode<DataType> *p = first->next;
	int count = 0;
	while (p != first && count < i - 1) {
		p = p->next;
		++count;
	}
	if (p == first && count != 0)
		throw "wrong Location";
	else {
		DulCirNode<DataType> *s = new DulCirNode<DataType>;
		s->next = p->next;
		p->next = s;
		s->prior = p;
		p->next->prior = s;
		s->data = e;
	}
}

template <class DataType>
DataType DulCirLinkList<DataType>::Delete(int i) {
	DulCirNode<DataType> *p = first;
	int count = 0;
	while (p->next != first && count < i - 1) {
		p = p->next;
		++count;
	}
	if (p == first && count != 0) 
		throw "wrong Location";
	else {
		DulCirNode<DataType> *s = p->next;
		int tmp = s->data;
		p->next = s->next;
		p = s->next->prior;
		return tmp;
	}
}

template <class DataType>
void DulCirLinkList<DataType>::PrintList() {
	DulCirNode<DataType> *p = first->next;
	while (p != first) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char** argv) {
	int a[] = {1,2};
	DulCirLinkList<int> q(a, 2);
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
	cout << "The length of DulCirLinkList: " << q.Getlength() << endl;
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
