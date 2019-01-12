#include <iostream>
using namespace std;

template <class DataType>
struct Node {
	DataType data;
	Node<DataType> *next;
};

template <class DataType>
class LinkList {
public:
	LinkList();
	LinkList(DataType a[], int n);
	~LinkList();   //析构
	int Getlength();  //获得单链表的长度
	bool listempty();      //判断单链表是否为空
	DataType GetElem(int i);   //获得第i个位置的元素
	int LocateElem(DataType e); //查找与给定值e相等的元素，找到则返回下标，否则返回0
	void Insert(int i, DataType e);  //在给定位置i插入元素e
	DataType Delete(int i);  //删除给定位置i的元素,并返回该值
	void PrintList(); //打印单链表
private:
	Node<DataType> *first;
};

template <class DataType>
LinkList<DataType>::LinkList() {
	first = new Node<DataType>;
	first->next = NULL;
}

template <class DataType>
LinkList<DataType>::LinkList(DataType a[], int n) {
	first = new Node<DataType>;
	first->next = NULL;
	for (int i = 0; i < n; ++i) {
		Node<DataType> *s = new Node<DataType>;
		s->data = a[i];
		s->next = first->next;
		first->next = s;
	}
}


template <class DataType>
LinkList<DataType>::~LinkList() {
	while (first != NULL) {
		Node<DataType> *p = first;
		first = first->next;
		delete p;
	}
}

template <class DataType>
int LinkList<DataType>::Getlength() {
	Node<DataType> *p = first->next;
	int count = 0;
	while (p) {
		++count;
		p = p->next;
	}
	return count;
}

template <class DataType>
bool LinkList<DataType>::listempty() {
	return first->next == NULL;
}

template<class DataType>
DataType LinkList<DataType>::GetElem(int i) {
	Node<DataType> *p = first->next;
	int count = 1;
	while (p && count < i) {
		p = p->next;
		++count;
	}
	if (p == NULL)
		throw "wrong Location";
	else
		return p->data;
}

template <class DataType>
int LinkList<DataType>::LocateElem(DataType e) {
	Node<DataType> *p = first->next;
	int count = 1;
	while (p) {
		if (p->data == e)
			return count;
		p = p->next;
		++count;
	}
	return 0;
}

template <class DataType>
void LinkList<DataType>::Insert(int i, DataType e) {
	Node<DataType> *p = first->next;
	int count = 0;
	while (p && count < i - 1) {
		p = p->next;
		++count;
	}
	if (p == NULL)
		throw "wrong Location";
	else {
		Node<DataType> *s = new Node<DataType>;
		s->next = p->next;
		p->next = s;
		s->data = e;
	}
}

template <class DataType>
DataType LinkList<DataType>::Delete(int i) {
	Node<DataType> *p = first->next;
	int count = 0;
	while (p && count < i - 1) {
		p = p->next;
		++count;
	}
	if (p == NULL) 
		throw "wrong Location";
	else {
		Node<DataType> *s = p->next;
		int tmp = s->data;
		p->next = s->next;
		return tmp;
	}
}

template <class DataType>
void LinkList<DataType>::PrintList() {
	Node<DataType> *p = first->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char** argv) {
	int a[] = {1,2};
	LinkList<int> q(a, 2);
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
	cout << "The length of LinkList: " << q.Getlength() << endl;
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
