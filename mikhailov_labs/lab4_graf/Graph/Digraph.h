#ifndef LAB4_GRAF_DIGRAPH_H
#define LAB4_GRAF_DIGRAPH_H
using namespace std;
#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <algorithm>

#include <iostream>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <algorithm>

class DirectedGraph {
private:
    int vertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    DirectedGraph(int numVertices) : vertices(numVertices) {
        adjacencyMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void setVertices(int numVertices) {
        vertices = numVertices;
        adjacencyMatrix.resize(vertices, std::vector<int>(vertices, 0));
    }

    void addEdge(int from, int to, int weight) {
        if (from >= 0 && from < vertices && to >= 0 && to < vertices) {
            adjacencyMatrix[from][to] = weight;
        } else {
            std::cerr << "Error: Incorrect vertices!" << std::endl;
        }
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                std::cout << adjacencyMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Поиск остова графа
    void findMinimumSpanningTree() {
        std::vector<bool> visited(vertices, false);
        std::vector<int> minWeight(vertices, INT_MAX);
        std::vector<int> parent(vertices, -1);

        minWeight[0] = 0;

        for (int i = 0; i < vertices - 1; ++i) {
            int minVertex = -1;
            for (int j = 0; j < vertices; ++j) {
                if (!visited[j] && (minVertex == -1 || minWeight[j] < minWeight[minVertex])) {
                    minVertex = j;
                }
            }

            visited[minVertex] = true;

            for (int k = 0; k < vertices; ++k) {
                if (adjacencyMatrix[minVertex][k] != 0 && !visited[k] && adjacencyMatrix[minVertex][k] < minWeight[k]) {
                    parent[k] = minVertex;
                    minWeight[k] = adjacencyMatrix[minVertex][k];
                }
            }
        }

        std::cout << "Minimum spanning tree:" << std::endl;
        for (int i = 1; i < vertices; ++i) {
            std::cout << "Edge " << parent[i] << " - " << i << "  Weight: " << minWeight[i] << std::endl;
        }
    }

    // Поиск компонент сильной связности
    void findStronglyConnectedComponents() {
        std::stack<int> stack;
        std::vector<bool> visited(vertices, false);
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                fillOrder(i, visited, stack);
            }
        }

        DirectedGraph transposedGraph = transpose();

        std::vector<bool> visitedAgain(vertices, false);
        std::cout << "Strongly Connected Components:" << std::endl;
        while (!stack.empty()) {
            int vertex = stack.top();
            stack.pop();

            if (!visitedAgain[vertex]) {
                std::cout << "Component: ";
                transposedGraph.transposedDfs(vertex, visitedAgain);
                std::cout << std::endl;
            }
        }
    }

    // Метод для нахождения суммы кратчайших путей от начальной вершины до всех остальных
    void findShortestPaths(int start) {
        std::vector<int> distance(vertices, std::numeric_limits<int>::max());
        distance[start] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (int v = 0; v < vertices; ++v) {
                if (adjacencyMatrix[u][v] != 0) {
                    int weight = adjacencyMatrix[u][v];
                    if (distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                        pq.push({distance[v], v});
                    }
                }
            }
        }

