using Microsoft.Msagl.Drawing;
using Microsoft.Msagl.GraphViewerGdi;
using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace Lab4
{
    public partial class Form1 : Form
    {
        private Microsoft.Msagl.Drawing.Graph graph;

        public Form1()
        {
            InitializeComponent();
            var graph = GraphReader.Read();//CreateGraph1();
            DrawGraph(graph);
        }

        private Graph CreateGraph1()
        {
            var graphModel = new Graph();
            graphModel.Nodes.Add(1,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 6, Weight = 14 }, new Edge { NodeId = 2, Weight = 5 }, new Edge { NodeId = 3, Weight = 4 } },
                    new List<Edge>()));
            graphModel.Nodes.Add(2,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 5, Weight = 7 },
                                       new Edge { NodeId = 3, Weight = 10 },
                                       new Edge { NodeId = 4, Weight = 15 },
                                       new Edge { NodeId = 7, Weight = 10 } },
                    new List<Edge>() { new Edge { NodeId = 1 } }));
            graphModel.Nodes.Add(3,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 4, Weight = 9 } },
                    new List<Edge>() { new Edge { NodeId = 6 }, new Edge { NodeId = 1 }, new Edge { NodeId = 2 } }));
            graphModel.Nodes.Add(4,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 5, Weight = 6 }, new Edge { NodeId = 6, Weight = 2 } },
                    new List<Edge>() { new Edge { NodeId = 3 }, new Edge { NodeId = 2 } }));
            graphModel.Nodes.Add(5,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 6, Weight = 9 } },
                    new List<Edge>() { new Edge { NodeId = 4 }, new Edge { NodeId = 2 } }));
            graphModel.Nodes.Add(6,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 3, Weight = 2 } },
                    new List<Edge>() { new Edge { NodeId = 1 }, new Edge { NodeId = 5 }, new Edge { NodeId = 4 } }));
            graphModel.Nodes.Add(7,
                new Node(
                    new List<Edge>(),
                    new List<Edge>() { new Edge { NodeId = 2 } }));
            return graphModel;
        }

        private void DrawGraph(Graph model)
        {
            GViewer viewer = new GViewer();
            graph = new Microsoft.Msagl.Drawing.Graph("graph");
            

            foreach (var node in model.Nodes)
            {
                string source = node.Key.ToString();
                foreach (var edge in node.Value.OutEdges)
                {
                    string target = edge.NodeId.ToString();
                    string label = edge.Weight.ToString();
                    graph.AddEdge(source, label, target);
                    var sourceNode = graph.FindNode(source);
                    DrawNode(sourceNode);
                }
                var graphNode = graph.FindNode(source);
                DrawNode(graphNode);
            }

            foreach (var e in graph.Edges)
            {
                e.Attr.Color = Microsoft.Msagl.Drawing.Color.LightPink;
            }

            graph.Attr.BackgroundColor = Microsoft.Msagl.Drawing.Color.AliceBlue;
            graph.Directed = false;
            viewer.Graph = graph;
            viewer.Refresh();
            SuspendLayout();
            viewer.Size = new Size(400, 400);
            viewer.Dock = DockStyle.Bottom;
            Controls.Add(viewer);
            ResumeLayout();
        }

        private void DrawPath(List<int> path)
        {
            Clear();

            for (int i = 0; i < path.Count; i++)
            {
                var node = graph.FindNode(path[i].ToString());
                HighlightNode(node);
                if (i != path.Count - 1)
                {
                    var source = path[i].ToString();
                    var target = path[i + 1].ToString();
                    var edge = graph.Edges.Where(e => e.Source == source && e.Target == target).First();
                    HighlightEdge(edge);
                }
            }

            Refresh();
        }

        private void DrawOstov(List<Tuple<int, int>> ostov) 
        {
            Clear();

            foreach (var edgegraphModelEdge in ostov)
            {
                var node1 = graph.FindNode(edgegraphModelEdge.Item1.ToString());
                HighlightNode(node1);
                var node2 = graph.FindNode(edgegraphModelEdge.Item2.ToString());
                HighlightNode(node2);

                var graphEdge = FindEdge(graph, edgegraphModelEdge.Item1, edgegraphModelEdge.Item2);
                if (graphEdge != null)
                {
                    HighlightEdge(graphEdge);
                }
                graphEdge = FindEdge(graph, edgegraphModelEdge.Item2, edgegraphModelEdge.Item1);

                if (graphEdge != null)
                {
                    HighlightEdge(graphEdge);
                }
            }

            Refresh();
        }

        private void DrawNode(Microsoft.Msagl.Drawing.Node node)
        {
            node.Attr.Color = Microsoft.Msagl.Drawing.Color.LightPink;
            node.Attr.FillColor = Microsoft.Msagl.Drawing.Color.White;
            node.Attr.Shape = Shape.Circle;
        }

        private void HighlightNode(Microsoft.Msagl.Drawing.Node node)
        {
            node.Attr.Color = Microsoft.Msagl.Drawing.Color.DeepPink;
            node.Attr.FillColor = Microsoft.Msagl.Drawing.Color.LightPink;
            node.Attr.Shape = Shape.DoubleCircle;
        }

        private void HighlightEdge(Microsoft.Msagl.Drawing.Edge edge)
        {
            edge.Attr.Color = Microsoft.Msagl.Drawing.Color.DeepPink;
        }

        private Microsoft.Msagl.Drawing.Edge FindEdge(Microsoft.Msagl.Drawing.Graph graph, int node1, int node2)
        {
            var source = node1.ToString();
            var target = node2.ToString();
            var edges = graph.Edges.Where(e => e.Source == source && e.Target == target);
            if (edges.Count() == 0)
            {
                return null;
            }
            return edges.First();
        }


        private void DrawSample()
        {
            //create a viewer object
            Microsoft.Msagl.GraphViewerGdi.GViewer viewer = new Microsoft.Msagl.GraphViewerGdi.GViewer();
            //create a graph object
            Microsoft.Msagl.Drawing.Graph graph = new Microsoft.Msagl.Drawing.Graph("graph");
            //create the graph content
            graph.AddEdge("A", "B");
            graph.AddEdge("B", "C");
            graph.AddEdge("A", "C").Attr.Color = Microsoft.Msagl.Drawing.Color.Green;
            graph.FindNode("A").Attr.Color = Microsoft.Msagl.Drawing.Color.Magenta;
            graph.FindNode("B").Attr.Color = Microsoft.Msagl.Drawing.Color.MistyRose;
            Microsoft.Msagl.Drawing.Node c = graph.FindNode("C");
            c.Attr.Color = Microsoft.Msagl.Drawing.Color.PaleGreen;
            c.Attr.Shape = Microsoft.Msagl.Drawing.Shape.Diamond;
            //bind the graph to the viewer
            viewer.Graph = graph;
            //associate the viewer with the form
            SuspendLayout();
            viewer.Dock = System.Windows.Forms.DockStyle.Fill;
            Controls.Add(viewer);
            ResumeLayout();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            Clear();
        }

        private void Clear()
        {
            tbResult.Visible = false;

            var model = CreateGraph1();
            var ids = model.Nodes.Select(n => n.Key);
            foreach (int i in ids)
            {
                var node = graph.FindNode(i.ToString());
                node.Attr.Color = Microsoft.Msagl.Drawing.Color.LightPink;
                node.Attr.FillColor = Microsoft.Msagl.Drawing.Color.White;
                node.Attr.Shape = Microsoft.Msagl.Drawing.Shape.Circle;
            }

            foreach (var node in model.Nodes)
            {
                var neighbours = node.Value.OutEdges.Select(e => e.NodeId).ToList();
                var source = node.Key;
                foreach (var neighbour in neighbours)
                {
                    var target = neighbour;
                    var edge = FindEdge(graph, source, target);
                    edge.Attr.Color = Microsoft.Msagl.Drawing.Color.LightPink;
                }
            }

            Refresh();
        }

        private void SetResult(List<int> path)
        {
            tbResult.Visible = true;

            if (path.Count() == 0)
            {
                tbResult.Text = "Вершина не достижима";
                return;
            }

            string result = "Путь: ";

            result += string.Join(" ", path);

            tbResult.Text = result;
        }

        private void btnShortPath_Click(object sender, EventArgs e)
        {
            tbResult.Visible = true;

            var graphModel = CreateGraph1();

            int start = (int)numStart.Value;
            int end = (int)numEnd.Value;

            var path = graphModel.GetShortestPath(start, end);

            DrawPath(path);
            SetResult(path);
        }

        private void btnOstov_Click(object sender, EventArgs e)
        {
            var graphModel = CreateGraph1();
            var ostov = graphModel.GetMinimumSpanningTree();
            DrawOstov(ostov);
        }
    }
}
