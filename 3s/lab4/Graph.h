#pragma once

#include <iostream>
#include "IDictionary.h"
#include "HashTable.h"
#include "ArraySequence.h"
#include "IHasher.h"
#include "Component.h"
template<typename T, typename ID, typename E>
class Graph {
private:
	IDictionary<ID, ArraySequence<Edge<ID, T, E>>> adjacency;
	IDictionary<ID, Node<ID, T>> nodes;
public:
	Graph(IHasher<ID>* hash) {
		adjacency = new HashTable<ID, ArraySequence<Edge<ID, T, E>>>(hash);
		nodes = new HashTable<ID, Node<ID, T>>(hash);
	}
	Graph(Graph<T, ID, E>& other) {
		adjacency = other.adjacency;
		nodes = other.nodes;
	}
	Graph(Graph<T, ID, E>&& other) {
		adjacency = std::move(other.adjacency);
		nodes = std::move(other.nodes);
	}
	~Graph() {
		delete adjacency;
		delete nodes;
	}
	void AddEdge(Edge<ID, T, E>& other) {
		if (!adjacency->ContainsKey(other.GetStart()->GetId())) {
			ArraySequence<Edge<ID, T, E>> newadjacency;
			newadjacency.Append(other);
			adjacency->Add({ other.GetStart()->GetId(), newadjacency });
		} 
		else {
			ArraySequence< Edge<ID, T, E>>& currentadjacency = adjacency->Get(other.GetStart()->GetId());
			currentadjacency.Append(other);
		}
	}
	void AddNode(Node<ID, T>& other) {
		if (!nodes->ContainsKey(other.GetId())) {
			nodes->Add({ other.GetId(), other });
		}
		else {
			throw std::out_of_range("This node was added");
		}
	}
	void AddNodes(std::initializer_list<Node<ID, T>> other) {
		for (auto a : other) {
			if (!nodes->ContainsKey(a.GetId())) {
				nodes->Add({ other.GetId(), a });
			}
		}
	}
	void AddEdges(std::initializer_list<Edge<ID, T, E>> other) {
		for (auto a : other) {
			if (!adjacency->ContainsKey(a.GetStart()->GetId())) {
				ArraySequence<Edge<ID, T, E>> newadjacency;
				newadjacency.Append(a);
				adjacency->Add({ a.GetStart()->GetId(), newadjacency });
			}
			else {
				ArraySequence< Edge<ID, T, E>>& currentadjacency = adjacency->Get(a.GetStart()->GetId());
				currentadjacency.Append(a);
			}
		}
	}
	void RemoveEdge(Edge<ID, T, E>& other) {
		if (!adjacency->ContainsKey(other.GetStart()->GetId())) {
			return;
		}
		else {
			ArraySequence<Edge<ID, T, E>>& currentadjacency = adjacency->Get(other.GetStart()->GetId());
			for (int i = 0; i < currentadjacency.GetLength(); i++) {
				if (currentadjacency.Get(i) == other) {
					currentadjacency.Remove(i);
				}
			}
		}
	}
	void RemoveNode(Node<ID, T>& other) {
		if (!nodes->ContainsKey(other.GetId())) {
			return;
		}
		else {
			adjacency->Remove(other.GetId());
			nodes->Remove(other.GetId());
		}
	}

};