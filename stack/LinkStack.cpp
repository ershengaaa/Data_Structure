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
	LinkStack(); //初始化
	~LinkStack(); //有指针需要析构操作
	bool StackEmpty() {return top == NULL;} //判断栈是否为空
	int StackLength() {return length;} //得到栈的长度
	DataType GetTop(); //得到栈顶元素
	void push(DataType e); //进栈
	DataType pop();  //出栈
private:
	Node<DataType> *top; //节点指针
	int length; //栈长度
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
