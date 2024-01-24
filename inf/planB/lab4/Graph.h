
#include "Lab4.h"

class Graph 
{
private:
	vector<Vertex> graph;
public:
	Graph(): graph(0), user(0) {}

	void addVertexUser(int nameVertexUser) //
	{
		if (SearchVertexUser(nameVertexUser)) return;

		addVertexGraph((int)graph.size());
		addUser(nameVertexUser);
		return;
	}

	void addEdgeUser(int nameVertexUser1, int nameVertexUser2, int weight)//
	{
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		if (index1 == -1 || index2 == -1 || (index1 == index2)) return;
		addEdgeGraph(index1, index2, weight);
		return;
	}

	void addArcUser(int nameVertexUser1, int nameVertexUser2, int weight)//
	{
		int index1 = getIndexUser(nameVertexUser1);
		int index2 = getIndexUser(nameVertexUser2);
		if (index1 == -1 || index2 == -1 || (index1 == index2)) return;
		addArcGraph(index1, index2, weight);
		return;
	}

	void removeEdgeUser(int nameVertexUser1, int nameVertexUser2)//
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

	void removeVertexUser(int nameVertexUser)//
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

	void ChangeWeightArcUser(int nameVertexUser1, int nameVertexUser2, int weight)//
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

	bool SearchVertexUser(int nameVertexUser)//
	{
		for (int i = 0; i < user.size(); i++)
		{
			if (user[i] == nameVertexUser) return true;
		}
		return false;
	}
	
	void PrintUser()//
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

};