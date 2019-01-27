//�ڽӱ� 
typedef char VertexType;  //��������
typedef int EdgeType;   //��Ȩֵ����
#define MAXVEX 100   //��󶥵���
//�߱�ڵ�
typedef struct EdgeNode {
	//�ڽӵ��򣬴洢�ö����Ӧ���±�
	int adjvex;
	//���ڴ洢Ȩֵ
	EdgeType weight;
	//ָ����һ���ڽӵ�
	struct EdgeNode *next;
}EdgeNode;
//�����ڵ�
typedef struct VertexNode {
	//�����򣬴洢������Ϣ
	VertexType data;
	//�߱�ͷָ��
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	//ͼ�е�ǰ�������ͱ���
	int numVextexes, numEdges;
}GraphAdjList;


//��ͼ 
void CreateALGraph(GraphAdjList *G) {
	int i,j,k;
	//���붥������ͱ���
	cin >>  G->numVextexes >> G->numEdges;
	//���붥����Ϣ������������Ϣ��
	for (i = 0; i < numVextexes; ++i) {
		cin >> G->adjList[i].data;
		G->adjList[i].firstedge = NULL;  //���߱���Ϊ��
	}
	//�����߱�
	for (k = 0; k < numEdges; ++k) {
		cin >> i >> j;  //���붥��(vi, vj)�±�
		//��vj���뵽vi�ı߱���
		EdgeNode *e = new EdgeNode();
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;
		//��vi���뵽vj�ı߱���
		EdgeNode *e = new EdgeNode();
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}


//DFS���ڽӱ� 
bool visited[MAXVEX];  //���ʼ�¼
void DFS(GraphAdjList G, int i) {
	EdgeNode *p;
	cout << G.adjList[i].data;  //����
	p = G.adjList[i].firstedge;  
	//�������·��û�����������
	while (p) {
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
}
//DFS����
void DFSTraverse(GraphAdjList G) {
	int i;
	//��ʼ�����ʼ�¼
	for (i = 0; i < numVextexes; ++i) {
		visited[i] = false;
	}
	//����ÿһ������
	for (i = 0; i < numVextexes; ++i) {
		if (!visited[i])
			DFS(G, i);
	} 
}



//BFS���ڽӱ� 
void BFSTraverse(GraphAdjList G) {
	int i;
	EdgeNode *p;
	queue<int> q;
	//��ʼ�����ʼ�¼
	for (i = 0; i < G.numVextexes; ++i) {
		visited[i] = false;
	}
	//����ÿ������
	for (i = 0; i < G.numVextexes; ++i) {
		if (!visited[i]) {
			visited[i] = true;
		}
		cout << G.adjList[i].data;
		q.push(i);
		while (!q.empty()) {
			q.pop();
			p = G.adjList[i].firstedge;
			while (p) {
				if (!visited[p->adjvex]) {
					visited[p->adjvex] = true;
					cout << G.adjList[p->adjvex].data;
					q.push(p->adjvex);
					p = p->next;
				}
			}
		}
	}
}
