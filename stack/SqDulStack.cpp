#include <iostream>
using namespace std;

//通过StackNumber判断操作哪个栈
const int MAXSIZE = 1000;

template <class DataType>
class SqDulStack {
public:
	SqDulStack();  //默认初始化
	~SqDulStack() {}
	bool StackEmpty(int StackNumber); //判断栈1/栈2是否为空
	int StackLength(int StackNumber); //得到栈1/栈2的长度
	DataType GetTop(int StackNumber); //得到栈1/栈2的栈顶元素
	void push(int StackNumber, DataType e); //选择栈1/栈2进栈
	DataType pop(int StackNumber); //栈1/栈2出栈
private:
	DataType data[MAXSIZE]; //整个存储空间
	int top1, top2;  //栈1/栈2栈顶指针
	int length1, length2; //栈1/栈2长度
};

template <class DataType>
bool SqDulStack<DataType>::StackEmpty(int StackNumber) {
	if (StackNumber == 1)
		return length1 == 0;
	else
		return length2 == 0;
}

template < class DataType>
int SqDulStack<DataType>::StackLength(int StackNumber) {
	if (StackNumber == 1)
		return length1;
	else
		return length2;
}

template <class DataType>
DataType SqDulStack<DataType>::GetTop(int StackNumber) {
	if (StackNumber == 1) {
		if (top1 == -1)
			throw "Stack1 empty";
		else
			return data[top1];
	}
	else {
		if (top2 == MAXSIZE)
			throw "Stack2 empty";
		else
			return data[top2];
	}
}

template <class DataType>
void SqDulStack<DataType>::push(int StackNumber, DataType e) {
	if (top1 + 1 == top2)
		throw "overflow";
	if (StackNumber == 1) {
		data[++top1] = e;
		++length1;
	}
	if (StackNumber == 2) {
		data[--top2] = e;
		++length2;
	}
}

template <class DataType>
DataType SqDulStack<DataType>::pop(int StackNumber) {
	if (StackNumber == 1){
		if (top1 == -1)
			throw "underflow";
		DataType tmp = data[top1];
		--top1;
		--length1;
		return tmp;
	}
	else{
		if (top2 == MAXSIZE)
			throw "underflow";
		DataType tmp = data[top2];
		++top2;
		--length2;
		return tmp;
	}
}

int main(int argc, char** argv) {
	SqDulStack<int> sdq;
	sdq.push(1,2);
	sdq.push(2,3);
	sdq.push(1,5);
	sdq.push(2,6);
	if (sdq.StackEmpty(1))
		cout << "Stack1 empty" << endl;
	else
		cout << "Stack1 not empty" << endl;
	cout << "Stack1 length: " << sdq.StackLength(1) << endl;
	cout << "Stack2 length: " << sdq.StackLength(2) << endl;
	cout << "Stack1 top: " << sdq.GetTop(1) << endl;
	cout << "Stack2 top: " << sdq.GetTop(2) << endl;
	sdq.pop(1);
	sdq.pop(2);
	cout << "Stack1 top: " << sdq.GetTop(1) << endl;
	cout << "Stack2 top: " << sdq.GetTop(2) << endl;
	return 0;
}
