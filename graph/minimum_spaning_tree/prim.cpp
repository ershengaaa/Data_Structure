#include <iostream>
#include <fstream>
using namespace std;

#define MAXVEX 100 //��󶥵���
#define INFINITY 65535 //��������
int graph[MAXVEX][MAXVEX]; //ͼ
char map[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',' h', 'i' }; //��Ӧ�Ķ��������

int Prim(int graph[][MAXVEX], int n) {
	int i, j, k, min, sum = 0;
	int adjvex[MAXVEX]; 
	int lowcost[MAXVEX];
	//���±�Ϊ0�Ķ��㿪ʼ������a��ʼ
	lowcost[0] = 0;
	//��ʼ����һ�������±�Ϊ0
	adjvex[0] = 0;
	//ѭ���±��0������ж���
	for (i = 1; i < n; ++i) {
		//��v0������֮�бߵ�Ȩֵ��������
		lowcost[i] = graph[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < n; ++i) {
		min = INFINITY; //��ʼ����СȨֵΪ����
		j = 1, k = 0;
		//ѭ��ȫ�����㣬�ҵ���СȨֵ
		while (j < n) {
			if (lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
			++j;
		}
		//�����СȨֵ��
		cout << map[adjvex[k]] << "->" << map[k] << "=" << min << endl;
		sum += min;
		lowcost[k] = 0;  //���±�Ϊk�Ķ������MST
		//����lowcostΪ����Ķ�������б�
		for (j = 1; j < n; ++j) {
			if (lowcost[j] != 0 && graph[k][j] < lowcost[j]) {
				lowcost[j] = graph[k][j];
				adjvex[j] = k;
			}
		}
	}
	return sum;
}


int main(int argc, char**argv) {
	int i,j,k,cost;
	int m,n;
	ifstream in("input.txt");
	in >> n >> m;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			graph[i][j] = INFINITY;
		}
	}

	for (k = 0; k < m; ++k) {
		in >> i >> j >> cost;
		graph[i][j] = cost;
		graph[j][i] = cost;
	}

	cost = Prim(graph, n);
	cout << "Minimum weight sum: " << cost << endl;
	return 0;
}
