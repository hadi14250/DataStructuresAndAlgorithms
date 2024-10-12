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

    bfs floodfill(graph);
    floodfill.perform_search({2, 4});
    floodfill.printValidPath();

    floodfill.perform_search({1, 0});
    floodfill.printValidPath();

    floodfill.perform_search({9, 0});
    floodfill.printValidPath();

    floodfill.perform_diagonal_search({9, 0});
    floodfill.printValidPath();

        floodfill.perform_diagonal_search({2, 4});
    floodfill.printValidPath();



}
