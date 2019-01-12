#include <iostream>
#include <vector>
using namespace std;

void HeapSort(vector<int>& vec);
void HeapAdjust(vector<int>& vec, int max_index, int length);
void PrintStep(vector<int> vec, int n, int i);
void PrintResult(vector<int> vec, int n);

void HeapSort(vector<int>& vec)
{
	int i;
	cout << "--------------构造大顶堆----------" << endl; 
	int count1 = 1;
	//这里vec.size() - 1是在数组前面加了一个0，方便下标进行操作
	//除以2是因为i 小于n/2的节点 才有子节点，这里用到了上述提到过的节点关系的思想 
	for (i = (vec.size() - 1)/2;i > 0; --i)
	{
		HeapAdjust(vec, i, vec.size() - 1);     //将元素构造大顶堆 
		PrintStep(vec, vec.size() - 1, count1);
		++count1;
	}
	cout << "--------------堆排序--------------" << endl;
	int count2 = 1;
	for (i = vec.size() - 1;i > 0;--i)
	{
		swap(vec[i], vec[1]);       //交换堆顶元素与当前未经排序的子序列的最后一个记录 
		HeapAdjust(vec, 1, i - 1);  //将vec[1..i - 1]重新调整为大顶堆 
		PrintStep(vec, vec.size() - 1, count2);
		++count2;
	}
	cout << "最终排序结果为：  ";
	PrintResult(vec, vec.size() - 1);
}


void HeapAdjust(vector<int>& vec, int max_index, int length)
{
	int tmp, j;
	tmp = vec[max_index];  //记录下堆顶元素
	//以下沿元素值较大的孩子节点往下找
	for (j = 2 * max_index; j <= length; j *= 2) //这里j *= 2，之所以递增2倍也是节点关系讨论的结果
	{
		//找到当前节点的较大孩子节点的下标，即为j
		if (vec[j] < vec[j+1] && j < length)
			++j;
		//若当前父节点比其两个孩子节点都大，则不用调整
		if (tmp >= vec[j])
			break;
		//否则将将较大值与当前父节点交换，并记录下重新出发的点
		vec[max_index] = vec[j];
		max_index = j;  
	}
	vec[max_index] = tmp;
}

void PrintStep(vector<int> vec, int n, int i)
{
	cout << "第" << i << "次堆调整结果： ";
	for (int j = 1; j <= n; ++j)
		cout << vec[j] << ' ';
	cout << endl;
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
	HeapSort(vec);
	return 0;
} 
