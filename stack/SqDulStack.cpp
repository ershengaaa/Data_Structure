#include <iostream>
using namespace std;

//ͨ��StackNumber�жϲ����ĸ�ջ
const int MAXSIZE = 1000;

template <class DataType>
class SqDulStack {
public:
	SqDulStack();  //Ĭ�ϳ�ʼ��
	~SqDulStack() {}
	bool StackEmpty(int StackNumber); //�ж�ջ1/ջ2�Ƿ�Ϊ��
	int StackLength(int StackNumber); //�õ�ջ1/ջ2�ĳ���
	DataType GetTop(int StackNumber); //�õ�ջ1/ջ2��ջ��Ԫ��
	void push(int StackNumber, DataType e); //ѡ��ջ1/ջ2��ջ
	DataType pop(int StackNumber); //ջ1/ջ2��ջ
private:
	DataType data[MAXSIZE]; //�����洢�ռ�
	int top1, top2;  //ջ1/ջ2ջ��ָ��
	int length1, length2; //ջ1/ջ2����
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
