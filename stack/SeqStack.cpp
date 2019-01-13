#include <iostream>
using namespace std;

const int MAXSIZE = 1000;

template <class DataType>
class SeqStack {
public:
	SeqStack() {   //Ĭ�Ϲ��캯����ʼ��
		length = 0;
		top = -1;
	}
	~SeqStack() {}  //����
	bool StackEmpty() {return top == -1;}  //�ж�ջ�Ƿ�Ϊ��
	int StackLength() {return length;}   //ջ��Ԫ�ظ���
	DataType GetTop();   //���ջ��Ԫ��
	void push(DataType e);  //��ջ
	DataType pop();   //��ջ�����س�ջԪ��
private:
	DataType data[MAXSIZE];   //�洢ջԪ��
	int top;     //ջָ�룬ָ��ջ��
	int length;  //ջ�ĳ���
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
