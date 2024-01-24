#include "Lab4.h"

struct Vertex
{
    int name;
    struct list<Edge> list;
};


class Edge
{  
public:
    int v1; 
    int v2; 
    int weight;

    Edge(int v1, int v2, int weight): v1(v1), v2(v2), weight(weight)
    {
    }

    Edge(Edge const& edge)
    {
        this->v1 = edge.v1;
        this->v2 = edge.v2;
        this->weight = edge.weight;
    }

    int getWeight()
    {
        return weight;
    }
};

