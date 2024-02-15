#ifndef HEXGAME_PATHALGORITHM_H
#define HEXGAME_PATHALGORITHM_H

#include <set>
#include "../common/Graph.h"

template<typename T, typename V>
class PathAlgorithm {
public:

    virtual ~PathAlgorithm() = default;

    /**
     * @brief Finds a path between a nodes.
     *
     * @param graph Graph object to find the path over.
     * @param condition Filtering condition for each node (if any).
     * @return Returns a `set` with the founded path, else an empty `set`.
     */
    virtual std::set<T> get_path(const Graph<T, V> &graph,
                                 const std::unordered_set<T> &starting_pos,
                                 const std::unordered_set<T> &ending_pos,
                                 std::function<bool(const V &token)> condition) const = 0;
};

#endif //HEXGAME_PATHALGORITHM_H
