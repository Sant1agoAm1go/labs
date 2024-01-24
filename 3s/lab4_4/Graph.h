
#include "Laba4.h"

class Graph 
{
private:
	vector<Vertex> graph;
public:
	Graph(): graph(0), user(0) {}

	void addVertexUser(int nameVertexUser) 
	{
		if (SearchVertexUser(nameVertexUser)) return;

		addVertexGraph((int)graph.size());
		addUser(nameVertexUser);
		return;
	}

	void addEdgeUser(int nameVertexUser1, int nameVertexUser2, int weight)
	{
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		if (index1 == -1 || index2 == -1 || (index1 == index2)) return;
		addEdgeGraph(index1, index2, weight);
		return;
	}

	void addArcUser(int nameVertexUser1, int nameVertexUser2, int weight)
	{
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		if (index1 == -1 || index2 == -1 || (index1 == index2)) return;
		addArcGraph(index1, index2, weight);
		return;
	}

	void removeEdgeUser(int nameVertexUser1, int nameVertexUser2)
	{
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		if (index1 == -1 || index2 == -1 || (index1 == index2)) return;
		removeEdgeGraph(index1, index2);
		return;
	}
	
	void removeArcUser(int nameVertexUser1, int nameVertexUser2)
	{
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		if (index1 == -1 || index2 == -1 || (index1 == index2)) return;
		removeArcGraph(index1, index2);
		return;
	}

	void removeVertexUser(int nameVertexUser)
	{
		int index = getIndexUser(nameVertexUser);
		if (index == -1) return;
		removeVertexGraph(index);
		removeUser(nameVertexUser);
		graphNorm();
		return;
	}

	int Size()
	{
		return (int)graph.size();
	}
	
	int GetWeightUser(int nameVertexUser1, int nameVertexUser2)
	{
		if (SearchVertexUser(nameVertexUser1) == false || SearchVertexUser(nameVertexUser2) == false) return 0;
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		for (int i = 0; i < graph.size(); i++)
		{
			for (list<Edge>::iterator it = graph[i].list.begin(); it != graph[i].list.end(); it++)
			{
				if ((*it).v1 == index1 && (*it).v2 == index2)
					return (*it).weight;
			}
		}
		return 0;
	}

	void ChangeWeightArcUser(int nameVertexUser1, int nameVertexUser2, int weight)
	{
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		if (index1 == -1 || index2 == -1 || (index1 == index2)) return;
		ChangeWeightArcGraph(index1, index2, weight);
		return;
	}

	void ChangeWeightEdgeUser(int nameVertexUser1, int nameVertexUser2, int weight)
	{
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		if (index1 == -1 || index2 == -1 || (index1 == index2)) return;
		ChangeWeightEdgeGraph(index1, index2, weight);
		return;
	}

	bool SearchVertexUser(int nameVertexUser)
	{
		for (int i = 0; i < user.size(); i++)
		{
			if (user[i] == nameVertexUser) return true;
		}
		return false;
	}
	
	void PrintUser()
	{
		for (int i = 0; i < graph.size(); i++)
		{
			cout << "VertexName: " << getUser(graph[i].name) << " { ";
			for (list<Edge>::iterator it = graph[i].list.begin(); it != graph[i].list.end(); it++)
			{
				std::cout << "[" << getUser((*it).v1) << "-" << getUser((*it).v2) << ":" << (*it).weight << "] ";
			}
			std::cout << "}" << std::endl;
		}
		return;
	}
	
