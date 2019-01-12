//�ݹ�汾 
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
	cout << "--------------�鲢����--------------" << endl;
	MSort(vec, vec, 0, vec.size() - 1);
}

void MSort(vector<int> SR, vector<int>& TR1, int start, int end)
{int m;
	if (start == end)   //��������ֱ�Ӹ�ֵ��Ŀ��������
		TR1[start] = SR[start];
	else
	{
		m = (start + end)/2;  //��SR[s..t]ƽ��ΪSR[sstart..m]��SR[m+1..end]
		MSort(SR, TR2, start, m); //�ݹ齫SR[start..m]�鲢Ϊ�����TR2[start..m]
		MSort(SR, TR2, m + 1, end);//�ݹ齫SR[m+1..end]�鲢Ϊ�����TR2[m+1..end]
		Merge(TR2, TR1,start, m, end);//��TR2[start..m]��TR2[m+1..end]�鲢��TR1��
	}	
}

void Merge(vector<int> SR, vector<int>& TR, int i, int m, int n)
{
	++count;
	cout << "��" << count << "�Σ�"<< endl; 
	cout << "��ǰ�ϲ�����TR2[start..m]Ϊ��";
	PrintResult(SR, SR.size()/2 + 1);
	cout << "��ǰ�ϲ�����TR2[m+1..end]Ϊ��";
	for (int x = SR.size()/2 + 1; x <= n; ++x)
	{
		cout << SR[x] << " ";
	}
	cout << endl;
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
	for (int j = 0; j < n; ++j)
		cout << vec[j] << ' ';
	cout << endl;
}
int main(int argc, char **argv)
{
	int a[] = {50,10,90,30,70,40,80,60,20};
	vector<int> vec(a, a+9);
	MergeSort(vec);
	cout << endl << "����������Ϊ��";
	PrintResult(vec, vec.size());
	return 0;
} 