        // Выводим сумму весов для каждой вершины
        std::cout << "Shortest paths from vertex " << start << ":\n";
        for (int i = 0; i < vertices; ++i) {
            std::cout << "To vertex " << i << ": " << distance[i] << std::endl;
        }
    }

    // Поиск кратчайшего пути с наибольшей пропускной способностью
    void findShortestPathWithMaxCapacity(int start, int end) {
        std::vector<int> maxCapacity(vertices, INT_MIN);
        std::vector<bool> visited(vertices, false);

        maxCapacity[start] = INT_MAX;  // Начальная пропускная способность

        for (int i = 0; i < vertices - 1; ++i) {
            int maxVertex = findMaxCapacityVertex(maxCapacity, visited);
            visited[maxVertex] = true;

            for (int j = 0; j < vertices; ++j) {
                if (!visited[j] && adjacencyMatrix[maxVertex][j] != 0) {
                    int capacity = std::min(maxCapacity[maxVertex], adjacencyMatrix[maxVertex][j]);
                    if (capacity > maxCapacity[j]) {
                        maxCapacity[j] = capacity;
                    }
                }
            }
        }

        // Вывод кратчайшего пути с наибольшей пропускной способностью
        std::cout << "Shortest Path with Max Capacity from " << start << " to " << end << ": " << maxCapacity[end] << std::endl;
    }

    // Поиск нескольких путей с заданной суммарной пропускной способностью
    void findPathsWithTotalCapacity(int start, int end, int requiredCapacity) {
        std::vector<int> currentPath;
        std::vector<std::vector<int>> allPaths;
        std::vector<bool> visited(vertices, false);

        findPathsDFS(start, end, requiredCapacity, currentPath, allPaths, visited);

        // Вывод всех найденных путей
        std::cout << "Paths with Total Capacity from " << start << " to " << end << " (" << requiredCapacity << "):" << std::endl;
        for (const auto& path : allPaths) {
            std::cout << "Path: ";
            for (int vertex : path) {
                std::cout << vertex << " ";
            }
            std::cout << " Capacity: " << calculatePathCapacity(path) << std::endl;
        }
    }

    void generateRandomGraph(int numVertices, int numEdges, int maxWeight) {
        if (numEdges > numVertices * (numVertices - 1)) {
            std::cerr << "Error: Too many edges for given number of vertices!" << std::endl;
            return;
        }

        int count = 0;
        while (count < numEdges) {
            int from = rand() % numVertices;
            int to = rand() % numVertices;

            if (from != to && adjacencyMatrix[from][to] == 0) {
                int weight = rand() % maxWeight + 1; // Вес от 1 до maxWeight
                addEdge(from, to, weight);
                count++;
            }
        }
    }
    int getVerticesCount() const {
        return vertices;
    }

    int getEdgesCount() const {
        int count = 0;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    int findMaxCapacityVertex(const std::vector<int>& maxCapacity, const std::vector<bool>& visited) {
        int maxVertex = -1;
        int maxCapacityValue = INT_MIN;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i] && maxCapacity[i] > maxCapacityValue) {
                maxCapacityValue = maxCapacity[i];
                maxVertex = i;
            }
        }

        return maxVertex;
    }

    void findPathsDFS(int current, int end, int requiredCapacity, std::vector<int>& currentPath, std::vector<std::vector<int>>& allPaths, std::vector<bool>& visited) {
        currentPath.push_back(current);

        if (current == end && calculatePathCapacity(currentPath) >= requiredCapacity) {
            allPaths.push_back(currentPath);
        } else {
            visited[current] = true;
            for (int i = 0; i < vertices; ++i) {
                if (adjacencyMatrix[current][i] != 0 && !visited[i]) {
                    findPathsDFS(i, end, requiredCapacity, currentPath, allPaths, visited);
                }
            }
            visited[current] = false;
        }

        currentPath.pop_back();
    }

    int calculatePathCapacity(const std::vector<int>& path) {
        int capacity = INT_MAX;
        for (size_t i = 0; i < path.size() - 1; ++i) {
            int from = path[i];
            int to = path[i + 1];
            int edgeWeight = adjacencyMatrix[from][to];
            capacity = std::min(capacity, edgeWeight);
        }
        return capacity;
    }

    void fillOrder(int vertex, std::vector<bool>& visited, std::stack<int>& stack) {
        visited[vertex] = true;
        for (int i = 0; i < vertices; ++i) {
            if (adjacencyMatrix[vertex][i] != 0 && !visited[i]) {
                fillOrder(i, visited, stack);
            }
        }
        stack.push(vertex);
    }

    DirectedGraph transpose() {
        DirectedGraph transposedGraph(vertices);
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                transposedGraph.addEdge(j, i, adjacencyMatrix[i][j]);
            }
        }
        return transposedGraph;
    }



    void transposedDfs(int vertex, std::vector<bool>& visited) {
        visited[vertex] = true;
        std::cout << vertex << " ";

        for (int i = 0; i < vertices; ++i) {
            if (adjacencyMatrix[vertex][i] != 0 && !visited[i]) {
                transposedDfs(i, visited);
            }
        }
    }
};
#endif //LAB4_GRAF_DIGRAPH_H
