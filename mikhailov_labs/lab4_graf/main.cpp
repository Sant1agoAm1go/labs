//"C:/Windows/Fonts/Arial.ttf"
#include "menu.h"
#include "handlers.h"
#include "Tests/tests.h"
#include "actions.h"
#include "Graph/Digraph.h"
#include "Tic Tac Toe/TicTacToe.h"

int main() {
    int var_prog = 0;
    print_choose_prog();
    handlerInput(&var_prog, 1, 3);
    if (var_prog == 1)
        program_work();
    else if (var_prog == 2)
        tests();
    else
        start_game();
}

//int main() {
//    DirectedGraph graph(7);
//
//    graph.addEdge(0, 1, 4);
//    graph.addEdge(0, 2, 3);
//    graph.addEdge(1, 2, 2);
//    graph.addEdge(1, 3, 5);
//    graph.addEdge(2, 3, 1);
//    graph.addEdge(2, 4, 6);
//    graph.addEdge(3, 4, 4);
//    graph.addEdge(4, 0, 7);
//    graph.addEdge(4, 5, 2);
//    graph.addEdge(5, 6, 3);
//    graph.addEdge(6, 4, 1);
//
//    std::cout << "Adjacency matrix:" << std::endl;
//    graph.printGraph();
//
//    std::cout << std::endl;
//
//    graph.findMinimumSpanningTree();
//
//    std::cout << std::endl;
//
//    graph.findStronglyConnectedComponents();
//
//    std::cout << std::endl;
//
//    graph.findShortestPathWithMaxCapacity(0, 6);
//
//    std::cout << std::endl;
//
//    graph.findPathsWithTotalCapacity(0, 6, 10);
//    return 0;
//}