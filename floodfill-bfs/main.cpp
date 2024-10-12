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

    bfs floodfill1(graph);
    floodfill1.perform_search({2, 4});
    floodfill1.printValidPath();

    floodfill1.perform_search({1, 0});
    floodfill1.printValidPath();

    floodfill1.perform_search({9, 0});
    floodfill1.printValidPath();
}
