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
		for (int j = n - 1; j >= i; --j) //注意j说从后往前循环
		{
			if (vec[j] > vec[j + 1]) 
				swap(vec[j], vec[j + 1]);
		}
	}
}

//冒泡排序改进
/*void BubbleSort(vector<int>& vec)
{
	cout << "--------------冒泡排序--------------" << endl;
	int n = vec.size();
	bool flag = 1;
	for (int i = 0; i < n && flag ; ++i)
	{
		flag = 0;
		for (int j = n - 2; j >= i; --j)
		{
			if (vec[j] > vec[j + 1]) {
				swap(vec[j], vec[j + 1]);
				flag = 1;      //有交换则将flag置为1
			}
		}
		PrintStep(vec, n, i);
	}
	cout << "最终排序结果为：";
	PrintResult(vec, n);
}*/

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
	int a[] = {2,1,3,4,5,6,7,8,9};
	vector<int > vec(a, a+9);
	BubbleSort(vec);
	return 0;
}
