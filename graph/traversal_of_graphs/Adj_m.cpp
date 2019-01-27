//邻接矩阵
typedef char VextexType;  //顶点类型(自定义）
typedef int EdgeType;    //边上权值类型(自定义)
#define MAXVEX 100      //最大顶点数
#define INFINITY 65535  //代替 无穷
typedef struct {
	VextexType vexs[MAXVEX];  //顶点表
	EdgeType arc[MAXVEX][MAXVEX];  //邻接矩阵
	int numVextexes, numEdges;  //图中当前顶点数和边数
}MGraph;

//建图 
void CreateMGraph(MGraph *G) {
	int i,j,k,w;
	//读入顶点个数和边数
	cin >> G->numVertexes >> G->numEdges;
	//建立顶点信息表
	for (i = 0; i < G->numVertexes; ++i) {
		cin >> G->vexs[i];
	}
	//初始化邻接矩阵
	for (i = 0; i < G->numVertexes; ++i) {
		for (j = 0; j < numVertexes; ++j) {
			G->arc[i][j] = INFINITY;
		}
	}
	//读入边权值，构建邻接矩阵
	for (k = 0; k < numEdges; ++k) {
		cin >> i >> j >> w;
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];  //无向图是对称矩阵
	}
}

//DFS（邻接矩阵） 
bool visited[MAXVEX];  //访问记录
//DFS递归算法
void DFS(MGraph G, int i) {
	int j;
	visited[i] = true;  //首先标记为已访问
	//接题意要求的操作
	cout << G.vexs[i];
	for (j = 0; j < G.numVextexes; ++j) {
		//如果还有邻接点未被访问，则继续访问
		if (G.arc[i][j] == 1 && !visited[j])
			DFS(G,j);
	}
}
//DFS操作
void DFSTraverse(MGraph G) {
	int i;
	//初始化访问记录表
	for (i = 0; i < G.numVextexes; ++i) {
		visited[i] = false;
	}
	//遍历每一个顶点
	for (i = 0; i < numVextexes; ++i) {
		if (!visited[i])
			DFS(G, i);
	}
}


//BFS（邻接矩阵） 
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
