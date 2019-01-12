#include <iostream>
using namespace std;

#define MAXSIZE 1000
template <class DataType>
struct Node {
	DataType data;
	int  next;
};

template <class DataType>
class StaticList {
public:
	StaticList();
	StaticList(DataType a[], int n);
	~StaticList() {}   //����
	int Getlength() {return length;}//��þ�̬����ĳ���
	bool listempty();      //�жϾ�̬�����Ƿ�Ϊ��
	DataType GetElem(int i);   //��õ�i��λ�õ�Ԫ��
	int LocateElem(DataType e); //���������ֵe��ȵ�Ԫ�أ��ҵ��򷵻��±꣬���򷵻�0
	void Insert(int i, DataType e);  //�ڸ���λ��i����Ԫ��e
	DataType Delete(int i);  //ɾ������λ��i��Ԫ��,�����ظ�ֵ
	void PrintList(); //��ӡ��̬����
private:
	Node<DataType>  SList[MAXSIZE];  //�������������
	int length;  //������
	int avail;   //��������ָ������
};

template <class DataType>
StaticList<DataType>::StaticList() {
	length = 0;
	for (int i = 0; i < MAXSIZE - 1; ++i)
		SList[i].next = i + 1;
	SList[MAXSIZE - 1].next = -1;
	SList[0].next = -1;
	avail = 1;
}

template <class DataType>
StaticList<DataType>::StaticList(DataType a[], int n) {
	length = 0;
    avail = 1;
	for (int i = 0; i < MAXSIZE - 1; ++i)
		SList[i].next = i + 1;
	SList[MAXSIZE - 1].next = -1;
	SList[0].next = avail;
	for (int j = 1; j <= n; ++j) {
		SList[j].data = a[j - 1];
		SList[j].next = j + 1;
	}
}

template <class DataType>
bool StaticList<DataType>::listempty() {
	return length == 0;
}

template<class DataType>
DataType StaticList<DataType>::GetElem(int i) {
	int k = 0;
	if (i > length  || i < 1)
		throw "wrong Location";
	else {
		for (int j = 0;j < i; ++j)
			k = SList[k].next;
		return SList[k].data;
	}
}

template <class DataType>
int StaticList<DataType>::LocateElem(DataType e) {
	int k = 0;
	for (int i = 0; i < length; ++i) {
		k = SList[k].next;
		if (SList[k].data == e)
			return i + 1;
	}
	return 0;
}

template <class DataType>
void StaticList<DataType>::Insert(int i, DataType e) {
	if (length == MAXSIZE - 2)
		throw "full";
	else if (i < 1 || i > length + 1)
		throw "wrong index";
	else {
		int m = 0;
        for(int j = 0;j<i-1;j++)
        {
            m = SList[m].next;
        }
        int t = avail;
        avail = SList[avail].next;
        int s = SList[m].next;
        SList[m].next = t;
        SList[t].data = e;
        SList[t].next = s;
        length++;
	}
}

template <class DataType>
DataType StaticList<DataType>::Delete(int i) {
	if (i < 1 || i > length)
		throw "wrong location";
    int m = 0;
    for(int j = 0;j<i-1;j++)
    {
        m = SList[m].next;
    }
    DataType temp = SList[SList[m].next].data;
    int t = SList[m].next;
    SList[m].next = SList[SList[m].next].next;
    SList[t].next = avail;
    avail = t;
    length--;
    return temp;
}

template <class DataType>
void StaticList<DataType>::PrintList() {
	int k = 0;
    for(int i = 0;i<length;i++)
    {
        k = SList[k].next;
        cout<<k<<":";
        cout<<SList[k].data<<" ";
    }
    cout<<endl;
}

int main(int argc, char** argv) {
	int a[] = {1,2};   //����д���ݲ�֧�ֹ��캯����ʼ������Ľ�
	StaticList<int> q(a, 2);
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
	q.PrintList();
	q.Insert(2,6);
	q.PrintList();
	cout << "The length of StaticList: " << q.Getlength() << endl;
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
