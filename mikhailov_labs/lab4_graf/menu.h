#ifndef TRAINING_SFML_MENU_H
#define TRAINING_SFML_MENU_H
#include <iostream>
using namespace std;

void print_choose_prog() {
    cout << "_____________________________________________________________\n";
    cout << "Select the actions:\n" <<
         "1) Graph\n" <<
         "2) Tests\n" <<
         "3) Tic Tac Toe\n" <<
         "Enter: ";
}

void print_choose_struct() {
    cout << "_____________________________________________________________\n";
    cout << "Select the actions:\n" <<
         "1) Digraph\n" <<
         "2) Non-Digraph\n" <<
         "Enter: ";
}

void print_prog_action_graph() {
    cout << "_____________________________________________________________\n";
    cout << "Select the actions:\n" <<
         "1) Finding the spanning tree of a graph\n" <<
         "2) Finding connected components of a graph\n" <<
         "3) Finding the single best path with the highest throughput\n" <<
         "4) Finding multiple paths to achieve a given total throughput\n" <<
         "5) Print Graph\n" <<
         "6) Exit\n" <<
         "Enter: ";
}



#endif //TRAINING_SFML_MENU_H
