#pragma once
typedef struct
{
	int weight;
	int flag;
	int parent;
	int leftchild;
	int rightchild;
}haffnode;
typedef struct
{
	int bit[maxbit];
	int start;
	int weight;
}code;
void haffman(int weight[], int n, haffnode hafftree[])
{
	int i, j, m1, m2, x1, x2;
	//≥ı ºªØ
	for (i = 0; i < 2 * n - 1; i++)
	{
		if (i < n)
			hafftree[i].weight = weight[i];
		else
			hafftree[i].weight = 0;
		hafftree[i].parent = -1;
		hafftree[i].flag = 0;
		hafftree[i].leftchild = -1;
		hafftree[i].rightchild = -1;
	}
	//
	for (i = 0; i < n - 1; i++)
	{
		m1 = m2 = maxvalue;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++)
		{
			if (hafftree[j].weight < m1 && hafftree[j].flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = hafftree[j].weight;
				x1 = j;
			}
			else if (hafftree[j].weight < m2 && hafftree[j].flag == 0)
			{
				m2 = hafftree[j].weight;
				x2 = j;
			}
		}
		hafftree[x1].parent = n + i;
		hafftree[x2].parent = n + i;
		hafftree[x1].flag = 1;
		hafftree[x2].flag = 1;
		hafftree[n + i].weight = hafftree[x1].weight + hafftree[x2].weight;
		hafftree[n + i].leftchild = x1;
		hafftree[n + i].rightchild = x2;

	}
}
void haffmancode(haffnode hafftree[], int n, code haffcode[])
{
	code* cd = (code*)malloc(sizeof(code));
	int i, j, child, parent;
	for (i = 0; i < n; i++)
	{
		cd->start = n - 1;
		cd->weight = hafftree[i].weight;
		child = i;
		parent = hafftree[child].parent;
		while (parent != -1)
		{
			if (hafftree[parent].leftchild == child)
				cd->bit[cd->start] = 0;
			else
				cd->bit[cd->start] = 1;
			cd->start--;
			child = parent;
			parent = hafftree[child].parent;
		}
		for (j = cd->start + 1; j < n; j++)
			haffcode[i].bit[j] = cd->bit[j];
		haffcode[i].start = cd->start + 1;
		haffcode[i].weight = cd->weight;
	}
}