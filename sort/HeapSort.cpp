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
	cout << "--------------����󶥶�----------" << endl; 
	int count1 = 1;
	//����vec.size() - 1��������ǰ�����һ��0�������±���в���
	//����2����Ϊi С��n/2�Ľڵ� �����ӽڵ㣬�����õ��������ᵽ���Ľڵ��ϵ��˼�� 
	for (i = (vec.size() - 1)/2;i > 0; --i)
	{
		HeapAdjust(vec, i, vec.size() - 1);     //��Ԫ�ع���󶥶� 
		PrintStep(vec, vec.size() - 1, count1);
		++count1;
	}
	cout << "--------------������--------------" << endl;
	int count2 = 1;
	for (i = vec.size() - 1;i > 0;--i)
	{
		swap(vec[i], vec[1]);       //�����Ѷ�Ԫ���뵱ǰδ������������е����һ����¼ 
		HeapAdjust(vec, 1, i - 1);  //��vec[1..i - 1]���µ���Ϊ�󶥶� 
		PrintStep(vec, vec.size() - 1, count2);
		++count2;
	}
	cout << "����������Ϊ��  ";
	PrintResult(vec, vec.size() - 1);
}


void HeapAdjust(vector<int>& vec, int max_index, int length)
{
	int tmp, j;
	tmp = vec[max_index];  //��¼�¶Ѷ�Ԫ��
	//������Ԫ��ֵ�ϴ�ĺ��ӽڵ�������
	for (j = 2 * max_index; j <= length; j *= 2) //����j *= 2��֮���Ե���2��Ҳ�ǽڵ��ϵ���۵Ľ��
	{
		//�ҵ���ǰ�ڵ�Ľϴ��ӽڵ���±꣬��Ϊj
		if (vec[j] < vec[j+1] && j < length)
			++j;
		//����ǰ���ڵ�����������ӽڵ㶼�����õ���
		if (tmp >= vec[j])
			break;
		//���򽫽��ϴ�ֵ�뵱ǰ���ڵ㽻��������¼�����³����ĵ�
		vec[max_index] = vec[j];
		max_index = j;  
	}
	vec[max_index] = tmp;
}

void PrintStep(vector<int> vec, int n, int i)
{
	cout << "��" << i << "�ζѵ�������� ";
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
