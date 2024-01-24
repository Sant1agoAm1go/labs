#include "Laba4.h"

int main()
{
    while (1)
    {
        if (menu() == 1) continue; else break;
    }

    assert(TestDijkstra() == 1);
    assert(TestTopologicalSort() == 1);
    assert(TestDFS() == 1);
    assert(TestBFS() == 1);
    assert(TestSearchVertex() == 1);
    assert(TestChangeWeight() == 1);
    assert(TestCycle() == 1);
    assert(TestAddRemoveVertex() == 1);
    cout << "All tests passed";
    return 0;
   
}