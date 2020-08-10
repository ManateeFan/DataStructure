#include <iostream>

#include <iostream>
#include "List.h"
#include "GrapList.h"

int main()
{
    //List list;
    //list.Add(0);
    //list.Add(1);
    //list.Add(2);
    //list.Add(3);
    //list.Remove(2);
    //list.Remove(1);
    //pNode tmp = list.Get(3);
    //std::vector<int> res(list.Values());
    //for (auto i : res)
    //{
    //    std::cout << i << " ";
    //}
    //std::cout << tmp->val << std::endl;
    std::cout << "//1----5" << std::endl;
    std::cout << "//|" << std::endl;
    std::cout << "//2----4----6----8" << std::endl;
    std::cout << "//|" << std::endl;
    std::cout << "//3----7" << std::endl;
    GraphList graph(9);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 4);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 7);
    graph.AddEdge(4, 6);
    graph.AddEdge(6, 8);

    std::cout << "DFSrecursion:\n";
    graph.DFSrecursion(2);
    graph.InitMark();
    std::cout << std::endl;
    std::cout << "DFS:\n";
    graph.DFS(2);
    std::cout << std::endl;
    graph.InitMark();
    std::cout << "BFS:\n";
    graph.BFS(2);
}
