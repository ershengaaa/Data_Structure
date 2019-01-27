#include <iostream>
#include <fstream>
#include <list>
#include <stack>
using namespace std;

class Graph {
public:
	Graph(int n);  //����
	~Graph();  //����
	void addEdge(int i, int j); //��������
	bool topo_sort(); //��������
private:
	int n;  //ͼ������
	list<int> *adj;  //�ڽӱ�
	stack<int> st;  //�洢���Ϊ0�Ķ���
	int *indegree; //�������
};

Graph::Graph(int n) {
	this->n = n;
	adj = new list<int>[n + 1];
	indegree = new int[n + 1];
	//��ʼ�����Ϊ0
	for (int i = 1; i <= n; ++i) {
		indegree[i] = 0;
	}
}

Graph::~Graph() {
	delete []adj;
	delete []indegree;
}

void Graph::addEdge(int i, int j) {
	//��ӱ�i->j��j������ȼ�1
	adj[i].push_back(j);
	++indegree[j];
}

bool Graph::topo_sort() {
	//���������Ϊ0����ջ
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0) 
			st.push(i);
	}
	//���㶥�����
	int count = 0;
	while (!st.empty()) {
		//ȡһ�����Ϊ0�Ķ���
		int temp = st.top();
		st.pop(); //��ջ
		//����ö���
		cout << temp << " ";
		++count;
		//����ɾ���ö���֮�����ඥ�����ȣ���Ϊ0����ջ
		list<int>::iterator it = adj[temp].begin();
		for (; it != adj[temp].end(); ++it) {
			if (!(--indegree[*it]))
				st.push(*it);
		}
	}
	//�������Ķ�����С��n����˵���л�
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
