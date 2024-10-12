#include "bfs.hpp"

std::vector<std::vector<int> > graph = {
    {3, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1},
    {1, 1, 6, 21, 0, 1, 1},
    {1, 0, 55, 1, 0, 17, 1},
    {1, 0, 0, 0, 1, 1, 1},
};

int main()
{
    bfs hadi(graph, {2, 3});

    hadi.printGraph();
    hadi.printQueue();
}
