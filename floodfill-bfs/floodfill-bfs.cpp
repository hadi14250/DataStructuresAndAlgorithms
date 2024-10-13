#include "floodfill-bfs.hpp"

bfs::bfs(std::vector<std::vector<int>> graph) {
    this->_visited.resize(graph.size());
    this->_graph.resize(graph.size());
    for (size_t i = 0; i < graph.size(); i++) {
        this->_visited[i].resize(graph[i].size(), false);
        this->_graph[i].resize(graph[i].size());
        for (size_t j = 0; j < graph[i].size(); j++)
            this->_graph[i][j] = graph[i][j];
    }
}

void bfs::printGraph() {
    for (const auto &row : _graph) {
        for (int val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    for (size_t i = 0; i < _graph[0].size(); i++)
        std::cout << "--";
    std::cout << std::endl;
}

void bfs::printQueue() {
    for (size_t i = 0; i < this->_queue.size(); i++)
        std::cout
            << "vertex: "
            << "("
            << _queue[i].first
            << ", " << _queue[i].second
            << ")" << " - with value: "
            << _graph[_queue[i].first][_queue[i].second]
            << " -> "
            << (isVisited({_queue[i].first, _queue[i].second}) ? "visited" : "not visited")
            << std::endl;

    for (size_t i = 0; i < _visited[0].size(); i++)
        std::cout << "--";
    std::cout << std::endl;
}

void bfs::printVisited() {
    for (const auto &row : _visited) {
        for (bool val : row)
            std::cout << val << " ";
        std::cout << std::endl;
    }
    for (size_t i = 0; i < _visited[0].size(); i++)
        std::cout << "--";
    std::cout << std::endl;
}

bool bfs::isVisited(std::pair<size_t, size_t> vertex) {
    if (vertex.first < 0 || vertex.second < 0 || vertex.first >= this->_graph.size() || vertex.second >= this->_graph[vertex.first].size())
        throw("Out of bound");
    return (_visited[vertex.first][vertex.second]);
}

void bfs::markVisited(std::pair<size_t, size_t> vertex) {
    if (vertex.first < 0 || vertex.second < 0 || vertex.first >= this->_graph.size() || vertex.second >= this->_graph[vertex.first].size())
        throw("Out of bound");
    this->_visited[vertex.first][vertex.second] = true;
}

void    bfs::resetVisted() {
    for (auto& row : _visited) {
        std::fill(row.begin(), row.end(), false);
    }
}

bool bfs::isOutOfBound(std::pair<size_t, size_t> vertex) {
    return (vertex.first < 0 || vertex.second < 0 || vertex.first >= this->_graph.size() || vertex.second >= this->_graph[vertex.first].size());
}

bool bfs::isValidNeighbor(std::pair<int, int> neighbor, int graphVertexValue) {
    return (!isOutOfBound(neighbor) && _graph[neighbor.first][neighbor.second] == graphVertexValue);
}

std::vector<std::pair<int, int>> bfs::getNeighbors(std::pair<int, int> vertex) {
    std::vector<std::pair<int, int>> neighbors;
    int graphVertexValue = _graph[vertex.first][vertex.second];

    std::vector<std::pair<int,int> > directions = {
        {0, -1}, {0, 1}, {-1, 0}, {+1, 0},
    };

    for(const auto& direction : directions) {
        std::pair<int,int> neighbor = {vertex.first + direction.first, vertex.second + direction.second};
        if (isValidNeighbor(neighbor, graphVertexValue))
            neighbors.push_back(neighbor);
    }

    return (neighbors);
}

std::vector<std::pair<int, int>> bfs::getAllNeighbors(std::pair<int, int> vertex) {
    std::vector<std::pair<int, int>> neighbors;
    int graphVertexValue = _graph[vertex.first][vertex.second];

    std::vector<std::pair<int,int> > directions = {
        {0, -1}, {0, 1}, {-1, 0}, {+1, 0},
        {-1, -1}, {+1, -1}, {-1, +1}, {+1, +1}
    };

    for(const auto& direction : directions) {
        std::pair<int,int> neighbor = {vertex.first + direction.first, vertex.second + direction.second};
        if (isValidNeighbor(neighbor, graphVertexValue))
            neighbors.push_back(neighbor);
    }

    return (neighbors);
}

void bfs::printValidPath() {
    std::cout   << "The valid path for vertex ("
                << _targetVertex.first << ", "
                << _targetVertex.second
                << ") is:\n"
                << std::endl;

    for (size_t i = 0; i < _graph.size(); i++) {
        for (size_t j = 0; j < _graph[i].size(); j++) {
            std::pair<int, int> currentCoord = {i, j};
            bool existsInPath = std::find(_validPath.begin(), _validPath.end(), currentCoord) != _validPath.end();
            if (_targetVertex == std::pair<int, int>(i, j))
                std::cout << "\033[33m";
            else if (existsInPath)
                std::cout << "\033[32m";
            std::cout << _graph[i][j];
            std::cout << "\033[0m";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void bfs::perform_search(std::pair<int,int> targetVertex) {
    if (isOutOfBound(targetVertex))
    {
        std::cout << "\033[31m"
          << "Vertex (" << targetVertex.first << ", " << targetVertex.second << ") is out of range" 
          << "\033[0m" << std::endl;
        return ;
    }
    _targetVertex = targetVertex;
    resetVisted();
    _validPath.clear();
    _queue.push_back(targetVertex);
    while (!_queue.empty()) {
        std::pair<int, int> vertex = _queue.front();
        _queue.pop_front();
        if (!isVisited(vertex)) {
            markVisited(vertex);
            _validPath.push_back(vertex);
            std::vector<std::pair<int, int>> neighbors = getNeighbors(vertex);
            for (auto neighbor : neighbors)
                if (!isVisited(neighbor))
                    _queue.push_back(neighbor);
        }
    }
}

void bfs::perform_diagonal_search(std::pair<int,int> targetVertex) {
    if (isOutOfBound(targetVertex))
    {
        std::cout << "\033[31m"
          << "Vertex (" << targetVertex.first << ", " << targetVertex.second << ") is out of range" 
          << "\033[0m" << std::endl;
        return ;
    }
    _targetVertex = targetVertex;
    resetVisted();
    _validPath.clear();
    _queue.push_back(targetVertex);
    while (!_queue.empty()) {
        std::pair<int, int> vertex = _queue.front();
        _queue.pop_front();

        if (!isVisited(vertex)) {
            markVisited(vertex);
            _validPath.push_back(vertex);
            std::vector<std::pair<int, int>> neighbors = getAllNeighbors(vertex);
            for (auto neighbor : neighbors)
                if (!isVisited(neighbor))
                    _queue.push_back(neighbor);
        }
    }
}