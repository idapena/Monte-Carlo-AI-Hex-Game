/**
 * @file Graph.cpp
 * @brief Implementation file for the Graph class.
 */

#include "../../include/common/Graph.h"

template<typename T, typename V>
void Graph<T, V>::add_node(const T &node, const V &content) {
    vertices_.emplace(node, content);
}

template<typename T, typename V>
void Graph<T, V>::add_edge(const T &node1, const T &node2) {
    vertices_.emplace(node1, V{});
    vertices_.emplace(node2, V{});
    adjacency_list_[node1].emplace(node2);
    adjacency_list_[node2].emplace(node1);
}

template<typename T, typename V>
bool Graph<T, V>::has_node(const T &vertex) const {
    return vertices_.count(vertex) > 0;
}

template<typename T, typename V>
bool Graph<T, V>::has_edge(const T &node1, const T &node2) const {
    if (has_node(node1) && has_node(node2)) {
        const auto &neighbors = adjacency_list_.at(node1);
        return neighbors.count(node2) > 0;
    }
    return false;
}

template<typename T, typename V>
const V &Graph<T, V>::get_node(const T &node) const {
    return vertices_.at(node);
}

template<typename T, typename V>
void Graph<T, V>::update_node(const T &node, const V &content) {
    vertices_[node] = content;
}

template<typename T, typename V>
const std::unordered_set<T> &Graph<T, V>::get_adjacency_list(const T &node) const {
    return adjacency_list_.at(node);
}