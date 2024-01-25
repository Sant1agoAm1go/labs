using Lab4;

namespace Test
{
    [TestClass]
    public class GraphUnitTests
    {
        private Graph CreateShortPathGraph()
        {
            var graphModel = new Graph();
            graphModel.Nodes.Add(1,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 6, Weight = 14 }, new Edge { NodeId = 3, Weight = 4 } },
                    new List<Edge>()));
            graphModel.Nodes.Add(2,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 5, Weight = 7 }, new Edge { NodeId = 3, Weight = 10 }, new Edge { NodeId = 4, Weight = 15 } },
                    new List<Edge>()));
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
            return graphModel;
        }

        private Graph CreateMstGraph1()
        {
            var graphModel = new Graph();
            graphModel.Nodes.Add(1,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 6, Weight = 14 }, new Edge { NodeId = 2, Weight = 5 }, new Edge { NodeId = 3, Weight = 4 } },
                    new List<Edge>()));
            graphModel.Nodes.Add(2,
                new Node(
                    new List<Edge>() { new Edge { NodeId = 5, Weight = 7 }, new Edge { NodeId = 3, Weight = 10 }, new Edge { NodeId = 4, Weight = 15 } },
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
            return graphModel;
        }

private Graph CreateMstGraph2()
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

        private string PathToString(List<int> path)
        {
            return string.Join(" ", path);
        }

        [TestMethod]
        public void GetShortestDistanceTest()
        {
            var graph = CreateShortPathGraph();
            int result = graph.GetShortestDistance(1, 5);
            result = graph.GetShortestDistance(1, 2);
            Assert.AreEqual(result, int.MaxValue);
            result = graph.GetShortestDistance(1, 3);
            Assert.AreEqual(result, 4);
            result = graph.GetShortestDistance(1, 4);
            Assert.AreEqual(result, 13);
            result = graph.GetShortestDistance(1, 5);
            Assert.AreEqual(result, 19);
            result = graph.GetShortestDistance(1, 6);
            Assert.AreEqual(result, 14);
        }

        [TestMethod]
        public void PathNotFoundTest()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(1, 2);
            Assert.AreEqual(0, result.Count());
        }

        [TestMethod]
        public void ShortestPathTest1()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(1, 3);
            Assert.AreEqual("1 3", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest2()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(1, 4);
            Assert.AreEqual("1 3 4", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest3()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(1, 5);
            Assert.AreEqual("1 3 4 5", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest4()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(1, 6);
            Assert.AreEqual("1 6", PathToString(result));
        }

[TestMethod]
        public void ShortestPathTest5()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(2, 3);
            Assert.AreEqual("2 3", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest6()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(2, 4);
            Assert.AreEqual("2 4", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest7()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(2, 5);
            Assert.AreEqual("2 5", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest8()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(2, 6);
            Assert.AreEqual("2 5 6", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest9()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(3, 6);
            Assert.AreEqual("3 4 6", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest10()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(4, 6);
            Assert.AreEqual("4 6", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest11()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(5, 3);
            Assert.AreEqual("5 6 3", PathToString(result));
        }

        [TestMethod]
        public void ShortestPathTest12()
        {
            var graph = CreateShortPathGraph();
            List<int> result = graph.GetShortestPath(6, 5);
            Assert.AreEqual("6 3 4 5", PathToString(result));
        }

        [TestMethod]
        public void MstTest1()
        {
            var graph = CreateMstGraph1();
            var result = graph.GetMinimumSpanningTree();
            Assert.AreEqual(5, result.Count);

            Assert.AreEqual(1, result[0].Item1);
            Assert.AreEqual(3, result[0].Item2);

            Assert.AreEqual(1, result[1].Item1);
            Assert.AreEqual(2, result[1].Item2);

            Assert.AreEqual(2, result[2].Item1);
            Assert.AreEqual(5, result[2].Item2);

            Assert.AreEqual(3, result[3].Item1);
            Assert.AreEqual(4, result[3].Item2);

            Assert.AreEqual(4, result[4].Item1);
            Assert.AreEqual(6, result[4].Item2);
        }

        [TestMethod]
        public void MstTest2()
        {
            var graph = CreateMstGraph2();
            var result = graph.GetMinimumSpanningTree();
            Assert.AreEqual(6, result.Count);

            Assert.AreEqual(1, result[0].Item1);
            Assert.AreEqual(3, result[0].Item2);

            Assert.AreEqual(1, result[1].Item1);
            Assert.AreEqual(2, result[1].Item2);

            Assert.AreEqual(2, result[2].Item1);
            Assert.AreEqual(5, result[2].Item2);

            Assert.AreEqual(3, result[3].Item1);
            Assert.AreEqual(4, result[3].Item2);

            Assert.AreEqual(4, result[4].Item1);
            Assert.AreEqual(6, result[4].Item2);

            Assert.AreEqual(2, result[5].Item1);
            Assert.AreEqual(7, result[5].Item2);
        }
    }
}
