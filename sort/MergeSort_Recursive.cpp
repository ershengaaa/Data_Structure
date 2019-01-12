//递归版本 
#include <iostream>
#include <vector>
using namespace std;

#define MAXSIZE 9
vector<int> TR2(MAXSIZE, 0);
int count = 0;

void MergeSort(vector<int>& vec);
void MSort(vector<int> SR, vector<int>& TR1, int start, int end);
void Merge(vector<int> SR, vector<int>& TR,int i, int m, int n);
void PrintResult(vector<int> vec, int n);

void MergeSort(vector<int>& vec)
{
	cout << "--------------归并排序--------------" << endl;
	MSort(vec, vec, 0, vec.size() - 1);
}

void MSort(vector<int> SR, vector<int>& TR1, int start, int end)
{int m;
	if (start == end)   //单个序列直接赋值到目标序列中
		TR1[start] = SR[start];
	else
	{
		m = (start + end)/2;  //将SR[s..t]平分为SR[sstart..m]、SR[m+1..end]
		MSort(SR, TR2, start, m); //递归将SR[start..m]归并为有序的TR2[start..m]
		MSort(SR, TR2, m + 1, end);//递归将SR[m+1..end]归并为有序的TR2[m+1..end]
		Merge(TR2, TR1,start, m, end);//将TR2[start..m]、TR2[m+1..end]归并到TR1中
	}	
}

void Merge(vector<int> SR, vector<int>& TR, int i, int m, int n)
{
	++count;
	cout << "第" << count << "次："<< endl; 
	cout << "当前合并序列TR2[start..m]为：";
	PrintResult(SR, SR.size()/2 + 1);
	cout << "当前合并序列TR2[m+1..end]为：";
	for (int x = SR.size()/2 + 1; x <= n; ++x)
	{
		cout << SR[x] << " ";
	}
	cout << endl;
	int j,k,l;
	for (j = m + 1,k = i;i <= m && j <= n; ++k)
	{
		if (SR[i] < SR[j])   //判断两个子序列中对应位置元素哪个根=更大，将大的加入到目标序列 
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	//若前序列有余，则加入到目标序列尾后 
	if (i <= m)
	{
		for (l = 0; l <= m - i; ++l)
			TR[k+l] = SR[i+l];  //将剩余的SR[i..m]复制到TR 
	}
	//若后序列有余，则加入到目标序列尾后 
	if (j <= n)
	{
		for (l = 0;l <= n - j; ++l)
			TR[k+l] = SR[j+l];   //将剩余的SR[j..n]复制到TR 
	}
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
	MergeSort(vec);
	cout << endl << "最终排序结果为：";
	PrintResult(vec, vec.size());
	return 0;
} 
