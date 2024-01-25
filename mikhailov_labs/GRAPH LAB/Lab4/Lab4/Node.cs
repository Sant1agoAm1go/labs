using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    public class Node
    {
        public List<Edge> OutEdges { get; private set; } = new List<Edge>();

        public List<Edge> InEdges { get; private set; } = new List<Edge>();

        public int Distance { get; set; } = int.MaxValue;

        public bool Visited { get; set; }

        public Node() { }

        public Node(List<Edge> outEdges, List<Edge> inEdges)
        {
            OutEdges = outEdges;
            InEdges = inEdges;
        }
    }
}
