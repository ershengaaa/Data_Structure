//非递归版本 
#include <iostream>
#include <vector>
using namespace std;

#define MAXSIZE 10
vector<int> TR(MAXSIZE, 0);
int count = 0;

void MergeSort(vector<int>& vec);
void MergePass(vector<int> SR, vector<int>& TR, int s, int n); 
void Merge(vector<int> SR, vector<int>& TR,int i, int m, int n);
void PrintResult(vector<int> vec, int n);

void MergeSort(vector<int>& vec)
{
	cout << "--------------归并排序--------------" << endl;
	int k = 1;  //k为归并间隔，依次分别为1，2，4，8，16 
	while (k < vec.size() - 1)
	{
		MergePass(vec, TR, k, vec.size() - 1);
		k *= 2;  //间隔倍增 
		MergePass(TR, vec, k, vec.size() - 1); //注意这里需要换回去，因为下一次仍是从vec进行操作 
		k *= 2;
	}
}
//s代表此次归并的间隔 
void MergePass(vector<int> SR, vector<int>& TR, int s, int n)
{
	int i = 1;
	int j;
	//i + 2*s -1 <= n 
	while (i <= n - 2*s +1)
	{
		Merge(SR, TR, i, i + s - 1,i + 2*s - 1); //两两进行归并 
		i += 2*s; 
	}
	//归并最后两个序列 
	if (i < n - s +1)
		Merge(SR, TR, i, i +s -1, n);
	//归并最后一个单独序列 
	else {
		for (j = i;j <= n; ++j)
			TR[j] = SR[j];	
	}
	cout << "归并间隔为" << s << "得到的序列为：";
	PrintResult(TR,n); 
	cout << endl; 
}

void Merge(vector<int> SR, vector<int>& TR, int i, int m, int n)
{
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
	for (int j = 1; j <= n; ++j)
		cout << vec[j] << ' ';
	cout << endl;
}
int main(int argc, char **argv)
{
	int a[] = {0,50,10,90,30,70,40,80,60,20};
	vector<int> vec(a, a+10);
	MergeSort(vec);
	cout << endl << "最终排序结果为：         ";
	PrintResult(vec, vec.size() - 1);
	return 0;
} 
