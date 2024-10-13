
#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <utility>

class   bfs {
private:
    bfs();

    std::vector<std::vector<int> >          _graph;
    std::vector<std::vector<bool> >         _visited;
    std::pair<int,int>                      _targetVertex;
    std::deque<std::pair<size_t, size_t> >  _queue;
    std::vector<std::pair<int,int> >        _validPath;

    bool                                    isOutOfBound(std::pair<size_t,size_t> vertex);
    bool                                    isVisited(std::pair<size_t,size_t> vertex);
    void                                    markVisited(std::pair<size_t,size_t> vertex);
    std::vector<std::pair<int,int> >        getNeighbors(std::pair<int,int> vertex);
    std::vector<std::pair<int, int>>        getAllNeighbors(std::pair<int, int> vertex);
    bool                                    isValidNeighbor(std::pair<int,int> neighbor, int graphVertexValue);
    void                                    resetVisted();

public:
    bfs(std::vector<std::vector<int> > graph);

    void    perform_search(std::pair<int,int> targetVertex);
    void    perform_diagonal_search(std::pair<int,int> targetVertex);

    void    printGraph();
    void    printQueue();
    void    printVisited();
    void    printValidPath();

};