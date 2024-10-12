
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
    
    bfs();

public:
    bfs(std::vector<std::vector<int> > graph, std::pair<int,int> vertex);

    void    printGraph();
    void    printQueue();
    void    printVisited();
    void    markVisited(std::pair<size_t,size_t> vertex);
    bool    isVisited(std::pair<size_t,size_t> vertex);
    void    perform_search();
};