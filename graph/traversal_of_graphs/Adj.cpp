//邻接表 
typedef char VertexType;  //顶点类型
typedef int EdgeType;   //边权值类型
#define MAXVEX 100   //最大顶点数
//边表节点
typedef struct EdgeNode {
	//邻接点域，存储该顶点对应的下标
	int adjvex;
	//用于存储权值
	EdgeType weight;
	//指向下一个邻接点
	struct EdgeNode *next;
}EdgeNode;
//顶点表节点
typedef struct VertexNode {
	//顶点域，存储顶点信息
	VertexType data;
	//边表头指针
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct {
	AdjList adjList;
	//图中当前顶点数和边数
	int numVextexes, numEdges;
}GraphAdjList;


//建图 
void CreateALGraph(GraphAdjList *G) {
	int i,j,k;
	//读入顶点个数和边数
	cin >>  G->numVextexes >> G->numEdges;
	//读入顶点信息，建立顶点信息表
	for (i = 0; i < numVextexes; ++i) {
		cin >> G->adjList[i].data;
		G->adjList[i].firstedge = NULL;  //将边表置为空
	}
	//建立边表
	for (k = 0; k < numEdges; ++k) {
		cin >> i >> j;  //读入顶点(vi, vj)下标
		//将vj插入到vi的边表中
		EdgeNode *e = new EdgeNode();
		e->adjvex = j;
		e->next = G->adjList[i].firstedge;
		G->adjList[i].firstedge = e;
		//将vi插入到vj的边表中
		EdgeNode *e = new EdgeNode();
		e->adjvex = i;
		e->next = G->adjList[j].firstedge;
		G->adjList[j].firstedge = e;
	}
}


//DFS（邻接表） 
bool visited[MAXVEX];  //访问记录
void DFS(GraphAdjList G, int i) {
	EdgeNode *p;
	cout << G.adjList[i].data;  //操作
	p = G.adjList[i].firstedge;  
	//如果这条路还没走完则继续走
	while (p) {
		if (!visited[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
}
//DFS操作
void DFSTraverse(GraphAdjList G) {
	int i;
	//初始化访问记录
	for (i = 0; i < numVextexes; ++i) {
		visited[i] = false;
	}
	//遍历每一个顶点
	for (i = 0; i < numVextexes; ++i) {
		if (!visited[i])
			DFS(G, i);
	} 
}



//BFS（邻接表） 
void BFSTraverse(GraphAdjList G) {
	int i;
	EdgeNode *p;
	queue<int> q;
	//初始化访问记录
	for (i = 0; i < G.numVextexes; ++i) {
		visited[i] = false;
	}
	//遍历每个顶点
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
