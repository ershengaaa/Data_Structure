#include <iostream>
#include <vector>
using namespace std;

void ShellSort(vector<int>& vec);
void PrintStep(vector<int> vec, int n, int i);
void PrintResult(vector<int> vec, int n);

void ShellSort(vector<int>& vec)
{
	cout << "--------------希尔排序--------------" << endl;
	int i,j;
	int k = 1;
	int tmp;
	int increment = vec.size(); 
	do 
	{
		increment = increment/3 + 1;  //初始跳跃间隔
		for (i = increment + 1; i <= vec.size(); ++i)
		{
			if (vec[i - 1] < vec[i - increment - 1])
			{
				//对每一个小序列执行直接插入排序
				tmp = vec[i - 1];
				for (j = i - increment - 1; j >= 0 && vec[j] > tmp; j -= increment)
					vec[j + increment] = vec[j];
				vec[j + increment] = tmp;
			}
			PrintStep(vec, vec.size(), k);
			++k;
		} 
	}while (increment > 1);  //当跳跃间隔大于1继续
	cout << "最终排序结果为：";
	PrintResult(vec, vec.size());
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
	int a[] = {9,1,5,8,3,7,4,6,2};
	vector<int> vec(a, a+9);
	ShellSort(vec);
	return 0;
} 
