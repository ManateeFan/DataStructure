#include <iostream>
#include "GraphMatrix.h"

int main() {
    char vtxs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
            {'A', 'B'},
            {'B', 'C'},
            {'B', 'F'},
            {'C', 'E'},
            {'D', 'C'},
            {'E', 'B'},
            {'E', 'D'},
            {'F', 'G'}};


    GraphMatrix<7> graph(vtxs, edges);

    graph.Print();

    graph.DFSrecursion('E');
    std::cout << std::endl;
    graph.InitMark();
    graph.DFS('E');
    graph.InitMark();
    std::cout << std::endl;
    graph.BFS('E');
    return 0;
}

