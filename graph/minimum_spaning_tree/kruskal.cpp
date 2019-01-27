#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

#define MAXVEX 100
//����߼����� 
struct Edge {
	int begin;
	int end;
	int weight;
};
Edge edges[MAXVEX];
char map[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

bool cmp(Edge a, Edge b) {
	return a.weight < b.weight;
}

//�������߶����β���±�
int Find(int *parent, int f) {
	while (parent[f] > 0)
		f = parent[f];
	return f;
}

void Kruskal(Edge edges[], int n, int m) {//�����ֱ��ʹ�ñ߼�������
	int sum = 0;
	int i,nn,mm;
	int parent[MAXVEX];
	//��ʼ��
	for (i = 0; i < n; ++i) {
		parent[i] = 0;
	}
	for (i = 0; i < m; ++i) {
		nn = Find(parent, edges[i].begin); //�����߶�Ӧ�Ķ���
		mm = Find(parent, edges[i].end);
		//�����˵���˱�û���������������γɻ�·
		if (nn != mm) {
			parent[nn] = mm;
			cout << map[edges[i].begin] << "->" << map[edges[i].end] << "=" << edges[i].weight << endl;
			sum += edges[i].weight;
		}
	}
	cout << "Minimum weight sum: " << sum << endl;
}


int main() {
	int i,n,m,begin,end,weight;
	ifstream in("input.txt");
	in >> n >> m;
	for (i = 0; i < m; ++i) {
		in >> begin >> end >> weight;
		edges[i].begin = begin;
		edges[i].end = end;
		edges[i].weight = weight;
	}
	sort(edges, edges + m, cmp);
	Kruskal(edges, n, m);
	return 0;
}
