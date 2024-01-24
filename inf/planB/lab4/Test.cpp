#include "Lab4.h"


int TestDijkstra()
{
    int flag = 0;
	Graph graph1;
	GenerateUndirectedGraph1(graph1);

    int start = 0;
    int end = 4;
    pair<vector<int>, vector<int>> result = graph1.Dijkstra(start, end);
    vector<int> distances = result.first;
    vector<int> path = result.second;
    if (distances[end] != 4) flag = 1;
    if (path[0] != 0 || path[1] != 3 || path[2] != 4) flag = 1;

    start = 2;
    end = 4;
    result = graph1.Dijkstra(start, end);
    distances = result.first;
    path = result.second;
    if (distances[end] != 5) flag = 1;
    if (path[0] != 2 || path[1] != 3 || path[2] != 4) flag = 1;


    Graph graph2;
    GenerateUndirectedGraph2(graph2);

    start = 0;
    end = 3;
    pair<vector<int>, vector<int>> result2 = graph2.Dijkstra(start, end);
    vector<int> distances2 = result2.first;
    vector<int> path2 = result2.second;
    if (distances2[end] != 7) flag = 1;
    if (path2[0] != 0 || path2[1] != 1 || path2[2] != 3) flag = 1;

    start = 1;
    end = 6;
    result2 = graph2.Dijkstra(start, end);
    distances2 = result2.first;
    path2 = result2.second;
    if (distances2[end] != 5) flag = 1;
    if (path2[0] != 1 || path2[1] != 5 || path2[2] != 6) flag = 1;


    Graph graph3;
    GenerateUndirectedGraph3(graph3);

    start = 0;
    end = 6;
    pair<vector<int>, vector<int>> result3 = graph3.Dijkstra(start, end);
    vector<int> distances3 = result3.first;
    vector<int> path3 = result3.second;
    if (distances3[end] != 3) flag = 1;
    if (path3[0] != 0 || path3[1] != 3 || path3[2] != 6) flag = 1;

    start = 2;
    end = 6;
    result3 = graph3.Dijkstra(start, end);
    distances3 = result3.first;
    path3 = result3.second;
    if (distances3[end] != 4) flag = 1;
    if (path3[0] != 2 || path3[1] != 3 || path3[2] != 6) flag = 1;


    Graph graph4;
    GenerateOrientedGraph1(graph4);

    start = 5;
    end = 3;
    pair<vector<int>, vector<int>> result4 = graph4.Dijkstra(start, end);
    vector<int> distances4 = result4.first;
    vector<int> path4 = result4.second;
    if (distances4[end] != 9) flag = 1;
    if (path4[0] != 5 || path4[1] != 2 || path4[2] != 3) flag = 1;

    start = 2;
    end = 1;
    result4 = graph4.Dijkstra(start, end);
    distances4 = result4.first;
    path4 = result4.second;
    if (distances4[end] != 13) flag = 1;
    if (path4[0] != 2 || path4[1] != 3 || path4[2] != 1) flag = 1;


    Graph graph5;
    GenerateOrientedGraph2(graph5);

    start = 0;
    end = 2;
    pair<vector<int>, vector<int>> result5 = graph5.Dijkstra(start, end);
    vector<int> distances5 = result5.first;
    vector<int> path5 = result5.second;
    if (distances5[end] != 5) flag = 1;
    if (path5[0] != 0 || path5[1] != 1 || path5[2] != 2) flag = 1;

    start = 2;
    end = 4;
    result5 = graph5.Dijkstra(start, end);
    distances5 = result5.first;
    path5 = result5.second;
    if (distances5[end] != 5) flag = 1;
    if (path5[0] != 2 || path5[1] != 3 || path5[2] != 4) flag = 1;

    Graph graph6;
    GenerateOrientedGraph3(graph6);

    start = 0;
    end = 5;
    pair<vector<int>, vector<int>> result6 = graph6.Dijkstra(start, end);
    vector<int> distances6 = result6.first;
    vector<int> path6 = result6.second;
    if (distances6[end] != 6) flag = 1;
    if (path6[0] != 0 || path6[1] != 2 || path6[2] != 5) flag = 1;

    start = 0;
    end = 3;
    result6 = graph6.Dijkstra(start, end);
    distances6 = result6.first;
    path6 = result6.second;
    if (distances6[end] != 5) flag = 1;
    if (path6[0] != 0 || path6[1] != 2 || path6[2] != 3) flag = 1;

    if (flag == 0) return 1;
    else return 0;
}


