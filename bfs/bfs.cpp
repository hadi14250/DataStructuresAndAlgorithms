#include "bfs.hpp"

bfs::bfs(std::vector<std::vector<int>> graph, std::pair<int,int> vertex)
{
    int i = vertex.first;
    int j = vertex.second;
    this->_visited.resize(graph.size());
    this->_graph.resize(graph.size());
    this->_queue.push_back(std::pair(i, j));
    for(size_t i = 0; i < graph.size(); i++)
    {
         this->_visited[i].resize(graph[i].size(), false);
         this->_graph[i].resize(graph[i].size());
         for(size_t j = 0; j < graph[i].size(); j++)
            this->_graph[i][j] = graph[i][j];
    }
}

void bfs::printGraph()
{
    for (const auto& row : _graph) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    for(size_t i = 0; i < _graph[0].size(); i++)
        std::cout << "--";
    std::cout << std::endl;
}

void bfs::printQueue()
{
    for (size_t i = 0; i < this->_queue.size(); i++)
        std::cout
        << "vertex: "
        << "("
        << _queue[i].first
        << ", " << _queue[i].second
        << ")"  << " - with value: "
        << _graph[_queue[i].first][_queue[i].second]
        <<  " -> "
        << (isVisited({_queue[i].first, _queue[i].second}) ? "visited" : "not visited")
        << std::endl;

    for(size_t i = 0; i < _visited[0].size(); i++)
        std::cout << "--";
    std::cout << std::endl;
}

void bfs::printVisited()
{
    for (const auto& row : _visited) {
        for (bool val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    for(size_t i = 0; i < _visited[0].size(); i++)
        std::cout << "--";
    std::cout << std::endl;
}

bool    bfs::isVisited(std::pair<size_t,size_t> vertex) {
    if (vertex.first < 0 || vertex.second < 0 || vertex.first >= this->_graph.size() || vertex.second >= this->_graph[vertex.first].size())
        throw ("Out of bound");
    return (_visited[vertex.first][vertex.second]);
}

void    bfs::markVisited(std::pair<size_t,size_t> vertex)
{
    if (vertex.first < 0 || vertex.second < 0 || vertex.first >= this->_graph.size() || vertex.second >= this->_graph[vertex.first].size())
        throw ("Out of bound");
    this->_visited[vertex.first][vertex.second] = true;
}

void    bfs::perform_search()
{
    while(!_queue.empty()) {
        std::pair<int,int> popped = _queue.front();
        _queue.pop_front();

        std::cout << "popped->first: " << popped.first << ", popped->second: " << popped.second << std::endl;
    }
}
