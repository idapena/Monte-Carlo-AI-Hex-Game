#ifndef HEXGAME_DEPTHFIRSTSEARCH_TPP
#define HEXGAME_DEPTHFIRSTSEARCH_TPP

#include <map>
#include <stack>
#include "../../include/algorithms/DepthFirstSearch.h"

template<typename T, typename V>
std::set<T> DepthFirstSearch<T, V>::get_path(const Graph<T, V> &graph,
                                             const std::unordered_set<T> &starting_pos,
                                             const std::unordered_set<T> &ending_pos,
                                             std::function<bool(const V &)> condition) const {
    std::unordered_set<T> visited_nodes;

    for (T st_node: starting_pos) {
        // Check if the node meets the condition
        if (!condition(graph.get_node(st_node)))
            continue;

        // Current to visit stack
        std::stack<T> to_visit;
        std::map<T, T> parents;
        std::set<T> path;

        // Add starting node
        to_visit.push(st_node);

        while (!to_visit.empty()) {
            // Get the current node to explore
            T current_node = to_visit.top();
            // Remove node from to_visit stack
            to_visit.pop();
            // Mark node as visited
            visited_nodes.insert(current_node);


            // If the node is an ending node, return the path
            if (ending_pos.find(current_node) != ending_pos.end()) {
                while (parents.find(current_node) != parents.end()) {
                    path.insert(current_node);
                    current_node = parents.find(current_node)->second;
                }
                path.insert(st_node);
                return path;
            }

            // Check each adjacent node
            auto adjacency_list = graph.get_adjacency_list(current_node);

            for (T adjacent: adjacency_list) {
                if (condition(graph.get_node(adjacent)) && visited_nodes.find(adjacent) == visited_nodes.end()) {
                    // Add to parent list
                    parents[adjacent] = current_node;
                    to_visit.push(adjacent);
                }
            }
        }
    }

    // Nothing found, returning an empty path
    return std::set<T>();
}


#endif //HEXGAME_DEPTHFIRSTSEARCH_TPP
