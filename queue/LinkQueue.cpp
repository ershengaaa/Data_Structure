#include <iostream>
using namespace std;

//�ڵ� 
template <class DataType>
struct Node {
	DataType data;
	Node *next;   
};

template <class DataType>
class LinkQueue {
public:
	LinkQueue();  //��ʼ�� 
	~LinkQueue();  //���� 
	bool QueueEmpty();  //�ж϶����Ƿ�Ϊ�� 
	int QueueLength();  //���г��� 
	DataType GetHead();  //��ͷ 
	void EnQueue(DataType e);  //��� 
	DataType DeQueue();  //���� 
private:
	Node<DataType> *front, *rear; //��ͷ����βָ�� 
	int length;   //���г��� 
};

template <class DataType>
LinkQueue<DataType>::LinkQueue() {
	Node<DataType> *p = new Node<DataType>;
	p->next = NULL;
	front = rear = p;
	length = 0;
}

template <class DataType>
LinkQueue<DataType>::~LinkQueue() {
	while (front->next != NULL) {
		Node<DataType> *p = front->next;
		front->next = p->next;
		delete p;
	}
}

template <class DataType>
bool LinkQueue<DataType>::QueueEmpty() {
	return front == rear;
	//return length == 0;
}

template <class DataType>
int LinkQueue<DataType>::QueueLength() {
	return length;
}

template <class DataType>
DataType LinkQueue<DataType>::GetHead() {
	if (rear == front)
		throw "underflow";
	DataType tmp = front->next->data;
	return tmp;
}

template <class DataType>
void LinkQueue<DataType>::EnQueue(DataType e) {
	Node<DataType> *p = new Node<DataType>;
	p->data = e;
	p->next = NULL;
	rear->next = p;
	rear = p;
	++length;
}

template <class DataType>
DataType LinkQueue<DataType>::DeQueue() {
	if (front == rear)
		throw "underflow";
	DataType tmp = front->next->data;
	Node<DataType> *p = front;
	front = front->next;
	delete p;
	--length;
	return tmp;
}

int main(int argc, char** argv) {
	LinkQueue<int> lq;
	lq.EnQueue(5);
	lq.EnQueue(4);
	if (lq.QueueEmpty())
		cout << "Queue empty" << endl;
	else
		cout << "Queue not empty" << endl;
	cout << "The queue length: " << lq.QueueLength() << endl;
	cout << "The queue head: " << lq.GetHead() << endl;
	lq.DeQueue();
	cout << "The queue length: " << lq.QueueLength() << endl;
	cout << "The queue head: " << lq.GetHead() << endl;
	return 0;
}
