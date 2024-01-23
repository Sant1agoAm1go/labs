#pragma once

#include <iostream>

template<typename ID, typename T>
class Node {
private:
	ID id;
	T data;
public:
	Node(T data, ID id) {
		this->data = data;
		this->id = id;
	}
	Node(const Node<ID,T>& other) {
		this->data = other.data;
		this->id = other.id;
	}
	ID GetId() {
		return id;
	}
	T& GetData() {
		return data;
	}
	T& operator=(const Node<ID,T>& other) {
		this->data = data;
		this->id = id;
		return *this;
	}
	bool operator==(const Node<ID,T>& other) {
		if (other.data == this->data && other.id == this->id) { return true; }
		else { return false; }
	}
	bool operator!=(const Node<ID,T>& other) {
		if (other.data != this->data || other.id != this->id) { return true; }
		else { return false; }
	}
	bool IsEqual(const Node<ID,T>& other) {
		return (*this == other);
	}
};

template<typename ID, typename T, typename E>
class Edge {
private:
	E data;
	Node<ID, T>* start;
	Node<ID, T>* end;
public:
	Edge() {
		data = new T();
		start = nullptr;
		end = nullptr;
	}
	Edge(E data2, Node<ID, T>* start2, Node<ID, T>* end2) {
		data = data2;
		start = start2;
		end = start2;
	}
	Edge(const Edge<ID, T, E>& other) {
		this->data = other.data;
		this->start = other.start;
		this->end = other.end;
	}
	Node<ID, T>* GetStart() {
		return start;
	}
	Node<ID, T>* GetEnd() {
		return end;
	}
	E& GetData() {
		return data;
	}
	bool operator==(const Edge<ID, T, E>& other) {
		if (other.start == this->start && other.end == this->end && other.data == this->data) { return true; }
		else { return false; }
	}
	bool operator!=(const Edge<ID, T, E>& other) {
		if (other.start != this->start || other.end != this->end || other.data != this->data) { return true; }
		else { return false; }
	}
	~Edge() {
		delete start;
		delete end;
	}
};