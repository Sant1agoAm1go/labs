#ifndef LAB4_GRAF_ACTIONS_H
#define LAB4_GRAF_ACTIONS_H
#include <iostream>
#include "menu.h"
#include "handlers.h"
#include <sstream>
#include "Graph/Digraph.h"
#include "Graph/NonDigraph.h"
void digraph_actions();
void non_digraph_actions();
void manualFillGraph(DirectedGraph& graph);
void manualFillNONDIGraph(NonDiGraph& graph);

void program_work() {
    int var_prog = 0;
    print_choose_struct();
    handlerInput(&var_prog, 1, 2);
    if (var_prog == 1)
        digraph_actions();
    else
        non_digraph_actions();
}


void digraph_actions() {
    DirectedGraph graph(0);
    int var_generation = 0;
    manualFillGraph(graph);
    int var_action = 0;
    do {
        print_prog_action_graph();
        handlerInput(&var_action, 1, 6);
        if (var_action == 1){
            graph.findMinimumSpanningTree();
        } else if (var_action == 2){
            graph.findStronglyConnectedComponents();
        } else if (var_action == 3){
            int startVertex, endVertex;

            // Ввод начальной вершины
            cout << "Enter starting vertex:";
            handlerInput(&startVertex, 0, graph.getVerticesCount() - 1);

            // Ввод конечной вершины
            cout << "Enter end vertex:";
            handlerInput(&endVertex, 0, graph.getVerticesCount() - 1);

            graph.findShortestPathWithMaxCapacity(startVertex, endVertex);
        } else if (var_action == 4){
            int startVertex, endVertex, requiredCapacity;

            // Ввод начальной вершины
            cout << "Enter starting vertex:";
            handlerInput(&startVertex, 0, graph.getVerticesCount() - 1);
            graph.findShortestPaths(startVertex);
        } else if (var_action == 5){
            graph.printGraph();
        }
    } while (var_action != 6);
}



void non_digraph_actions() {
    NonDiGraph graph(0);

    manualFillNONDIGraph(graph);

    int var_action = 0;
    do {
        print_prog_action_graph();
        handlerInput(&var_action, 1, 6);

        if (var_action == 1) {
            graph.findMinimumSpanningTree();
        } else if (var_action == 2) {
            graph.findConnectedComponents();
        } else if (var_action == 3) {
            int startVertex, endVertex;

            // Ввод начальной вершины
            std::cout << "Enter starting vertex:";
            handlerInput(&startVertex, 0, graph.getVerticesCount() - 1);

            // Ввод конечной вершины
            std::cout << "Enter end vertex:";
            handlerInput(&endVertex, 0, graph.getVerticesCount() - 1);

            graph.findShortestPathWithMaxCapacity(startVertex, endVertex);
        } else if (var_action == 4) {
            int startVertex, endVertex, requiredCapacity;

            // Ввод начальной вершины
            std::cout << "Enter starting vertex:";
            handlerInput(&startVertex, 0, graph.getVerticesCount() - 1);

            // Ввод конечной вершины
            std::cout << "Enter end vertex:";
            handlerInput(&endVertex, 0, graph.getVerticesCount() - 1);

            // Ввод суммарной пропускной способности
            std::cout << "Enter required capacity:";
            handlerInput(&requiredCapacity, 1, INT_MAX);

            graph.findPathsWithTotalCapacity(startVertex, endVertex, requiredCapacity);
        } else if (var_action == 5) {
            graph.printGraph();
        }
    } while (var_action != 6);
}



void manualFillGraph(DirectedGraph& graph) {
    int numVertices;
    cout << "Enter the number of vertices:";
    cin >> numVertices;

    graph.setVertices(numVertices);

    for (int i = 0; i < numVertices; ++i) {
        cout << "Enter, separated by commas, which vertices the vertex will be associated with " << i << ":";

        string input;
        getline(cin >> ws, input);

        vector<int> connectedVertices;
        stringstream ss(input);
        int vertex;

        while (ss >> vertex) {
            connectedVertices.push_back(vertex);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }

        cout << "Enter edge weight:\n";

        for (int connectedVertex : connectedVertices) {
            int weight;
            cout << "Edge weight " << i << "-" << connectedVertex << ":";
            cin >> weight;

            graph.addEdge(i, connectedVertex, weight);
        }
    }
}

void manualFillNONDIGraph(NonDiGraph& graph) {
    int numVertices;
    cout << "Enter the number of vertices:";
    cin >> numVertices;

    graph.setVertices(numVertices);

    for (int i = 0; i < numVertices; ++i) {
        cout << "Enter, separated by commas, which vertices the vertex will be associated with " << i << ":";

        string input;
        getline(cin >> ws, input);

        vector<int> connectedVertices;
        stringstream ss(input);
        int vertex;

        while (ss >> vertex) {
            connectedVertices.push_back(vertex);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }

        cout << "Enter edge weight:\n";

        for (int connectedVertex : connectedVertices) {
            int weight;
            cout << "Edge weight " << i << "-" << connectedVertex << ":";
            cin >> weight;

            graph.addEdge(i, connectedVertex, weight);
        }
    }
}
#endif //LAB4_GRAF_ACTIONS_H
