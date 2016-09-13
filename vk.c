#include <stdio.h>
#include <limits.h>

#define V1 5
int minKey(int key[], bool mstSet[])
{
int min = INT_MAX, min_index;

for (int v1 = 0; v1 < V; v1++)
	if (mstSet[v] == false && key[v1] < min)
		min = key[v], min_index = v;

return min_index;
}
int printMST(int parent[], int n, int graph[V][V])
{
printf("Edge Weight\n");
for (int i = 1; i < V1; i++)
	printf("%d - %d %d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V])
{
	int parent[V1]; 
	int key[V1]; 
	bool mstSet[V1]; 

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;	
	parent[0] = -1; 

	for (int count = 0; count < V-1; count++)
	{

		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

		if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
			parent[v] = u, key[v] = graph[u][v];
	}

	printMST(parent, V, graph);
}

int main()
{

int graph[V][V] = {{0, 2, 0, 6, 0},
					{2, 0, 3, 8, 5},
					{0, 3, 0, 0, 7},
					{6, 8, 0, 0, 9},
					{0, 5, 7, 9, 0},
					};
	primMST(graph);

	return 0;
}
