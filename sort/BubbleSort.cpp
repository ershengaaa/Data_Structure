#include <iostream>
#include <vector>
using namespace std;

void BubbleSort(vector<int>& vec);
void PrintStep(vector<int> vec, int n, int i);
void PrintResult(vector<int> vec, int n);

void BubbleSort(vector<int>& vec)
{
	int n = vec.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = n - 1; j >= i; --j) //ע��j˵�Ӻ���ǰѭ��
		{
			if (vec[j] > vec[j + 1]) 
				swap(vec[j], vec[j + 1]);
		}
	}
}

//ð������Ľ�
/*void BubbleSort(vector<int>& vec)
{
	cout << "--------------ð������--------------" << endl;
	int n = vec.size();
	bool flag = 1;
	for (int i = 0; i < n && flag ; ++i)
	{
		flag = 0;
		for (int j = n - 2; j >= i; --j)
		{
			if (vec[j] > vec[j + 1]) {
				swap(vec[j], vec[j + 1]);
				flag = 1;      //�н�����flag��Ϊ1
			}
		}
		PrintStep(vec, n, i);
	}
	cout << "����������Ϊ��";
	PrintResult(vec, n);
}*/

void PrintStep(vector<int> vec, int n, int i)
{
	cout << "��" << i + 1 << "���������� ";
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
	int a[] = {2,1,3,4,5,6,7,8,9};
	vector<int > vec(a, a+9);
	BubbleSort(vec);
	return 0;
}
