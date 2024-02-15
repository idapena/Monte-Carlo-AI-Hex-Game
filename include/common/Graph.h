#ifndef HEXGAME_GRAPH_H
#define HEXGAME_GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <iostream>
#include <vector>

/**
 * @brief A class representing an undirected graph_.
 *
 * @tparam T The type of the vertex index.
 * @tparam V The type of the vertex value.
 */
template<typename T, typename V>
class Graph {
public:
    /**
     * @brief Constructs a graph_ with optional initial capacity for vertices.
     *
     * @param initialVertexCapacity The initial capacity for the vertex set.
     */
    explicit Graph(std::size_t initialVertexCapacity)
            : vertices_(initialVertexCapacity),
              adjacency_list_(initialVertexCapacity) {};

    /**
     * @brief Construct a new Graph object by copying the vertices and adjacency list from an existing graph_.
     *
     * @param graph The graph_ to be copied.
     */
    Graph(const Graph<T, V> &graph) {
        // Copy the vertices
        for (const auto &vertex: graph.vertices_) {
            vertices_[vertex.first] = vertex.second;
        }

        // Copy the adjacency list
        for (const auto &adjacency: graph.adjacency_list_) {
            adjacency_list_[adjacency.first] = adjacency.second;
        }
    }

    /**
     * @brief Adds a vertex with content to the graph_.
     *
     * @param vertex The vertex to be added.
     * @param content The content associated with the vertex.
     */
    void add_node(const T &vertex, const V &content);

    /**
     * @brief Adds an edge between two vertices in the graph_.
     * The graph_ is undirected, so the edge is bidirectional.
     *
     * @param vertex1 The first vertex of the edge.
     * @param vertex2 The second vertex of the edge.
     */
    void add_edge(const T &vertex1, const T &vertex2);

    /**
     * @brief Checks if a vertex exists in the graph_.
     *
     * @param vertex The vertex to check.
     * @return `true` if the vertex exists, `false` otherwise.
     */
    bool has_node(const T &vertex) const;

    /**
     * @brief Checks if an edge exists between two vertices in the graph_.
     *
     * @param vertex1 The first vertex of the edge.
     * @param vertex2 The second vertex of the edge.
     * @return `true` if the edge exists, `false` otherwise.
     */
    bool has_edge(const T &vertex1, const T &vertex2) const;

    /**
     * @brief Gets the content of a vertex.
     * @param vertex The vertex to get content.
     * @return The content of a vertex.
     */
    const V &get_node(const T &vertex) const;

    /**
    * @brief Sets the content of a vertex.
    * @param vertex The vertex to set content.
    * @param content Content of the vertex.
    */
    void update_node(const T &vertex, const V &content);

    /**
     * @brief Retrieves the adjacency list of a given vertex.
     * @param vertex The vertex for which to retrieve the adjacency list.
     * @return A reference to the adjacency list of the specified vertex.
     */
    const std::unordered_set<T> &get_adjacency_list(const T &vertex) const;


    /**
     * @brief Overloaded stream insertion operator for the `Graph` class.
     *
     * This operator allows the Graph class to be printed to an output stream.
     * It prints the vertices and their content, as well as the adjacency list
     * of each vertex.
     *
     * @param out The output stream to print the graph_ to.
     * @param graph The Graph object to be printed.
     * @return A reference to the output stream after printing the graph_.
     */
    friend std::ostream &operator<<(std::ostream &out, const Graph<T, V> &graph) {
        for (const auto &vertex: graph.vertices_) {
            out << "Vertex: " << vertex.first << ", Content: " << static_cast<int>(vertex.second) << '\n';
            if (graph.adjacency_list_.count(vertex.first) > 0) {
                out << "Adjacency List: ";
                for (const auto &neighbor: graph.adjacency_list_.at(vertex.first)) {
                    out << neighbor << ' ';
                }
                out << '\n';
            }
        }
        return out;
    }

private:
    std::unordered_map<T, V> vertices_;                           /** Map of vertices and their content. */
    std::unordered_map<T, std::unordered_set<T>> adjacency_list_; /** Adjacency list representation of the graph_. */
};

#include "../../src/common/Graph.tpp"

#endif //HEXGAME_GRAPH_H
