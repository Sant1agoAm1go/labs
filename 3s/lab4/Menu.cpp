#include "Laba4.h"


int menu()
{
    int graphType = 1;  //1 - ориентированный, 2 - неориентированный
    int operation = 1;
    int inputType = 1;  //1 - auto, 2 - manually
    int numVertex = 5;
    int numEdges = 0;
    cout << "Select type of graph(1 - oriented graph, 2 - undirected graph, 3 - exit): ";
    cin >> graphType;
    cout << "Select input type(1 - auto, 2 - manually): "; cin >> inputType;
    if (inputType == 2) { cout << "Input number of vertex: "; cin >> numVertex; cout << "Input number of edges: "; cin >> numEdges; }

    if (graphType < 1 || graphType > 3) return 1;
    if (inputType < 1 || graphType > 2) return 1;

    Graph graph;
    if (inputType == 1 && graphType == 1)
    {
        GenerateOrientedGraph1(graph);
    }
    if (inputType == 2 && graphType == 1)
    {
        CreateGraphManuallyArc(graph, numEdges);
    }
    if (inputType == 1 && graphType == 2)
    {
        GenerateUndirectedGraph1(graph);
    }
    if (inputType == 2 && graphType == 2)
    {
        CreateGraphManuallyEdge(graph, numEdges);
    }
    while (1)
    {
        cout << "Select operation with graph(1 - topological sort, 2 - DFS, 3 - BFS, 4 - Print, 5 - addVertex, 6 - addEdge/Arc, 7 - removeVertex," << endl; 
        cout << "8 - removeEdge, 9 - searchVertex, 10 - changeWeight, 11 - Dijkstra, 12 - FloydWarshall, 13 - cycle, 14 - DijkstraFull, 15 - exit): "; cin >> operation;
        if (operation < 1 || operation > 15) return 1;
        switch(operation)
        {
            case 1:
            {
                vector<int> topologicalSort;
                graph.topologicalSort(topologicalSort);
                if (topologicalSort.size() == 0){ cout << "Graph has cycle" << endl; break; }
                cout << "{ ";
                for (int i = 0; i < topologicalSort.size(); i++)
                {
                    cout << topologicalSort[i] << " ";
                }
                cout << "}";
                cout << endl;
                break;
            }
            case 2:
            {
                int startVertexUser = 0;
                int endVertexUser = 0;
                cout << "Input start vertex: "; cin >> startVertexUser; 
                cout << "Input end vertex: "; cin >> endVertexUser; 
                if (graph.SearchVertexUser(startVertexUser) == false || graph.SearchVertexUser(endVertexUser) == false) break;
                //vector<int> DFS;
                int startVertexGraph = graph.getIndexUser(startVertexUser);
                int endVertexGraph = graph.getIndexUser(endVertexUser);
                vector<int> path;
                cout << "DFS: "; graph.DFS(startVertexGraph, endVertexGraph, path);
                cout << "{ ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout << graph.getUser(path[i]) << " ";
                }
                cout << "}";
                cout << endl;
                break;
            }
            case 3:
            {

                int startVertexUser = 0;
                int endVertexUser = 0;
                cout << "Input start vertex: "; cin >> startVertexUser; 
                cout << "Input end vertex: "; cin >> endVertexUser; 
                if (graph.SearchVertexUser(startVertexUser) == false || graph.SearchVertexUser(endVertexUser) == false) break;
                //vector<int> BFS;
                int startVertexGraph = graph.getIndexUser(startVertexUser);
                int endVertexGraph = graph.getIndexUser(endVertexUser);
                vector<int> path;
                cout << "BFS: "; graph.BFS(startVertexGraph, endVertexGraph, path);
                cout << "{ ";
                for (int i = 0; i < path.size(); i++)
                {
                    cout << graph.getUser(path[i]) << " ";
                }
                cout << "}";
                cout << endl;
                break;
            }
            case 4:
            {
                graph.PrintUser();
                break;
            }
            case 5: 
            {
                int vertexUser = 0;
                cout << "Input vertex: "; cin >> vertexUser;
                graph.addVertexUser(vertexUser);
                break;
            }
            case 6:
            {
                int v1User = 0;
                int v2User = 0;
                int weight = 0;
                if (graphType == 1)
                {
                    cout << "Input start of arc: "; cin >> v1User;
                    cout << "Input end of arc: "; cin >> v2User;
                    cout << "Input weight: "; cin >> weight;
                    graph.addArcUser(v1User, v2User, weight);
                }
                else
                {
                    cout << "Input start of edge: "; cin >> v1User;
                    cout << "Input end of edge: "; cin >> v2User;
                    cout << "Input weight: "; cin >> weight;
                    graph.addEdgeUser(v1User, v2User, weight);
                }
                break;
            }
            case 7:
            {
                int vertexUser = 0;
                cout << "Input vertex: "; cin >> vertexUser;
                graph.removeVertexUser(vertexUser);
                break;
            }
            case 8:
            {
                int v1User = 0;
                int v2User = 0;
                int weight = 0;
                cout << "Input start of edge: "; cin >> v1User;
                cout << "Input end of edge: "; cin >> v2User;
                graph.removeEdgeUser(v1User, v2User);
                break;
            }
            case 9:
            {
                int vertexUser = 0;
                cout << "Input vertex to search: "; cin >> vertexUser;
                graph.SearchVertexUser(vertexUser);
                break;
            }
            case 10:
            {
                int v1User = 0;
                int v2User = 0;
                int weight = 0;
                if (graphType == 1)
                {
                    cout << "Input start of arc: "; cin >> v1User;
                    cout << "Input end of arc: "; cin >> v2User;
                    cout << "Input weight: "; cin >> weight;
                    if (graph.SearchVertexUser(v1User) == false || graph.SearchVertexUser(v2User) == false) break;
                    graph.ChangeWeightArcUser(v1User, v2User, weight);
                }
                else
                {
                    cout << "Input start of edge: "; cin >> v1User;
                    cout << "Input end of edge: "; cin >> v2User;
                    cout << "Input weight: "; cin >> weight;
                    if (graph.SearchVertexUser(v1User) == false || graph.SearchVertexUser(v2User) == false) break;
                    graph.ChangeWeightEdgeUser(v1User, v2User, weight);
                }
                break;
            }
            case 11:
            {
                int startUser = 0;
                int endUser = 0;
                cout << "Input start vertex: "; cin >> startUser;
                cout << "Input end vertex: "; cin >> endUser;
                if (graph.SearchVertexUser(startUser) == false || graph.SearchVertexUser(endUser) == false) break;

                int startGraph = graph.getIndexUser(startUser);
                int endGraph = graph.getIndexUser(endUser);

                pair<vector<int>, vector<int>> result = graph.Dijkstra(startGraph, endGraph);
                vector<int> distances = result.first;
                vector<int> path = result.second;
                if (distances[endGraph] == INT_MAX) 
                {
                    cout << "No path to vertex" << graph.getUser(endGraph) << endl; break;
                }
                cout << "Distance from vertex " << graph.getUser(startGraph) << " to vertex " << graph.getUser(endGraph) << " = " << distances[endGraph] << endl;
                cout << "Path: ";
                for (int vertex : path) {
                    cout << graph.getUser(vertex) << " ";
                }
                cout << endl;
                break;
            }
            case 12:
            {
                int startUser = 0;
                int endUser = 0;
                cout << "Input start vertex: "; cin >> startUser;
                cout << "Input end vertex: "; cin >> endUser;
                if (graph.SearchVertexUser(startUser) == false || graph.SearchVertexUser(endUser) == false) break;
                int startGraph = graph.getIndexUser(startUser);
                int endGraph = graph.getIndexUser(endUser);
                graph.floydWarshall(startGraph, endGraph);
                break;
            }
            case 13:
            {
                if (graph.hasCycle()) cout << "Graph has cycle";
                else cout << "Graph has not cycle";
                cout << endl;
                break;
            }
            case 14:
            {
                int startUser = 0;
                cout << "Input start vertex: "; cin >> startUser;
                if (graph.SearchVertexUser(startUser) == false) break;
                DijkstraFullUser(graph, startUser);
                break;
            }
            case 15:
            {
                return 0;
                break;
            }
        }//switch
        
    }// while

    return 1;
}
