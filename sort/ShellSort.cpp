#include <iostream>
#include <vector>
using namespace std;

void ShellSort(vector<int>& vec);
void PrintStep(vector<int> vec, int n, int i);
void PrintResult(vector<int> vec, int n);

void ShellSort(vector<int>& vec)
{
	cout << "--------------ϣ������--------------" << endl;
	int i,j;
	int k = 1;
	int tmp;
	int increment = vec.size(); 
	do 
	{
		increment = increment/3 + 1;  //��ʼ��Ծ���
		for (i = increment + 1; i <= vec.size(); ++i)
		{
			if (vec[i - 1] < vec[i - increment - 1])
			{
				//��ÿһ��С����ִ��ֱ�Ӳ�������
				tmp = vec[i - 1];
				for (j = i - increment - 1; j >= 0 && vec[j] > tmp; j -= increment)
					vec[j + increment] = vec[j];
				vec[j + increment] = tmp;
			}
			PrintStep(vec, vec.size(), k);
			++k;
		} 
	}while (increment > 1);  //����Ծ�������1����
	cout << "����������Ϊ��";
	PrintResult(vec, vec.size());
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
	int a[] = {9,1,5,8,3,7,4,6,2};
	vector<int> vec(a, a+9);
	ShellSort(vec);
	return 0;
} 
