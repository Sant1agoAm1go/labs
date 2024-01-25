#include "Lab4.h"


int menu()
{
    int graphType = 1;  
    int operation = 1;
    int inputType = 1;  
    int numVertex = 5;
    int numEdges = 0;
    cout << "Type of grap - oriented graph" << endl << endl;
    cout << "Select input type(1 - auto, 2 - manually): "; cin >> inputType; cout << endl;
    if (inputType == 2) { cout << "Input number of vertex: "; cin >> numVertex; cout << "Input number of edges: "; cin >> numEdges; }
    cout << endl;

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
    while (1)
    {
        cout << "\t\t\t\t\tSelect operation with graph:" << endl;
        cout << "\t\t\t1 - Print" << endl << "\t\t\t2 - addVertex" << endl << "\t\t\t3 - addArc" << endl << "\t\t\t4 - removeVertex" << endl << "\t\t\t5 - removeEdge" << endl << "\t\t\t6 - changeWeight" << endl << "\t\t\t7 - DFS" << endl << "\t\t\t8 - exit" << endl; cin >> operation;
        if (operation < 1 || operation > 15) return 1;
        switch(operation)
        {
            case 1:
            {
                cout << endl;
                graph.PrintUser();
                cout << endl;
                break;
            }
            case 2: 
            {
                cout << endl;
                int vertexUser = 0;
                cout << "Input vertex: "; cin >> vertexUser;
                graph.addVertexUser(vertexUser);
                cout << endl;
                break;
            }
            case 3:
            {
                cout << endl;
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
                cout << endl;
                break;
            }
            case 4:
            {
                cout << endl;
                int vertexUser = 0;
                cout << "Input vertex: "; cin >> vertexUser;
                graph.removeVertexUser(vertexUser);
                cout << endl;
                break;
            }
            case 5:
            {
                cout << endl;
                int v1User = 0;
                int v2User = 0;
                int weight = 0;
                cout << "Input start of edge: "; cin >> v1User;
                cout << "Input end of edge: "; cin >> v2User;
                graph.removeEdgeUser(v1User, v2User);
                cout << endl;
                break;
            }
            case 6:
            {
                cout << endl;
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
                cout << endl;
                break;
            }
            case 7:
            {
                int startVertexUser = 0;
                int endVertexUser = 0;
                cout << "Input start vertex: "; cin >> startVertexUser; 
                cout << "Input end vertex: "; cin >> endVertexUser; 
                if (graph.SearchVertexUser(startVertexUser) == false || graph.SearchVertexUser(endVertexUser) == false) break;
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
            case 8:
            {
                return 0;
                break;
            }
        }
        
    }

    return 1;
}
