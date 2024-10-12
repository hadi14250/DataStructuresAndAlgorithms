#include "floodfill-bfs.hpp"

std::vector<std::vector<int> > graph = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
};

int main() {

    bfs floodfill1(graph, {2, 4});
    floodfill1.perform_search();
    floodfill1.printValidPath();

    bfs floodfill2(graph, {1, 0});
    floodfill2.perform_search();
    floodfill2.printValidPath();

    bfs floodfill3(graph, {9, 0});
    floodfill3.perform_search();
    floodfill3.printValidPath();
}
