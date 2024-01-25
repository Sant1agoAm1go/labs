using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab4
{
    internal static class GraphReader
    {
        public static Graph Read ()
        {
            Graph graph = new Graph();
            string line;
            try
            {
                StreamReader sr = new StreamReader("C:\\temp\\graph.txt");
                line = sr.ReadLine();
                bool firstLine = true;
                int nodeKey = 1;
                while (line != null)
                {
                    if (firstLine)
                    {   
                        int nodeCount = int.Parse(line);
                        firstLine = false;
                        for (int i = 0; i < nodeCount; i++) 
                        {
                            graph.Nodes.Add(i + 1, new Node());
                        }
                    }

                    else 
                    { 
                        if (String.IsNullOrEmpty(line))
                        {
                            ++nodeKey;
                            continue; 
                        }
                        var nodeWeightPairs = line.Split(',');
                        foreach( var pair in nodeWeightPairs)
                        {
                            var nodeWeightPairArray = pair.Split(' ');
                            int nodeId = int.Parse(nodeWeightPairArray[0]);
                            int weight = int.Parse(nodeWeightPairArray[1]);
                            var edge = new Edge(nodeId, weight);
                            var inEdge = new Edge(nodeKey, weight);
                            graph.Nodes[nodeKey].OutEdges.Add(edge);
                            graph.Nodes[nodeId].InEdges.Add(inEdge);
                        }
                        
                        ++nodeKey;

                    }

                    line = sr.ReadLine();
                }
                //close the file
                sr.Close();
                Console.ReadLine();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
            finally
            {
                Console.WriteLine("Executing finally block.");
            }
            return graph; 
        }
    }
}
