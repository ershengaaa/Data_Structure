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
	cout << "--------------快速排序--------------" << endl;
	QSort(vec, 0, vec.size() - 1);
}

void QSort(vector<int>& vec, int low, int high)
{
	int pivot; //记录枢轴值pivot
	if (low < high)
	{
		pivot = Partition(vec, low, high);  //将序列分割为符合要求的两部分
											//算出枢轴值pivot
		QSort(vec, low, pivot - 1);       //对低子表递归排序
		QSort(vec, pivot + 1, high);       //对高子表递归排序
	} 
}

int Partition(vector<int>& vec, int low, int high)
{
	int pivotkey;         
	pivotkey = vec[low];   //对子表的第一个作枢轴记录
	while (low < high)     //从表的两端进行扫描
	{
		while (low < high && vec[high] >= pivotkey)  //从后找到第一个比枢轴小的值
			high--;
		swap(vec[low], vec[high]);  //交换该值与枢轴值
		while (low < high && vec[low] <= pivotkey) //从前找到第一个比枢轴大的值
			low++;
		swap(vec[low], vec[high]);  //交换该值与枢轴值
	}
	PrintStep(vec, vec.size(), count);
	++count;
	return low;  //返回枢轴下标 
}

void PrintStep(vector<int> vec, int n, int i)
{
	cout << "第" << i << "轮排序结果： ";
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
	cout << "最终排序结果为：";
	PrintResult(vec, vec.size());
	return 0;
} 
