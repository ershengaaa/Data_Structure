#include <iostream>
using namespace std;

const int MAXSIZE = 1000;

template <class DataType>
class SeqStack {
public:
	SeqStack() {   //默认构造函数初始化
		length = 0;
		top = -1;
	}
	~SeqStack() {}  //析构
	bool StackEmpty() {return top == -1;}  //判断栈是否为空
	int StackLength() {return length;}   //栈中元素个数
	DataType GetTop();   //获得栈顶元素
	void push(DataType e);  //进栈
	DataType pop();   //出栈，返回出栈元素
private:
	DataType data[MAXSIZE];   //存储栈元素
	int top;     //栈指针，指向栈顶
	int length;  //栈的长度
};

template <class DataType>
DataType SeqStack<DataType>::GetTop() {
	if (top != -1)
		return data[top];
	else
		throw "non-number";
}

template <class DataType>
void SeqStack<DataType>::push(DataType e) {
	if (top == MAXSIZE - 1)
		throw "overflow";
	data[++top] = e;
	++length;
}

template <class DataType>
DataType SeqStack<DataType>::pop() {
	if (top == -1)
		throw "underflow";
	DataType tmp = data[top];
	--top;
	--length;
	return tmp;
}

int main(int argc, char** argv) {
	SeqStack<int> sq;
	sq.push(2);
	sq.push(4);
	sq.push(6);
	sq.push(8);
	if (sq.StackEmpty())
		cout << "Stack Empty" << endl;
	else
		cout << "Stack Not Empty" << endl;
	cout << "stack length: "<< sq.StackLength() << endl;
	cout << "the top: " << sq.GetTop() << endl;
	sq.pop();
	sq.pop();
	cout << "the top: " << sq.GetTop() << endl;
	return 0;
}
