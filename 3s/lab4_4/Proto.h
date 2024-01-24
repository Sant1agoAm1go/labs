#pragma once
#include "Laba4.h"

struct Vertex;
class Edge;
class Graph;

int menu();

void CreateGraphManuallyEdge(Graph& graph, int numEdges);
void CreateGraphManuallyArc(Graph& graph, int numEdges);
void GenerateOrientedGraph1(Graph& graph);
void GenerateUndirectedGraph1(Graph& graph);
void GenerateOrientedGraph2(Graph& graph);
void GenerateUndirectedGraph2(Graph& graph);
void GenerateOrientedGraph3(Graph& graph);
void GenerateUndirectedGraph3(Graph& graph);
void DijkstraFullUser(Graph& graph, int rootNameUser);

int TestDijkstra();
int TestTopologicalSort();
int TestDFS();
int TestBFS();
int TestSearchVertex();
int TestChangeWeight();
int TestCycle();
int TestAddRemoveVertex();