int TestTopologicalSort()
{
    int flag = 0;

    Graph graph1;
    GenerateUndirectedGraph1(graph1);
    vector<int> topologicalSort1;
    graph1.topologicalSort(topologicalSort1);
    
    if (topologicalSort1.size() != 0) flag = 1;

    Graph graph2;
    GenerateUndirectedGraph2(graph2);
    vector<int> topologicalSort2;
    graph2.topologicalSort(topologicalSort2);

    if (topologicalSort2.size() != 0) flag = 1;

    Graph graph3;
    GenerateUndirectedGraph3(graph3);
    vector<int> topologicalSort3;
    graph3.topologicalSort(topologicalSort3);

    if (topologicalSort3.size() != 0) flag = 1;

    Graph graph4;
    GenerateOrientedGraph1(graph4);
    vector<int> topologicalSort4;
    graph4.topologicalSort(topologicalSort4);
    if (topologicalSort4[0] != 5 || topologicalSort4[1] != 4 || topologicalSort4[2] != 2 || topologicalSort4[3] != 3 || topologicalSort4[4] != 1 || topologicalSort4[5] != 0) flag = 1;


    Graph graph5;
    GenerateOrientedGraph2(graph5);
    vector<int> topologicalSort5;
    graph5.topologicalSort(topologicalSort5);
    if (topologicalSort5.size() != 0) flag = 1;

    Graph graph6;
    GenerateOrientedGraph3(graph6);
    vector<int> topologicalSort6;
    graph6.topologicalSort(topologicalSort6);
    if (topologicalSort6[0] != 0 || topologicalSort6[1] != 2 || topologicalSort6[2] != 4 || topologicalSort6[3] != 5 || topologicalSort6[4] != 3 || topologicalSort6[5] != 1) flag = 1;

    if (flag == 0) return 1;
    else return 0;
}


int TestDFS()
{
    int flag = 0;

    Graph graph1;
    GenerateUndirectedGraph1(graph1);
    int startVertex = 0;
    int endVertex = 4;
    vector<int> path1;
    graph1.DFS(startVertex, endVertex, path1);
    if (path1[0] != 0 || path1[1] != 3 || path1[2] != 4) flag = 1;

    Graph graph2;
    GenerateUndirectedGraph2(graph2);
    startVertex = 0;
    endVertex = 2;
    vector<int> path2;
    graph2.DFS(startVertex, endVertex, path2);
    if (path2[0] != 0 || path2[1] != 1 || path2[2] != 2) flag = 1;

    Graph graph3;
    GenerateUndirectedGraph3(graph3);
    startVertex = 0;
    endVertex = 6;
    vector<int> path3;
    graph3.DFS(startVertex, endVertex, path3);
    if (path3[0] != 0 || path3[1] != 4 || path3[2] != 6) flag = 1;

    Graph graph4;
    GenerateOrientedGraph1(graph4);
    startVertex = 5;
    endVertex = 1;
    vector<int> path4;
    graph4.DFS(startVertex, endVertex, path4);
    if (path4[0] != 5 || path4[1] != 2 || path4[2] != 3 || path4[3] != 1) flag = 1;

    Graph graph5;
    GenerateOrientedGraph2(graph5);
    startVertex = 0;
    endVertex = 5;
    vector<int> path5;
    graph5.DFS(startVertex, endVertex, path5);
    if (path5[0] != 0 || path5[1] != 3 || path5[2] != 4 || path5[3] != 5) flag = 1;

    Graph graph6;
    GenerateOrientedGraph3(graph6);
    startVertex = 0;
    endVertex = 5;
    vector<int> path6;
    graph6.DFS(startVertex, endVertex, path6);
    if (path6[0] != 0 || path6[1] != 2 || path6[2] != 5) flag = 1;

    if (flag == 0) return 1;
    else return 0;
}


