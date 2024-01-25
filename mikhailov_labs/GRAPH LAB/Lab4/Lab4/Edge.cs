using Microsoft.Msagl.Core.DataStructures;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab4
{
    public class Edge
    {
        public int Weight { get; set; }

        public int NodeId { get; set;  }

        public Edge()
        { 
        }

        public Edge(int nodeId, int weight) { Weight = weight; NodeId = nodeId; }
    }
}
