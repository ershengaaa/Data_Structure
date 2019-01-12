#include <iostream>
#include <vector>
using namespace std;

void SelectSort(vector<int>& vec);
void PrintStep(vector<int> vec, int n, int i);
void PrintResult(vector<int> vec, int n);

void SelectSort(vector<int>& vec)
{
	cout << "--------------选择排序--------------" << endl;
	int n = vec.size();
	int minIndex;
	for (int i = 0; i < n - 1; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < vec.size(); ++j)
		{
			if (vec[j] < vec[minIndex])
				minIndex = j;
		}
		if (i != minIndex)
			swap(vec[i], vec[minIndex]);
		PrintStep(vec, n, i);
	}
	cout << "最终排序结果为：";
	PrintResult(vec, n);
}

void PrintStep(vector<int> vec, int n, int i)
{
	cout << "第" << i + 1 << "次排序结果： ";
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
	vector<int > vec(a, a+9);
	SelectSort(vec);
	return 0;
}
