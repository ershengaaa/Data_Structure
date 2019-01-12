#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int>& vec);
void QSort(vector<int>& vec, int low, int high);
int Partition(vector<int>& vec, int low, int high);
void PrintStep(vector<int> vec, int n, int i);
void PrintResult(vector<int> vec, int n);

int count = 1;

void QuickSort(vector<int>& vec)
{
	cout << "--------------��������--------------" << endl;
	QSort(vec, 0, vec.size() - 1);
}

void QSort(vector<int>& vec, int low, int high)
{
	int pivot; //��¼����ֵpivot
	if (low < high)
	{
		pivot = Partition(vec, low, high);  //�����зָ�Ϊ����Ҫ���������
											//�������ֵpivot
		QSort(vec, low, pivot - 1);       //�Ե��ӱ�ݹ�����
		QSort(vec, pivot + 1, high);       //�Ը��ӱ�ݹ�����
	} 
}

int Partition(vector<int>& vec, int low, int high)
{
	int pivotkey;         
	pivotkey = vec[low];   //���ӱ�ĵ�һ���������¼
	while (low < high)     //�ӱ�����˽���ɨ��
	{
		while (low < high && vec[high] >= pivotkey)  //�Ӻ��ҵ���һ��������С��ֵ
			high--;
		swap(vec[low], vec[high]);  //������ֵ������ֵ
		while (low < high && vec[low] <= pivotkey) //��ǰ�ҵ���һ����������ֵ
			low++;
		swap(vec[low], vec[high]);  //������ֵ������ֵ
	}
	PrintStep(vec, vec.size(), count);
	++count;
	return low;  //���������±� 
}

void PrintStep(vector<int> vec, int n, int i)
{
	cout << "��" << i << "���������� ";
	for (int j = 0; j < n; ++j)
		cout << vec[j] << ' ';
	cout << endl;
}
void PrintResult(vector<int> vec, int n)
{
	for (int j = 0; j < n; ++j)
		cout << vec[j] << ' ';
	cout << endl;
}
int main(int argc, char **argv)
{
	int a[] = {50,10,90,30,70,40,80,60,20};
	vector<int> vec(a, a+9);
	QuickSort(vec);
	cout << "����������Ϊ��";
	PrintResult(vec, vec.size());
	return 0;
} 
