#include "Laba4.h"


void DijkstraFullUser(Graph& graph, int rootNameUser)
{
    int rootNameGraph = graph.getIndexUser(rootNameUser);
    vector<int> namesGraph;
    graph.getVertexNamesGraph(namesGraph);
    for (int i = 0; i < namesGraph.size(); i++)
    {
        if (rootNameGraph == namesGraph[i]) continue;

        pair<vector<int>, vector<int>> result = graph.Dijkstra(rootNameGraph, namesGraph[i]);
        vector<int> distances = result.first;
        vector<int> path = result.second;

        cout << "Distance from vertex " << rootNameUser << " to vertex " << graph.getUser(namesGraph[i]) << " = " << distances[namesGraph[i]] << endl;
        cout << "Path: { ";
        for (int vertex : path)
        {
            cout << graph.getUser(vertex) << " ";
        }
        cout << "}" << endl;
    }

    return;
}