#include <iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int>& vec);
void PrintStep(vector<int> vec, int n, int i);
void PrintResult(vector<int> vec, int n);

void InsertSort(vector<int>& vec)
{
	cout << "--------------直接插入排序--------------" << endl;
	int n = vec.size();
	int i, j, tmp;
	for (i = 1; i < vec.size(); ++i)
	{
		if (vec[i] < vec[i - 1]) 
		{
			tmp = vec[i];  //将当前待插入的元素提出
		for (j = i - 1; j >= 0 && vec[j] > tmp; --j)
			vec[j + 1] = vec[j];  //将已经排好序的序列往后移一位，找到插入位置则停止
		vec[j + 1] = tmp;  //将元素插入其中
		}
		PrintStep(vec, n, i);
	}
	cout << "最终排序结果为：";
	PrintResult(vec, n);
}

void PrintStep(vector<int> vec, int n, int i)
{
	cout << "第" << i << "次排序结果： ";
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