	vector<int> Dijkstra(int start) 
	{
		int numVertices = this->Size();
		vector<int> dist(numVertices, INT_MAX);
		dist[start] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, start });

		while (!pq.empty()) 
		{
			int u = pq.top().second;
			pq.pop();

			for (const auto& edge : graph[u].list) 
			{
				int v = edge.v2;
				int weight = edge.weight;

				if (dist[v] > dist[u] + weight) 
				{
					dist[v] = dist[u] + weight;
					pq.push({ dist[v], v });
				}
			}
		}

		return dist;
	}

	pair<vector<int>, vector<int>> Dijkstra(int start, int end) 
	{
		int numVertices = this->Size();
		vector<int> dist(numVertices, INT_MAX);
		vector<int> prev(numVertices, -1);
		dist[start] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, start });

		while (!pq.empty()) 
		{
			int u = pq.top().second;
			pq.pop();

			for (const auto& edge : graph[u].list) 
			{
				int v = edge.v2;
				int weight = edge.weight;

				if (dist[v] > dist[u] + weight) 
				{
					dist[v] = dist[u] + weight;
					prev[v] = u;
					pq.push({ dist[v], v });
				}
			}
		}

		vector<int> path;
		for (int at = end; at != -1; at = prev[at]) 
		{
			path.push_back(at);
		}
		reverse(path.begin(), path.end());

		return { dist, path };
	}
	
	void DFS(int vertex, vector<int>& DFS)
	{
		if (SearchVertexGraph(vertex) == false) return;
		vector<bool> visited(this->Size(), false);
		stack<int> stack;
		stack.push(vertex);

		while (!stack.empty())
		{
			int vertex = stack.top();
			stack.pop();

			if (!visited[vertex])
			{
				DFS.push_back(vertex);
				visited[vertex] = true;
			}

			for (auto i = graph[vertex].list.begin(); i != graph[vertex].list.end(); ++i)
				if (!visited[(*i).v2])
					stack.push((*i).v2);
		}

		return;
	}

	void DFS(int startVertex, int endVertex, vector<int>& path) 
	{
		if (SearchVertexGraph(startVertex) == false || SearchVertexGraph(endVertex) == false) return;
		vector<bool> visited(this->Size(), false);
		stack<int> stack;
		vector<int> parent(this->Size(), -1); 

		visited[startVertex] = true;
		stack.push(startVertex);

		while (!stack.empty()) 
		{
			int currentVertex = stack.top();
			stack.pop();

			if (currentVertex == endVertex) 
			{
				
				int v = endVertex;
				while (v != -1) 
				{
					path.push_back(v);
					v = parent[v];
				}
				std::reverse(path.begin(), path.end()); 
				return;
			}

			for (auto i : graph[currentVertex].list) 
			{
				if (!visited[i.v2]) 
				{
					stack.push(i.v2);
					visited[i.v2] = true;
					parent[i.v2] = currentVertex; 
				}
			}
		}

		return;
	}

	void BFS(int vertex, vector<int>& BFS)
	{
		if (SearchVertexGraph(vertex) == false) return;
		vector<bool> visited(this->Size(), false);
		queue<int> queue;
		visited[vertex] = true;
		queue.push(vertex);
		BFS.push_back(vertex);

		while (queue.empty() == false)
		{
			int vertex = queue.front();
			queue.pop();
			if (!visited[vertex])
			{
				BFS.push_back(vertex);
				visited[vertex] = true;
			}
			
			for (auto i = graph[vertex].list.begin(); i != graph[vertex].list.end(); ++i)
				if (!visited[(*i).v2])
					queue.push((*i).v2);
		}

		return;
	}
	
	void BFS(int startVertex, int endVertex, vector<int>& path) 
	{
		if (SearchVertexGraph(startVertex) == false || SearchVertexGraph(endVertex) == false) return;
		vector<bool> visited(this->Size(), false);
		queue<int> queue;
		vector<int> parent(this->Size(), -1); 

		visited[startVertex] = true;
		queue.push(startVertex);

		while (!queue.empty()) 
		{
			int currentVertex = queue.front();
			queue.pop();

			if (currentVertex == endVertex) 
			{
				int v = endVertex;
				while (v != -1) 
				{
					path.push_back(v);
					v = parent[v];
				}
				std::reverse(path.begin(), path.end()); 
				return;
			}

			for (auto i : graph[currentVertex].list) 
			{
				if (!visited[i.v2]) 
				{
					queue.push(i.v2);
					visited[i.v2] = true;
					parent[i.v2] = currentVertex; 
					
				}
			}
		}

		return;
	}

	void topologicalSort(vector<int>& topologicalSort)
	{
		if (this->hasCycle()) return;
		stack<int> Stack;
		vector<bool> visited(this->Size(), false);

		for (int i = 0; i < graph.size(); i++)
			if (visited[i] == false)
				topologicalSortUtil(i, visited, Stack);

		while (Stack.empty() == false) 
		{
			topologicalSort.push_back(Stack.top());
			Stack.pop();
		}

		return;
	}
	
	
	void floydWarshall(int vert)
	{
		if (SearchVertexGraph(vert) == false) return;
		int n = (int)graph.size();
		int INF = INT_MAX; 
		vector<vector<int>> dist(n, vector<int>(n, INF));

		for (int i = 0; i < n; i++)
		{
			dist[i][i] = 0; 
			for (const Edge& e : graph[i].list)
			{
				dist[e.v1][e.v2] = e.weight;
			}
		}

		vector<vector<int>> next(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dist[i][j] != INF && i != j)
				{
					next[i][j] = j;
				}
			}
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		for (int j = 0; j < n; j++)
		{

			if (dist[vert][j] == INF)
			{
				cout << "No path from " << vert << " to " << j << "\n";
			}
			else
			{
				cout << "Shortest path from " << vert << " to " << j << " is " << dist[vert][j] << "\n";
			}
		}
		/* Для всех вершин
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				if (dist[i][j] == INF)
				{
					cout << "No path from " << i << " to " << j << "\n";
				}
				else
				{
					cout << "Shortest path from " << i << " to " << j << " is " << dist[i][j] << "\n";
				}
			}
		*/
		return;
	}

	void floydWarshall(int start, int end)
	{
		if (SearchVertexGraph(start) == false || SearchVertexGraph(end) == false) return;
		int n = (int)graph.size();
		int INF = INT_MAX;
		vector<vector<int>> dist(n, vector<int>(n, INF));
		vector<vector<int>> next(n, vector<int>(n, -1));

		for (int i = 0; i < n; i++)
		{
			dist[i][i] = 0;
			for (const Edge e : graph[i].list)
			{
				dist[e.v1][e.v2] = e.weight;
				next[e.v1][e.v2] = e.v2;
			}
		}

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						next[i][j] = next[i][k];
					}
				}
			}
		}

		if (dist[start][end] == INF)
		{
			cout << "No path from " << getUser(start) << " to " << getUser(end) << "";
		}
		else
		{
			cout << "Distance from vertex " << getUser(start) << " to " << getUser(end) << " is " << dist[start][end] << "" << endl;
			cout << "Path: " << getUser(start);
			int current = start;
			while (current != end)
			{
				current = next[current][end];
				cout << " " << getUser(current);
			}
			cout << "";
		}
		cout << endl;
	
		return;
	}

	bool hasCycle() 
	{
		int numVertices = (int)graph.size();
		bool* visited = new bool[numVertices];
		bool* recStack = new bool[numVertices];
		for (int i = 0; i < numVertices; i++) 
		{
			visited[i] = false;
			recStack[i] = false;
		}

		for (int i = 0; i < numVertices; i++) 
		{
			if (hasCycleUtil(i, visited, recStack)) 
			{
				delete[] visited;
				delete[] recStack;
				return true;
			}
		}

		delete[] visited;
		delete[] recStack;

		return false;
	}

	int getUser(int vertexGraph)
	{
		return user[vertexGraph];
	}

	void getVertexNamesGraph(vector<int>& names)
	{
		for (int i = 0; i < graph.size(); i++)
		{
			names.push_back(graph[i].name);
		}
		return;
	}

	int getIndexUser(int vertexUser)
	{
		for (int i = 0; i < user.size(); i++)
		{
			if (user[i] == vertexUser) return i;
		}
		return -1;
	}

