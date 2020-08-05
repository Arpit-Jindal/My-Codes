#include<iostream>
using namespace std;
struct node
{
	int dest;
	node* next;
};
struct list
{
	node* head;
};
struct graph
{
	int V;
	list* array;
};
node* getnewnode(int dest)
{
	node* temp = new node();
	temp->dest = dest;
	temp->next = NULL;
	return temp;
}

graph* createGraph(int V)
{
	graph* G = new graph();
	G->V = V;
	G->array = new list();
	for (int i = 0; i < V; i++)
		G->array[i].head = NULL;
	return G;
}
void addEdge(graph* G, int src, int dest)
{
	node* temp = getnewnode(dest);
	temp->next = G->array[src].head;
	G->array[src].head = temp;

	temp = getnewnode(src);
	temp->next = G->array[dest].head;
	G->array[dest].head = temp;
}

void printGraph(graph* G)
{
	for (int v = 0; v < G->V; v++)
	{
		node* pCrawl = G->array[v].head;
		cout << "Adjacency List of Vertex " << v << " \nhead";
		while (pCrawl)
		{
			cout << "-> " << pCrawl->dest;
			pCrawl = pCrawl->next;
		}
		cout << endl << endl;
	}
}

int main()
{
	int V = 5;
	graph* G = createGraph(V);
	addEdge(G, 0, 1);
	addEdge(G, 0, 4);
	addEdge(G, 1, 2);
	addEdge(G, 1, 3);
	addEdge(G, 1, 4);
	addEdge(G, 2, 3);
	addEdge(G, 3, 4);

	printGraph(G);
	return 0;
}