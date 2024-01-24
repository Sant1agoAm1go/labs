#include "Lab4.h"


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

