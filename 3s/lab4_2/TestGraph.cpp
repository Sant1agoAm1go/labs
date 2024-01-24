#include <iostream>
#include "Graph.h"
#include "STLHasher.h"
using namespace std;

int main() {
	IHasher<int>* hash = new STLHasher<int>();
	Graph<int, int, int> graph1(hash);
}