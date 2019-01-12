#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int>& vec);
void PrintStep(vector<int> vec, int n, int i);
void PrintResult(vector<int> vec, int n);

void InsertSort(vector<int>& vec)
{
	cout << "--------------ֱ�Ӳ�������--------------" << endl;
	int n = vec.size();
	int i, j, tmp;
	for (i = 1; i < vec.size(); ++i)
	{
		if (vec[i] < vec[i - 1]) 
		{
			tmp = vec[i];  //����ǰ�������Ԫ�����
		for (j = i - 1; j >= 0 && vec[j] > tmp; --j)
			vec[j + 1] = vec[j];  //���Ѿ��ź��������������һλ���ҵ�����λ����ֹͣ
		vec[j + 1] = tmp;  //��Ԫ�ز�������
		}
		PrintStep(vec, n, i);
	}
	cout << "����������Ϊ��";
	PrintResult(vec, n);
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
	int a[] = {9,8,7,6,5,4,3,2,1};
	vector<int> vec(a, a+9);
	InsertSort(vec);
	return 0;
} 
