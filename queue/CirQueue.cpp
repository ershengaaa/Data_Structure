#include <iostream>
using namespace std;

const int MAXSIZE = 1000;

template <class DataType>
class CirQueue {
public:
	CirQueue();  //��ʼ�� 
	~CirQueue() {} //���� 
	bool QueueEmpty(); //�ж϶����Ƿ�Ϊ�� 
	int QueueLength(); //���г��� 
	DataType GetHead();  //�õ�����ͷ�� 
	void EnQueue(DataType e);  //��� 
	DataType DeQueue(); //���� 
private:
	DataType data[MAXSIZE];
	int front, rear;  //��ͷ����βָ�� 
};

template <class DataType>
CirQueue<DataType>::CirQueue() {
	front = rear = 0;
}

template <class DataType>
bool CirQueue<DataType>::QueueEmpty() {
	return front == rear;
}

template <class DataType>
int CirQueue<DataType>::QueueLength() {
	return (rear - front + MAXSIZE) % MAXSIZE;
}

template <class DataType>
DataType CirQueue<DataType>::GetHead() {
	if (rear == front)
		throw "underflow";
	int i = (front + MAXSIZE) % MAXSIZE;
	return data[i];
}

template <class DataType>
void CirQueue<DataType>::EnQueue(DataType e) {
	if ((rear + 1) % MAXSIZE == front)
		throw "overflow";
	data[rear] = e;
	rear = (rear + 1) % MAXSIZE;
}

template <class DataType>
DataType CirQueue<DataType>::DeQueue() {
	if (rear == front)
		throw "underflow";
	DataType tmp = data[front];
	front = (front + 1) % MAXSIZE;
	return tmp;
}

int main(int argc, char** argv) {
	CirQueue<int> cq;
	cq.EnQueue(2);
	cq.EnQueue(5);
	if (cq.QueueEmpty())
		cout << "Queue empty" << endl;
	else
		cout << "Queue not empty" << endl;
	cout << "The queue length: " << cq.QueueLength() << endl;
	cout << "The queue head: " << cq.GetHead() << endl;
	cq.DeQueue();
	cout << "The queue length: " << cq.QueueLength() << endl;
	cout << "The queue head: " << cq.GetHead() << endl;
	return 0;
}