private:
	vector<int> user;

	void setUser(int index, int vertexUser)
	{
		user[index] = vertexUser;
		return;
	}

	void addUser(int vertexUser)
	{
		user.push_back(vertexUser);
		return;
	}

	void removeUser(int vertexUser)
	{
		for (auto it = user.begin(); it != user.end();)
		{
			if ((*it) == vertexUser)
			{
				user.erase(it);
				return;
			}
			else
			{
				it++;
			}
		}
		return;
	}

	void graphNorm()
	{
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[i].name != i)
			{
				for (int j = 0; j < graph.size(); j++)
				{
					for (list<Edge>::iterator it = graph[j].list.begin(); it != graph[j].list.end(); it++)
					{
						if ((*it).v1 == graph[i].name) (*it).v1 = i;
						if ((*it).v2 == graph[i].name) (*it).v2 = i;
					}
				}
				graph[i].name = i;
			}
		}
		return;
	}

	void addVertexGraph(int nameVertexGraph)
	{
		Vertex vertex;
		vertex.name = nameVertexGraph;
		list<Edge> list;
		vertex.list = list;
		graph.push_back(vertex);
		return;
	}

	void addEdgeGraph(int nameVertexGraph1, int nameVertexGraph2, int weight)
	{
		if (SearchEdgeArcGraph(nameVertexGraph1, nameVertexGraph2)) return;

		Edge newEdge(nameVertexGraph1, nameVertexGraph2, weight);
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[i].name == nameVertexGraph1) graph[i].list.push_back(newEdge);
		}

		Edge reverseEdge(nameVertexGraph2, nameVertexGraph1, weight);
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[i].name == nameVertexGraph2) graph[i].list.push_back(reverseEdge);
		}

		return;
	}

	void addArcGraph(int nameVertexGraph1, int nameVertexGraph2, int weight)
	{
		if (SearchEdgeArcGraph(nameVertexGraph1, nameVertexGraph2)) return;
		Edge newEdge(nameVertexGraph1, nameVertexGraph2, weight);
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[i].name == nameVertexGraph1) graph[i].list.push_back(newEdge);
		}
		return;
	}

	void removeEdgeGraph(int nameVertexGraph1, int nameVertexGraph2)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			for (list<Edge>::iterator i = graph[j].list.begin(); i != graph[j].list.end();)
			{
				if (((*i).v1 == nameVertexGraph1 && (*i).v2 == nameVertexGraph2) || ((*i).v1 == nameVertexGraph2 && (*i).v2 == nameVertexGraph1))
				{
					i = graph[j].list.erase(i);
				}
				else
				{
					i++;
				}
			}
		}
		return;
	}

	void removeArcGraph(int nameVertexGraph1, int  nameVertexGraph2)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			for (list<Edge>::iterator i = graph[j].list.begin(); i != graph[j].list.end();)
			{
				if (((*i).v1 == nameVertexGraph1 && (*i).v2 == nameVertexGraph2))
				{
					i = graph[j].list.erase(i);
				}
				else
				{
					i++;
				}
			}
		}
		return;
	}

	void removeVertexGraph(int nameVertexGraph)
	{
		for (vector<Vertex>::iterator it = graph.begin(); it != graph.end();)
		{
			if ((*it).name == nameVertexGraph) { graph.erase(it); break; }
			else { it++; }
		}

		for (int i = 0; i < graph.size(); i++)
		{
			for (list<Edge>::iterator it = graph[i].list.begin(); it != graph[i].list.end();)
			{
				if ((*it).v1 == nameVertexGraph || (*it).v2 == nameVertexGraph)
				{
					it = graph[i].list.erase(it);
				}
				else
				{
					it++;
				}
			}
		}

		return;
	}

	void ChangeWeightArcGraph(int nameVertexGraph1, int nameVertexGraph2, int weight)
	{
		for (int i = 0; i < graph.size(); i++)
		{
			for (list<Edge>::iterator it = graph[i].list.begin(); it != graph[i].list.end(); it++)
			{
				if ((*it).v1 == nameVertexGraph1 && (*it).v2 == nameVertexGraph2) (*it).weight = weight;
			}
		}
		return;
	}

	void ChangeWeightEdgeGraph(int nameVertexGraph1, int nameVertexGraph2, int weight)
	{
		for (int i = 0; i < graph.size(); i++)
		{
			for (list<Edge>::iterator it = graph[i].list.begin(); it != graph[i].list.end(); it++)
			{
				if (((*it).v1 == nameVertexGraph1 && (*it).v2 == nameVertexGraph2) || ((*it).v1 == nameVertexGraph2 && (*it).v2 == nameVertexGraph1)) (*it).weight = weight;
			}
		}
		return;
	}

	bool SearchVertexGraph(int nameVertexGraph)
	{
		for (int i = 0; i < graph.size(); i++)
		{
			if (graph[i].name == nameVertexGraph) return true;
		}
		return false;
	}

	bool SearchEdgeArcGraph(int nameVertexGraph1, int nameVertexGraph2)
	{
		for (int i = 0; i < graph.size(); i++)
		{
			for (list<Edge>::iterator it = graph[i].list.begin(); it != graph[i].list.end(); it++)
			{
				if ((*it).v1 == nameVertexGraph1 && (*it).v2 == nameVertexGraph2) return true;
			}
		}
		return false;
	}

	void PrintGraph()
	{
		for (int i = 0; i < graph.size(); i++)
		{
			cout << "VertexName: " << graph[i].name << " { ";
			for (list<Edge>::iterator it = graph[i].list.begin(); it != graph[i].list.end(); it++)
			{
				std::cout << "[" << (*it).v1 << "-" << (*it).v2 << ":" << (*it).weight << "] ";
			}
			std::cout << "}" << std::endl;
		}
		return;
	}

	void topologicalSortUtil(int vertex, vector<bool>& visited, stack<int>& Stack)
	{
		visited[vertex] = true;
		for (auto it = graph[vertex].list.begin(); it != graph[vertex].list.end(); ++it)
			if (!visited[(*it).v2])
				topologicalSortUtil((*it).v2, visited, Stack);
		Stack.push(vertex);
		return;
	}

	bool hasCycleUtil(int v, bool visited[], bool* recStack) 
	{
		if (!visited[v]) 
		{
			visited[v] = true;
			recStack[v] = true;

			for (auto& edge : graph[v].list) 
			{
				int neighbor = edge.v2;
				if (!visited[neighbor] && hasCycleUtil(neighbor, visited, recStack)) 
				{
					return true;
				}
				else if (recStack[neighbor]) 
				{
					return true;
				}
			}
		}
		recStack[v] = false;
		return false;
	}
};