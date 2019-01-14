#include <iostream>
using namespace std;

//节点 
template <class DataType>
struct Node {
	DataType data;
	Node *next;   
};

template <class DataType>
class LinkQueue {
public:
	LinkQueue();  //初始化 
	~LinkQueue();  //析构 
	bool QueueEmpty();  //判断队列是否为空 
	int QueueLength();  //队列长度 
	DataType GetHead();  //队头 
	void EnQueue(DataType e);  //入队 
	DataType DeQueue();  //出队 
private:
	Node<DataType> *front, *rear; //队头、队尾指针 
	int length;   //队列长度 
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
