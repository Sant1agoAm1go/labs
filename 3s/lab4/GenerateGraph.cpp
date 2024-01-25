#include "Laba4.h"


void CreateGraphManuallyArc(Graph& graph, int numEdges)
{
	int name = 0;
	int nameV2 = 0;
	int weight = 0;
	for (int i = 0; i < numEdges; i++)
	{
		cout << "Input num vertex(start of edge): "; cin >> name; 
		cout << "Begin of edge is: " << name; cout << endl;
		cout << "Input end of edge: "; cin >> nameV2;
		cout << "Input weight of edge: "; cin >> weight;
		graph.addVertexUser(name);
		graph.addVertexUser(nameV2);
		graph.addArcUser(name, nameV2, weight);
	}
	return;
}

void CreateGraphManuallyEdge(Graph& graph, int numEdges)
{
	int name = 0;
	int nameV2 = 0;
	int weight = 0;
	for (int i = 0; i < numEdges; i++)
	{
		cout << "Input num vertex(start of edge): "; cin >> name; 
		cout << "Begin of edge is: " << name; cout << endl;
		cout << "Input end of edge: "; cin >> nameV2;
		cout << "Input weight of edge: "; cin >> weight;
		graph.addVertexUser(name);
		graph.addVertexUser(nameV2);
		graph.addEdgeUser(name, nameV2, weight);
	}
	return;
}



void GenerateOrientedGraph1(Graph& graph)
{
	graph.addVertexUser(0);
	graph.addVertexUser(1);
	graph.addVertexUser(2);
	graph.addVertexUser(3);
	graph.addVertexUser(4);
	graph.addVertexUser(5);
	graph.addArcUser(5, 2, 4);
	graph.addArcUser(5, 0, 1);
	graph.addArcUser(2, 3, 5);
	graph.addArcUser(3, 1, 8);
	graph.addArcUser(4, 0, 5);
	graph.addArcUser(4, 1, 4);
	return;
}

void GenerateOrientedGraph2(Graph& graph)
{
	graph.addVertexUser(0);
	graph.addVertexUser(1);
	graph.addVertexUser(2);
	graph.addVertexUser(3);
	graph.addVertexUser(4);
	graph.addVertexUser(5);
	graph.addArcUser(0, 1, 2);
	graph.addArcUser(0, 3, 7);
	graph.addArcUser(1, 2, 3);
	graph.addArcUser(2, 3, 1);
	graph.addArcUser(2, 0, 6);
	graph.addArcUser(3, 4, 4);
	graph.addArcUser(4, 2, 7);
	graph.addArcUser(4, 5, 8);
	graph.addArcUser(5, 2, 5);
	return;
}

void GenerateOrientedGraph3(Graph& graph)
{
	graph.addVertexUser(0);
	graph.addVertexUser(1);
	graph.addVertexUser(2);
	graph.addVertexUser(3);
	graph.addVertexUser(4);
	graph.addVertexUser(5);
	graph.addArcUser(0, 1, 1);
	graph.addArcUser(0, 2, 2);
	graph.addArcUser(2, 3, 3);
	graph.addArcUser(2, 4, 7);
	graph.addArcUser(2, 5, 4);
	graph.addArcUser(4, 5, 9);

	return;
}

void GenerateUndirectedGraph1(Graph& graph)
{
	graph.addVertexUser(0);
	graph.addVertexUser(1);
	graph.addVertexUser(2);
	graph.addVertexUser(3);
	graph.addVertexUser(4);
	graph.addEdgeUser(0, 1, 4);
	graph.addEdgeUser(0, 2, 1);
	graph.addEdgeUser(0, 3, 1);
	graph.addEdgeUser(2, 3, 2);
	graph.addEdgeUser(1, 3, 5);
	graph.addEdgeUser(3, 4, 3);
	graph.addEdgeUser(1, 4, 3);
	return;
}

void GenerateUndirectedGraph2(Graph& graph)
{
	graph.addVertexUser(0);
	graph.addVertexUser(1);
	graph.addVertexUser(2);
	graph.addVertexUser(3);
	graph.addVertexUser(4);
	graph.addVertexUser(5);
	graph.addVertexUser(6);
	graph.addEdgeUser(0, 1, 2);
	graph.addEdgeUser(1, 2, 3);
	graph.addEdgeUser(1, 5, 1);
	graph.addEdgeUser(1, 4, 4);
	graph.addEdgeUser(1, 3, 5);
	graph.addEdgeUser(2, 6, 6);
	graph.addEdgeUser(6, 5, 4);
	graph.addEdgeUser(3, 5, 7);
	return;
}

void GenerateUndirectedGraph3(Graph& graph)
{
	graph.addVertexUser(0);
	graph.addVertexUser(1);
	graph.addVertexUser(2);
	graph.addVertexUser(3);
	graph.addVertexUser(4);
	graph.addVertexUser(5);
	graph.addVertexUser(6);
	graph.addEdgeUser(0, 1, 5);
	graph.addEdgeUser(0, 2, 4);
	graph.addEdgeUser(0, 3, 1);
	graph.addEdgeUser(0, 4, 6);
	graph.addEdgeUser(2, 1, 3);
	graph.addEdgeUser(2, 3, 2);
	graph.addEdgeUser(1, 5, 7);
	graph.addEdgeUser(1, 3, 9);
	graph.addEdgeUser(3, 5, 4);
	graph.addEdgeUser(3, 6, 2);
	graph.addEdgeUser(4, 3, 8);
	graph.addEdgeUser(4, 6, 7);
	return;
}
