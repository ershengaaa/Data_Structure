#include <iostream>
#include <fstream>
using namespace std;

#define MAXVEX 100 //最大顶点数
#define INFINITY 65535 //代替无穷
int graph[MAXVEX][MAXVEX]; //图
char map[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',' h', 'i' }; //对应的顶点的描述

int Prim(int graph[][MAXVEX], int n) {
	int i, j, k, min, sum = 0;
	int adjvex[MAXVEX]; 
	int lowcost[MAXVEX];
	//从下标为0的顶点开始，即从a开始
	lowcost[0] = 0;
	//初始化第一个顶点下标为0
	adjvex[0] = 0;
	//循环下标除0外的所有顶点
	for (i = 1; i < n; ++i) {
		//将v0顶点与之有边的权值存入数组
		lowcost[i] = graph[0][i];
		adjvex[i] = 0;
	}
	for (i = 1; i < n; ++i) {
		min = INFINITY; //初始化最小权值为无穷
		j = 1, k = 0;
		//循环全部顶点，找到最小权值
		while (j < n) {
			if (lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
			++j;
		}
		//输出最小权值边
		cout << map[adjvex[k]] << "->" << map[k] << "=" << min << endl;
		sum += min;
		lowcost[k] = 0;  //将下标为k的顶点加入MST
		//更新lowcost为加入的顶点的所有边
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
