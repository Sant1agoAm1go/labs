using System;
using System.Collections.Generic;
using System.Data.SqlTypes;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.Remoting;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Xml.Linq;

namespace Lab4
{
    public class Graph
    {
        public Dictionary<int, Node> Nodes { get; set; } = new Dictionary<int, Node>();

        public int Count
        {
            get {
                return Nodes.Count;
            }
        }

        public Graph()
        { }

        public List<Tuple<int, int>> GetMinimumSpanningTree()
        {
            var result = new List<Tuple<int, int>>();
            var addedNodes = new List<int>();
            Nodes.First().Value.Visited = true;
            int nodeToAdd;

            do
            {
                nodeToAdd = -1;
                Tuple<int, int> edgeToAdd = new Tuple<int, int>(0, 0);
                int minDistance = int.MaxValue;
                foreach (var node in Nodes.Where(n => n.Value.Visited))
                {
                    foreach (Edge edge in node.Value.OutEdges)
                    { 
                        if (Nodes[edge.NodeId].Visited)
                        {
                            continue;
                        }

                        if (edge.Weight < minDistance)
                        {
                            minDistance = edge.Weight;
                            edgeToAdd = new Tuple<int, int>(node.Key, edge.NodeId);
                            nodeToAdd = edge.NodeId;
                        }
                    }
                }

                if (nodeToAdd != -1)
                {
                    Nodes[nodeToAdd].Visited = true;
                    result.Add(edgeToAdd);
                }
            }
            while (nodeToAdd != -1);
            return result;
        }

        public int GetShortestDistance(int start, int end)
        {
            var startNode = Nodes[start];
            startNode.Distance = 0;
            Visit(start);
            return Nodes[end].Distance;
        }

        public List<int> GetShortestPath(int start, int end)
        {
            var startNode = Nodes[start];
            startNode.Distance = 0;
            Visit(start);
            var result = new List<int>();
            result.Add(end);
            var node = Nodes[end];
            int id = end;

            while (id != start)
            {
                var nodeIds = node.InEdges.Select(e => e.NodeId).ToList();
                var nodes = Nodes.Where(n => nodeIds.Contains(n.Key));
                if (nodes.Count() == 0)
                {
                    return new List<int>();
                }
                var minDistance = nodes.Min(n => n.Value.Distance);
                var idNodePair = nodes.Where(n => n.Value.Distance == minDistance).First();
                node = idNodePair.Value;
                id = idNodePair.Key;
                result.Add(id);
            }

            result.Reverse();

            return result;
        }

        private void Visit(int start)
        {
            var node = Nodes[start];

            foreach (var edge in node.OutEdges)
            {
                int distance = edge.Weight + node.Distance;

                if (Nodes[edge.NodeId].Distance > distance)
                {
                    Nodes[edge.NodeId].Distance = distance;
                }
            }

            node.Visited = true;

            var nodeIds = node.OutEdges.Select(e => e.NodeId).ToList();

            foreach (var id in nodeIds)
            {
                if (!Nodes[id].Visited)
                {
                    Visit(id);
                }
            }
        }
    }
}
