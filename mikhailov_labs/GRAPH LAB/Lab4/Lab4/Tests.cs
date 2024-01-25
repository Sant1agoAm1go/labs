using Microsoft.Msagl.Drawing;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    internal class Tests
    {
        private Graph CreateGraph()
        {
            Graph graphModel = new Graph();

            graphModel.Nodes.Add(1, new Node(
                new List<Edge>() { new Edge { NodeId = 6, Weight = 14 }, new Edge { NodeId = 3, Weight = 4 } },
                new List<Edge>()));
            graphModel.Nodes.Add(2,
                new Node(new List<Edge>() { new Edge { NodeId = 5, Weight = 7 }, new Edge { NodeId = 3, Weight = 10 }, new Edge { NodeId = 4, Weight = 15 } },
                new List<Edge>()));
            graphModel.Nodes.Add(3,
                new Node(new List<Edge>() { new Edge { NodeId = 4, Weight = 9 } },
                new List<Edge>() { new Edge { NodeId = 6 }, new Edge { NodeId = 1 }, new Edge { NodeId = 2 } }));
            graphModel.Nodes.Add(4,
                new Node(new List<Edge>() { new Edge { NodeId = 5, Weight = 6 } },
                new List<Edge>() { new Edge { NodeId = 3 }, new Edge { NodeId = 2 } }));
            graphModel.Nodes.Add(5,
                new Node(new List<Edge>() { new Edge { NodeId = 6, Weight = 9 } },
                new List<Edge>() { new Edge { NodeId = 4 }, new Edge { NodeId = 2 } }));
            graphModel.Nodes.Add(6,
                new Node(new List<Edge>() { new Edge { NodeId = 3, Weight = 2 } },
                new List<Edge>() { new Edge { NodeId = 1 }, new Edge { NodeId = 5 } }));

            return graphModel;
        }

        public void GetShortestDistanceTest()
        {
            var graph = CreateGraph();
            int result = graph.GetShortestDistance(1, 5);
        }

        public void GetShortestPathTest()
        {
            var graph = CreateGraph();
            List<int> result = graph.GetShortestPath(1, 5);
        }
    }
}
