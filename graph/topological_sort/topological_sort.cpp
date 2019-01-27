#include <iostream>
#include <fstream>
#include <list>
#include <stack>
using namespace std;

class Graph {
public:
	Graph(int n);  //构造
	~Graph();  //析构
	void addEdge(int i, int j); //添加有向边
	bool topo_sort(); //拓扑排序
private:
	int n;  //图顶点数
	list<int> *adj;  //邻接表
	stack<int> st;  //存储入度为0的顶点
	int *indegree; //保存入度
};

Graph::Graph(int n) {
	this->n = n;
	adj = new list<int>[n + 1];
	indegree = new int[n + 1];
	//初始化入度为0
	for (int i = 1; i <= n; ++i) {
		indegree[i] = 0;
	}
}

Graph::~Graph() {
	delete []adj;
	delete []indegree;
}

void Graph::addEdge(int i, int j) {
	//添加边i->j，j顶点入度加1
	adj[i].push_back(j);
	++indegree[j];
}

bool Graph::topo_sort() {
	//将顶点入度为0的入栈
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) 
			st.push(i);
	}
	//计算顶点个数
	int count = 0;
	while (!st.empty()) {
		//取一个入度为0的顶点
		int temp = st.top();
		st.pop(); //出栈
		//输出该顶点
		cout << temp << " ";
		++count;
		//计算删除该顶点之后其余顶点的入度，若为0则入栈
		list<int>::iterator it = adj[temp].begin();
		for (; it != adj[temp].end(); ++it) {
			if (!(--indegree[*it]))
				st.push(*it);
		}
	}
	//如果计算的定点数小于n，则说明有环
	if (count < n)
		return false;
	else
		return true;
}

int main() {
	int n,m;
	int i, j, k;
	ifstream in("input.txt");
	in >> n >> m;
	Graph g(n);
	for (k = 0; k < m; ++k) {
		in >> i >> j;
		g.addEdge(i,j);
	}
	g.topo_sort();
	return 0;
}
