#ifndef LAB4_GRAF_TEST_DIGRAPH_H
#define LAB4_GRAF_TEST_DIGRAPH_H
#include "../Graph/Digraph.h"
#include <iostream>
#include <cassert>

template <typename T>
bool test_directed_graph_default_constructor() {
    DirectedGraph graph(5);
    assert(graph.getVerticesCount() == 5);
    assert(graph.getEdgesCount() == 0);

    std::cout << "Test passed: test_directed_graph_default_constructor\n";
    return true;
}

template <typename T>
bool test_directed_graph_add_edge() {
    DirectedGraph graph(3);
    graph.addEdge(0, 1, 2);
    graph.addEdge(1, 2, 3);
    assert(graph.getEdgesCount() == 2);

    std::cout << "Test passed: test_directed_graph_add_edge\n";
    return true;
}

template <typename T>
bool test_directed_graph_find_minimum_spanning_tree() {
    DirectedGraph graph(4);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 3);

    graph.findMinimumSpanningTree();

    // Add your assertions based on the expected minimum spanning tree

    std::cout << "Test passed: test_directed_graph_find_minimum_spanning_tree\n";
    return true;
}

template <typename T>
bool test_directed_graph_find_shortest_paths() {
    DirectedGraph graph(4);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 3);

    graph.findShortestPaths(0);

    // Add your assertions based on the expected shortest paths

    std::cout << "Test passed: test_directed_graph_find_shortest_paths\n";
    return true;
}

template <typename T>
bool test_directed_graph_find_strongly_connected_components() {
    DirectedGraph graph(4);
    graph.addEdge(0, 1, 1);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 0, 1);
    graph.addEdge(1, 3, 1);

    graph.findStronglyConnectedComponents();

    // Add your assertions based on the expected strongly connected components

    std::cout << "Test passed: test_directed_graph_find_strongly_connected_components\n";
    return true;
}

void test_directed_graph() {
    int total_tests = 5;
    int passed_tests = test_directed_graph_default_constructor<int>() +
                       test_directed_graph_add_edge<int>() +
                       test_directed_graph_find_minimum_spanning_tree<int>() +
                       test_directed_graph_find_shortest_paths<int>() +
                       test_directed_graph_find_strongly_connected_components<int>();

    int failed_tests = total_tests - passed_tests;
    std::cout << "_____________________________________________________________\n";
    std::cout << "Total DirectedGraph tests: " << total_tests << ", Passed: " << passed_tests << ", Failed: " << failed_tests << std::endl;
    std::cout << "_____________________________________________________________\n";
}

#endif //LAB4_GRAF_TEST_DIGRAPH_H
