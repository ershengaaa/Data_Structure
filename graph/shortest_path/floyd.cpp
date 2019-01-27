#include <iostream>
#include <fstream>
using namespace std;

#define MAXVEX 100
#define INFINITY 65535
int map[MAXVEX][MAXVEX]; //Ȩֵ���󣬼��ڽӾ���
int p[MAXVEX][MAXVEX];  //��̽ڵ�·��
char vex[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };

void Floyd(int map[][MAXVEX], int n) {
	int i,j,k;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			p[i][j] = j;
		}
	}
	for (k = 0; k < n; ++k) {
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				//ת�Ʒ��̣��������k����·����ԭ�����·����������� 
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					p[i][j] = p[i][k];
				}
			}
		}
	}
}

int main() {
	int n,m;
	int i,j,k,cost;
	ifstream in("input.txt");
	in >> n >> m;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			map[i][j] = INFINITY;
		}
	}

	for (k = 0; k < m; ++k) {
		in >> i >> j >> cost;
		map[i][j] = cost;
		map[j][i] = cost;
	}

	Floyd(map, n);
	//��ӡ·�� 
	for (i = 0; i < n; ++i) {
		for (j = i + 1; j < n; ++j) {
			cout << vex[i] << "->" << vex[j] << " minimum sum weight: " << map[i][j] << endl;
			int t = p[i][j];
			cout << "path: " << vex[i];
			while (t != j) {
				cout << "->" << vex[t];
				t= p[t][j];
			}
			cout << "->" << vex[t] << endl;
		}
		cout << endl;
	}

	return 0;
}

