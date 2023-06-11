#pragma once
typedef struct
{
	DataType list[MaxSize];
	int size;
}SeqList;

void ListInitiate(SeqList* L) {
	L->size = 0;
}
int ListLength(SeqList L)
{
	return L.size;
}


int LisiInsert(SeqList* L, int i, DataType x)
{
	int j;
	if (L->size >= MaxSize)
	{
		printf("顺序表已满无法插入！\n");
	}
	else if (i<0 || i>L->size)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else
	{
		for (j = L->size; j > i; j--)
			L->list[j] = L->list[j - 1];
		L->list[i] = x;
		L->size++;
		return 1;
	}
}



int ListDelete(SeqList* L, int i, DataType* x)
{
	int j;
	if (L->size <= 0)
	{
		printf("顺序表已空无数据元素可删！\n");
		return 0;
	}
	else if (i<0 || i>L->size - 1)
	{
		printf("参数i不合法\n");
		return 0;
	}
	else
	{
		*x = L->list[i];//保存删除的元素到x中
		//从前往后依次前移
		for (j = i + 1; j <= L->size - 1; j++)
			L->list[j - 1] = L->list[j];
		L->size--;
		return 1;
	}
}



int ListGet(SeqList L, int i, DataType* x)
{
	if (i<0 || i>L.size - 1)
	{
		printf("参数i不合法");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}
typedef struct
{
	SeqList Vertices;
	int edge[MaxVertices][MaxVertices];
	int numOfEdges;
}AdjMGraph;

void Initiate(AdjMGraph* G, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				G->edge[i][j] = 0;
			else
				G->edge[i][j] = MaxWeight;
		}
	}
	G->numOfEdges = 0;
	ListInitiate(&G->Vertices);
}
void InsertVertex(AdjMGraph* G, DataType vertex)
{
	LisiInsert(&G->Vertices, G->Vertices.size, vertex);
}
void InsertEdge(AdjMGraph* G, int v1, int v2, int weight)
{
	if (v1 < 0 || v1 >= G->Vertices.size || v2 < 0 || v2 >= G->Vertices.size)
	{
		printf("参数v1或v2越界出错！\n");
		return;
	}
	G->edge[v1][v2] = weight;
	G->numOfEdges++;
}
void DeleteEdge(AdjMGraph* G, int v1, int v2)
{
	if (v1 < 0 || v1 >= G->Vertices.size || v2 < 0 || v2 >= G->Vertices.size || v1 == v2)
	{
		printf("参数v1或者参数v2出错！\n");
		return;
	}
	if (G->edge[v1][v2] == MaxWeight || v1 == v2)
	{
		printf("该边不存在！\n");
		return;
	}
	G->edge[v1][v2] = MaxWeight;
	G->numOfEdges--;
}
int GetFirstVex(AdjMGraph G, int v)
{
	int col;
	if (v < 0 || v >= G.Vertices.size)
	{
		printf("参数v1越界出错！\n");
		return -1;
	}
	for (col = 0; col < G.Vertices.size; col++)
		if (G.edge[v][col] > 0 && G.edge[v][col] < MaxWeight)
			return col;
	return -1;
}
int GetNextVex(AdjMGraph G, int v1, int v2)
{
	int col;
	if (v1 < 0 || v1 >= G.Vertices.size || v2 < 0 || v2 >= G.Vertices.size)
	{
		printf("参数v1或参数v2越界出错！\n");
		return -1;
	}
	for (col = v2 + 1; col < G.Vertices.size; col++)
		if (G.edge[v1][col] > 0 && G.edge[v1][col] < MaxWeight) return col;
	return -1;
}
typedef struct
{
	int row;
	int col;
	int weight;
}RowColWeight;
void Dijkstra(AdjMGraph G, int v0, int distance[], int path[])
{
	int n = G.Vertices.size;
	int* s = (int*)malloc(sizeof(int) * n);
	int minDis, i, j, u;
	for (i = 0; i < n; i++)
	{
		distance[i] = G.edge[v0][i];
		s[i] = 0;
		if (i != v0 && distance[i] < MaxWeight) path[i] = v0;
		else path[i] = -1;
	}
	s[v0] = 1;
	for (i = 1; i < n; i++)
	{
		minDis = MaxWeight;
		for (j = 0; j < n; j++)
			if (s[j] == 0 && distance[j] < minDis)
			{
				u = j;
				minDis = distance[j];
			}
		if (minDis == MaxWeight)return;
		s[u] = 1;
		for (j = 0; j < n; j++)
			if (s[j] == 0 && G.edge[u][j] < MaxWeight && distance[u] + G.edge[u][j] < distance[j])
			{
				distance[j] = distance[u] + G.edge[u][j];
				path[j] = u;
			}
	}
}
void CreatGraph(AdjMGraph* G, DataType V[], int n, RowColWeight E[], int e)
{
	int i, k;
	Initiate(G, n);
	for (i = 0; i < n; i++)
		InsertVertex(G, V[i]);
	for (k = 0; k < e; k++)
		InsertEdge(G, E[k].row, E[k].col, E[k].weight);

}