int TestBFS()
{
    int flag = 0;

    Graph graph1;
    GenerateUndirectedGraph1(graph1);
    int startVertex = 0;
    int endVertex = 4;
    vector<int> path1;
    graph1.BFS(startVertex, endVertex, path1);
    if (path1[0] != 0 || path1[1] != 1 || path1[2] != 4) flag = 1;

    Graph graph2;
    GenerateUndirectedGraph2(graph2);
    startVertex = 0;
    endVertex = 2;
    vector<int> path2;
    graph2.BFS(startVertex, endVertex, path2);
    if (path2[0] != 0 || path2[1] != 1 || path2[2] != 2) flag = 1;

    Graph graph3;
    GenerateUndirectedGraph3(graph3);
    startVertex = 0;
    endVertex = 6;
    vector<int> path3;
    graph3.BFS(startVertex, endVertex, path3);
    if (path3[0] != 0 || path3[1] != 3 || path3[2] != 6) flag = 1;

    Graph graph4;
    GenerateOrientedGraph1(graph4);
    startVertex = 5;
    endVertex = 1;
    vector<int> path4;
    graph4.BFS(startVertex, endVertex, path4);
    if (path4[0] != 5 || path4[1] != 2 || path4[2] != 3 || path4[3] != 1) flag = 1;

    Graph graph5;
    GenerateOrientedGraph2(graph5);
    startVertex = 0;
    endVertex = 5;
    vector<int> path5;
    graph5.BFS(startVertex, endVertex, path5);
    if (path5[0] != 0 || path5[1] != 3 || path5[2] != 4 || path5[3] != 5) flag = 1;

    Graph graph6;
    GenerateOrientedGraph3(graph6);
    startVertex = 0;
    endVertex = 5;
    vector<int> path6;
    graph6.BFS(startVertex, endVertex, path6);
    if (path6[0] != 0 || path6[1] != 2 || path6[2] != 5) flag = 1;

    if (flag == 0) return 1;
    else return 0;
}

int TestSearchVertex()
{
    int flag = 0;

    Graph graph1;
    GenerateUndirectedGraph1(graph1);
    if (graph1.SearchVertexUser(1) == false) flag = 1;
    if (graph1.SearchVertexUser(2) == false) flag = 1;
    if (graph1.SearchVertexUser(4) == false) flag = 1;
    if (graph1.SearchVertexUser(5)) flag = 1;
    if (graph1.SearchVertexUser(6)) flag = 1;
    if (graph1.SearchVertexUser(10)) flag = 1;

    Graph graph2;
    GenerateUndirectedGraph2(graph2);
    if (graph2.SearchVertexUser(1) == false) flag = 1;
    if (graph2.SearchVertexUser(3) == false) flag = 1;
    if (graph2.SearchVertexUser(4) == false) flag = 1;
    if (graph2.SearchVertexUser(11)) flag = 1;
    if (graph2.SearchVertexUser(9)) flag = 1;
    if (graph2.SearchVertexUser(10)) flag = 1;

    Graph graph3;
    GenerateUndirectedGraph3(graph3);
    if (graph3.SearchVertexUser(1) == false) flag = 1;
    if (graph3.SearchVertexUser(2) == false) flag = 1;
    if (graph3.SearchVertexUser(4) == false) flag = 1;
    if (graph3.SearchVertexUser(11)) flag = 1;
    if (graph3.SearchVertexUser(9)) flag = 1;
    if (graph3.SearchVertexUser(10)) flag = 1;

    Graph graph4;
    GenerateOrientedGraph1(graph4);
    if (graph4.SearchVertexUser(0) == false) flag = 1;
    if (graph4.SearchVertexUser(5) == false) flag = 1;
    if (graph4.SearchVertexUser(4) == false) flag = 1;
    if (graph4.SearchVertexUser(11)) flag = 1;
    if (graph4.SearchVertexUser(9)) flag = 1;
    if (graph4.SearchVertexUser(10)) flag = 1;

    Graph graph5;
    GenerateOrientedGraph2(graph5);
    if (graph5.SearchVertexUser(0) == false) flag = 1;
    if (graph5.SearchVertexUser(5) == false) flag = 1;
    if (graph5.SearchVertexUser(4) == false) flag = 1;
    if (graph5.SearchVertexUser(11)) flag = 1;
    if (graph5.SearchVertexUser(9)) flag = 1;
    if (graph5.SearchVertexUser(10)) flag = 1;

    Graph graph6;
    GenerateOrientedGraph3(graph6);
    if (graph6.SearchVertexUser(0) == false) flag = 1;
    if (graph6.SearchVertexUser(3) == false) flag = 1;
    if (graph6.SearchVertexUser(2) == false) flag = 1;
    if (graph6.SearchVertexUser(11)) flag = 1;
    if (graph6.SearchVertexUser(9)) flag = 1;
    if (graph6.SearchVertexUser(10)) flag = 1;

    if (flag == 0) return 1;
    else return 0;
}

