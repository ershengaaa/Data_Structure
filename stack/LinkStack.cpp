#include <iostream>
using namespace std;

template <class DataType>
struct Node {
	DataType data;
	Node<DataType> *next;
};

template <class DataType>
class LinkStack {
public:
	LinkStack(); //��ʼ��
	~LinkStack(); //��ָ����Ҫ��������
	bool StackEmpty() {return top == NULL;} //�ж�ջ�Ƿ�Ϊ��
	int StackLength() {return length;} //�õ�ջ�ĳ���
	DataType GetTop(); //�õ�ջ��Ԫ��
	void push(DataType e); //��ջ
	DataType pop();  //��ջ
private:
	Node<DataType> *top; //�ڵ�ָ��
	int length; //ջ����
};

template <class DataType>
LinkStack<DataType>::LinkStack() {
	top = NULL;
	length = 0;
}

template <class DataType>
LinkStack<DataType>::~LinkStack() {
	while (top) {
		Node<DataType> *p = top;
		top = top->next;
		delete p;
	}
}

template <class DataType>
DataType LinkStack<DataType>::GetTop() {
	if (top == NULL)
		throw "non-number";
	else
		return top->data;
}

template <class DataType>
void LinkStack<DataType>::push(DataType e) {
	Node<DataType> *p = new Node<DataType>;
	p->next = top;
	p->data = e;
	top = p;
	++length;
}

template <class DataType>
DataType LinkStack<DataType>::pop() {
	if (top == NULL)
		throw "underflow";
	Node<DataType> *p = top;
	DataType tmp = top->data;
	top = top->next;
	delete p;
	--length;
	return tmp;
}

int main(int argc, char** argv) {
	LinkStack<int> ls;
	ls.push(2);
	ls.push(5);
	ls.push(6);
	if (ls.StackEmpty())
		cout << "Stack Empty" << endl;
	else
		cout << "Stack Not Empty" << endl;
	cout << "stack length: "<< ls.StackLength() << endl;
	cout << "the top: " << ls.GetTop() << endl;
	ls.pop();
	ls.pop();
	cout << "the top: " << ls.GetTop() << endl;
}
