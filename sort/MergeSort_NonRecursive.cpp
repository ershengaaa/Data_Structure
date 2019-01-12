//�ǵݹ�汾 
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
	cout << "--------------�鲢����--------------" << endl;
	int k = 1;  //kΪ�鲢��������ηֱ�Ϊ1��2��4��8��16 
	while (k < vec.size() - 1)
	{
		MergePass(vec, TR, k, vec.size() - 1);
		k *= 2;  //������� 
		MergePass(TR, vec, k, vec.size() - 1); //ע��������Ҫ����ȥ����Ϊ��һ�����Ǵ�vec���в��� 
		k *= 2;
	}
}
//s����˴ι鲢�ļ�� 
void MergePass(vector<int> SR, vector<int>& TR, int s, int n)
{
	int i = 1;
	int j;
	//i + 2*s -1 <= n 
	while (i <= n - 2*s +1)
	{
		Merge(SR, TR, i, i + s - 1,i + 2*s - 1); //�������й鲢 
		i += 2*s; 
	}
	//�鲢����������� 
	if (i < n - s +1)
		Merge(SR, TR, i, i +s -1, n);
	//�鲢���һ���������� 
	else {
		for (j = i;j <= n; ++j)
			TR[j] = SR[j];	
	}
	cout << "�鲢���Ϊ" << s << "�õ�������Ϊ��";
	PrintResult(TR,n); 
	cout << endl; 
}

void Merge(vector<int> SR, vector<int>& TR, int i, int m, int n)
{
	int j,k,l;
	for (j = m + 1,k = i;i <= m && j <= n; ++k)
	{
		if (SR[i] < SR[j])   //�ж������������ж�Ӧλ��Ԫ���ĸ���=���󣬽���ļ��뵽Ŀ������ 
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	//��ǰ�������࣬����뵽Ŀ������β�� 
	if (i <= m)
	{
		for (l = 0; l <= m - i; ++l)
			TR[k+l] = SR[i+l];  //��ʣ���SR[i..m]���Ƶ�TR 
	}
	//�����������࣬����뵽Ŀ������β�� 
	if (j <= n)
	{
		for (l = 0;l <= n - j; ++l)
			TR[k+l] = SR[j+l];   //��ʣ���SR[j..n]���Ƶ�TR 
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
	cout << endl << "����������Ϊ��         ";
	PrintResult(vec, vec.size() - 1);
	return 0;
} 
