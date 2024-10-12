#include "floodfill-bfs.hpp"

std::vector<std::vector<int> > graph1 = {
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

std::vector<std::vector<int>> graph2 = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0}
};

std::vector<std::vector<int>> graph3 = {
    {1, 0, 1, 1},
    {0, 1, 0, 1, 1, 0},
    {1, 1, 1},
    {0, 0, 1, 1, 0},
    {1, 0, 1, 0}
};


int main() {

    bfs floodfill1(graph1);
    floodfill1.perform_search({2, 4});
    floodfill1.printValidPath();

    floodfill1.perform_search({1, 0});
    floodfill1.printValidPath();

    floodfill1.perform_search({9, 0});
    floodfill1.printValidPath();

    floodfill1.perform_diagonal_search({9, 0});
    floodfill1.printValidPath();

    floodfill1.perform_diagonal_search({2, 4});
    floodfill1.printValidPath();

    bfs floodfill2(graph2);
    floodfill2.perform_search({2, 4});
    floodfill2.printValidPath();

    floodfill2.perform_search({1, 0});
    floodfill2.printValidPath();

    floodfill2.perform_search({9, 0});
    floodfill2.printValidPath();

    floodfill2.perform_diagonal_search({9, 0});
    floodfill2.printValidPath();

    floodfill2.perform_diagonal_search({2, 4});
    floodfill2.printValidPath();

    bfs floodfill3(graph3);
    floodfill3.perform_search({1, 1});
    floodfill3.printValidPath();

    floodfill3.perform_diagonal_search({1, 1});
    floodfill3.printValidPath();

}