int TestChangeWeight()
{
    int flag = 0;

    Graph graph1;
    GenerateUndirectedGraph1(graph1);
    graph1.ChangeWeightEdgeUser(0, 1, 5);
    graph1.ChangeWeightEdgeUser(3, 1, 7);
    graph1.ChangeWeightEdgeUser(4, 3, 10);
    if (graph1.GetWeightUser(0, 1) != 5) flag = 1;
    if (graph1.GetWeightUser(3, 1) != 7) flag = 1;
    if (graph1.GetWeightUser(4, 3) != 10) flag = 1;

    Graph graph2;
    GenerateUndirectedGraph2(graph2);
    graph2.ChangeWeightEdgeUser(0, 1, 5);
    graph2.ChangeWeightEdgeUser(3, 1, 7);
    graph2.ChangeWeightEdgeUser(1, 4, 10);
    if (graph2.GetWeightUser(0, 1) != 5) flag = 1;
    if (graph2.GetWeightUser(3, 1) != 7) flag = 1;
    if (graph2.GetWeightUser(1, 4) != 10) flag = 1;

    Graph graph3;
    GenerateUndirectedGraph3(graph3);
    graph3.ChangeWeightEdgeUser(0, 1, 5);
    graph3.ChangeWeightEdgeUser(3, 1, 7);
    graph3.ChangeWeightEdgeUser(3, 4, 10);
    if (graph3.GetWeightUser(0, 1) != 5) flag = 1;
    if (graph3.GetWeightUser(3, 1) != 7) flag = 1;
    if (graph3.GetWeightUser(3, 4) != 10) flag = 1;

    Graph graph4;
    GenerateOrientedGraph1(graph4);
    graph4.ChangeWeightArcUser(5, 2, 5);
    graph4.ChangeWeightArcUser(4, 0, 7);
    graph4.ChangeWeightArcUser(3, 1, 10);
    if (graph4.GetWeightUser(5, 2) != 5) flag = 1;
    if (graph4.GetWeightUser(4, 0) != 7) flag = 1;
    if (graph4.GetWeightUser(3, 1) != 10) flag = 1;

    Graph graph5;
    GenerateOrientedGraph2(graph5);
    graph5.ChangeWeightArcUser(5, 2, 6);
    graph5.ChangeWeightArcUser(4, 2, 3);
    graph5.ChangeWeightArcUser(1, 2, 10);
    if (graph5.GetWeightUser(5, 2) != 6) flag = 1;
    if (graph5.GetWeightUser(4, 2) != 3) flag = 1;
    if (graph5.GetWeightUser(1, 2) != 10) flag = 1;

    Graph graph6;
    GenerateOrientedGraph3(graph6);
    graph6.ChangeWeightArcUser(0, 2, 6);
    graph6.ChangeWeightArcUser(2, 3, 3);
    graph6.ChangeWeightArcUser(2, 4, 10);
    if (graph6.GetWeightUser(0, 2) != 6) flag = 1;
    if (graph6.GetWeightUser(2, 3) != 3) flag = 1;
    if (graph6.GetWeightUser(2, 4) != 10) flag = 1;

    if (flag == 0) return 1;
    else return 0;
}

