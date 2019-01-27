//�ڽӾ���
typedef char VextexType;  //��������(�Զ��壩
typedef int EdgeType;    //����Ȩֵ����(�Զ���)
#define MAXVEX 100      //��󶥵���
#define INFINITY 65535  //���� ����
typedef struct {
	VextexType vexs[MAXVEX];  //�����
	EdgeType arc[MAXVEX][MAXVEX];  //�ڽӾ���
	int numVextexes, numEdges;  //ͼ�е�ǰ�������ͱ���
}MGraph;

//��ͼ 
void CreateMGraph(MGraph *G) {
	int i,j,k,w;
	//���붥������ͱ���
	cin >> G->numVertexes >> G->numEdges;
	//����������Ϣ��
	for (i = 0; i < G->numVertexes; ++i) {
		cin >> G->vexs[i];
	}
	//��ʼ���ڽӾ���
	for (i = 0; i < G->numVertexes; ++i) {
		for (j = 0; j < numVertexes; ++j) {
			G->arc[i][j] = INFINITY;
		}
	}
	//�����Ȩֵ�������ڽӾ���
	for (k = 0; k < numEdges; ++k) {
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];  //����ͼ�ǶԳƾ���
	}
}

//DFS���ڽӾ��� 
bool visited[MAXVEX];  //���ʼ�¼
//DFS�ݹ��㷨
void DFS(MGraph G, int i) {
	int j;
	visited[i] = true;  //���ȱ��Ϊ�ѷ���
	//������Ҫ��Ĳ���
	cout << G.vexs[i];
	for (j = 0; j < G.numVextexes; ++j) {
		//��������ڽӵ�δ�����ʣ����������
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G,j);
	}
}
//DFS����
void DFSTraverse(MGraph G) {
	int i;
	//��ʼ�����ʼ�¼��
	for (i = 0; i < G.numVextexes; ++i) {
		visited[i] = false;
	}
	//����ÿһ������
	for (i = 0; i < numVextexes; ++i) {
		if (!visited[i])
			DFS(G, i);
	}
}


//BFS���ڽӾ��� 
void BFSTraverse(MGraph G) {
	int i,j;
	queue<int> q;
	for (i = 0; i < G.numVertexes; ++i) {
		visited[i] = false;
	}
	for (i = 0; i < G.numVextexes; ++i) {
		if (!visited[i])
			visited[i] = true;
		cout << G.vexs[i];
		q.push(G.vexs[i]);
		while (!q.empty()) {
			VextexType temp = q.pop();
			for (j = 0; j < G.numVextexes; ++j) {
				if (G.arc[i][j] == 1 && !visited[j]) {
					visited[j] = true;
					cout << G.vexs[j];
					q.push(G.vexs[j]);
				}
			}
		}
	}
}
