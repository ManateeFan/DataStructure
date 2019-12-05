#include <iostream>
#include "Graph.h"
#include "Bag.h"
using namespace std;

int main()
{
	Graph graph(6);

	graph.AddEdge(0, 1);
	graph.AddEdge(0, 2);
	graph.AddEdge(1, 3);
	graph.AddEdge(2, 4);
	graph.AddEdge(3, 4);
	graph.AddEdge(4, 0);
	graph.AddEdge(5, 5);
	cout << "0 degree: " << graph.Degree(0) << endl;
	cout << "1 degree: " << graph.Degree(1) << endl;
	cout << "2 degree: " << graph.Degree(2) << endl;
	cout << "3 degree: " << graph.Degree(3) << endl;
	cout << "4 degree: " << graph.Degree(4) << endl;

	Bag* bag = graph.Adjs(0);
	cout << "bags[0] itemNum: " << bag->GetNum() << endl;
	cout << "2 1 connected: " << graph.Connected(2, 1) << endl;
	cout << "max degree: " << graph.MaxDegree() << endl;

	graph.AddEdge(4, 4);
	cout << "self loop: " << graph.SelfLoop() << endl;

	cout << "depth first search: " << graph.DepthFirstSearch(4) << endl;

	graph.BreadthFirstSearch(1);
	return 0;
}