#ifndef HEXGAME_DEPTHFIRSTSEARCH_H
#define HEXGAME_DEPTHFIRSTSEARCH_H

#include "PathAlgorithm.h"

/**
 * @brief Represents a Depth-First Search algorithm approach.
 *
 * @tparam T Vertex key.
 * @tparam V Vertex content.
 */


template<typename T, typename V>
class DepthFirstSearch : public PathAlgorithm<T, V> {
public:

    std::set<T> get_path(const Graph<T, V> &graph,
                         const std::unordered_set<T> &starting_pos,
                         const std::unordered_set<T> &ending_pos,
                         std::function<bool(const V &token)> condition) const override;
};

#include "../../src/algortihms/DepthFirstSearch.tpp"

#endif //HEXGAME_DEPTHFIRSTSEARCH_H
