
#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

class   bfs {
private:
    std::vector<std::vector<bool> > _visited;
    std::vector<std::vector<int> > _graph;
    std::deque<std::pair<size_t, size_t> > _queue;
    std::vector<std::pair<int,int> > _validPath;

    bfs();
    bool    isOutOfBound(std::pair<size_t,size_t> vertex);
    bool    isVisited(std::pair<size_t,size_t> vertex);
    void    markVisited(std::pair<size_t,size_t> vertex);
    std::vector<std::pair<int,int> > getNeighbors(std::pair<int,int> vertex);
    bool    isValidNeighbor(std::pair<int,int> neighbor, int graphVertexValue);

public:
    bfs(std::vector<std::vector<int> > graph, std::pair<int,int> vertex);

    void    printGraph();
    void    printQueue();
    void    printVisited();
    void    perform_search();
    void    printValidPath();

};