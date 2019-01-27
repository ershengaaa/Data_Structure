#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

#define MAXVEX 100
//定义边集数组 
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

//查找连线顶点的尾部下标
int Find(int *parent, int f) {
	while (parent[f] > 0)
		f = parent[f];
	return f;
}

void Kruskal(Edge edges[], int n, int m) {//这里就直接使用边集数组了
	int sum = 0;
	int i,nn,mm;
	int parent[MAXVEX];
	//初始化
	for (i = 0; i < n; ++i) {
		parent[i] = 0;
	}
	for (i = 0; i < m; ++i) {
		nn = Find(parent, edges[i].begin); //找连线对应的顶点
		mm = Find(parent, edges[i].end);
		//不相等说明此边没有与现有生成树形成环路
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
