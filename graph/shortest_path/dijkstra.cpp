#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define MAXVEX 100
#define INFINITY 65535
int path[MAXVEX];
int cost[MAXVEX];
int map[MAXVEX][MAXVEX];
char vex[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

void Dijkstra(int map[][MAXVEX], int start, int n) {
	int i, j, k, min;
	int final[MAXVEX];  //标记顶点
	for (i = 0; i < n; ++i) {
		final[i] = 0;
		cost[i] = map[start][i]; //start表示源点下标
		path[i] = 0;
		cost[0] = 0;
		final[start] = 1;
	}
	for (i = 1; i < n; ++i) {
		min = INFINITY;
		//找到v0到vk的最短路径
		for (j = 0; j < n; ++j) {
			if (!final[j] && cost[j] < min) {
				k = j;
				min = cost[j];
			}
		}
		final[k] = 1;  //标记该顶点
		//修正当前最短路径及距离
		for (j = 0; j < n; ++j) {
			if (!final[j] && min + map[k][j] < cost[j]) {
				cost[j] = min + map[k][j];
				path[j] = k;
			} 
		}
	}
}

int main() {
	int n,m;
	int i,j,k,costvalue;
	ifstream in("input.txt");
	in >> n >> m;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			map[i][j] = INFINITY;
		}
	}

	for (k = 0; k < m; ++k) {
		in >> i >> j >> costvalue;
		map[i][j] = costvalue;
		map[j][i] = costvalue;
	}

	Dijkstra(map, 0, n);
	//打印最短路径 
	for (i = 1; i < n; ++i) {
		if (path[i] == 0) {
			cout << vex[0] << "->" << vex[i] << "=" << cost[i] << endl;
		}
		else {
			vector<int> vec(n, 0);
			int t = 0;
			int k = i;	
			while (path[k] != 0) {
				vec[t] = k;
				k = path[k];
				++t;
			}
			vec[t] = k;
			++t;
			for (int l = t; l > 0 ; --l) {
				cout << vex[vec[l]] << "->";
			}
			cout << vex[vec[0]] << "=" << cost[i] << endl;
		}
	}
	return 0;
}