int TestCycle()
{
    int flag = 0;

    Graph graph1;
    GenerateUndirectedGraph1(graph1);
    if (graph1.hasCycle() == false) flag = 1;

    Graph graph2;
    GenerateUndirectedGraph2(graph2);
    if (graph2.hasCycle() == false) flag = 1;

    Graph graph3;
    GenerateUndirectedGraph3(graph3);
    if (graph3.hasCycle() == false) flag = 1;

    Graph graph4;
    GenerateOrientedGraph1(graph4);
    if (graph4.hasCycle()) flag = 1;

    Graph graph5;
    GenerateOrientedGraph2(graph5);
    if (graph5.hasCycle() == false) flag = 1;

    Graph graph6;
    GenerateOrientedGraph3(graph6);
    if (graph6.hasCycle()) flag = 1;

    if (flag == 0) return 1;
    else return 0;
}

int TestAddRemoveVertex()
{
    int flag = 0;

    Graph graph1;
    GenerateUndirectedGraph1(graph1);
    graph1.addVertexUser(10);
    graph1.addVertexUser(5);
    graph1.addVertexUser(100);
    if (graph1.SearchVertexUser(10) == false) flag = 1;
    if (graph1.SearchVertexUser(5) == false) flag = 1;
    if (graph1.SearchVertexUser(100) == false) flag = 1;
    graph1.removeVertexUser(0);
    graph1.removeVertexUser(100);
    if (graph1.SearchVertexUser(0)) flag = 1;
    if (graph1.SearchVertexUser(100)) flag = 1;

    Graph graph2;
    GenerateUndirectedGraph2(graph2);
    graph2.addVertexUser(10);
    graph2.addVertexUser(7);
    graph2.addVertexUser(100);
    if (graph2.SearchVertexUser(10) == false) flag = 1;
    if (graph2.SearchVertexUser(7) == false) flag = 1;
    if (graph2.SearchVertexUser(100) == false) flag = 1;
    graph2.removeVertexUser(0);
    graph2.removeVertexUser(100);
    if (graph2.SearchVertexUser(0)) flag = 1;
    if (graph2.SearchVertexUser(100)) flag = 1;

    Graph graph3;
    GenerateUndirectedGraph3(graph3);
    graph3.addVertexUser(11);
    graph3.addVertexUser(7);
    graph3.addVertexUser(100);
    if (graph3.SearchVertexUser(11) == false) flag = 1;
    if (graph3.SearchVertexUser(7) == false) flag = 1;
    if (graph3.SearchVertexUser(100) == false) flag = 1;
    graph3.removeVertexUser(0);
    graph3.removeVertexUser(7);
    if (graph3.SearchVertexUser(0)) flag = 1;
    if (graph3.SearchVertexUser(7)) flag = 1;

    Graph graph4;
    GenerateOrientedGraph1(graph4);
    graph4.addVertexUser(11);
    graph4.addVertexUser(7);
    graph4.addVertexUser(100);
    if (graph4.SearchVertexUser(11) == false) flag = 1;
    if (graph4.SearchVertexUser(7) == false) flag = 1;
    if (graph4.SearchVertexUser(100) == false) flag = 1;
    graph4.removeVertexUser(0);
    graph4.removeVertexUser(7);
    if (graph4.SearchVertexUser(0)) flag = 1;
    if (graph4.SearchVertexUser(7)) flag = 1;

    Graph graph5;
    GenerateOrientedGraph2(graph5);
    graph5.addVertexUser(11);
    graph5.addVertexUser(7);
    graph5.addVertexUser(100);
    if (graph5.SearchVertexUser(11) == false) flag = 1;
    if (graph5.SearchVertexUser(7) == false) flag = 1;
    if (graph5.SearchVertexUser(100) == false) flag = 1;
    graph5.removeVertexUser(0);
    graph5.removeVertexUser(7);
    if (graph5.SearchVertexUser(0)) flag = 1;
    if (graph5.SearchVertexUser(7)) flag = 1;


    Graph graph6;
    GenerateOrientedGraph3(graph6);
    graph6.addVertexUser(11);
    graph6.addVertexUser(7);
    graph6.addVertexUser(100);
    if (graph6.SearchVertexUser(11) == false) flag = 1;
    if (graph6.SearchVertexUser(7) == false) flag = 1;
    if (graph6.SearchVertexUser(100) == false) flag = 1;
    graph6.removeVertexUser(0);
    graph6.removeVertexUser(7);
    if (graph6.SearchVertexUser(0)) flag = 1;
    if (graph6.SearchVertexUser(7)) flag = 1;

    if (flag == 0) return 1;
    else return 0;
}

