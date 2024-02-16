#include <catch2/catch_all.hpp>
#include "../../include/common/Graph.h"

Graph<int, std::string> get_graph() {
    auto graph = Graph<int, std::string>{4};

    graph.add_node(1, "Upper left");
    graph.add_node(2, "Upper right");
    graph.add_node(3, "Lower left");
    graph.add_node(4, "Lower right");

    graph.add_edge(1,2);
    graph.add_edge(1,3);
    graph.add_edge(1, 4);
    graph.add_edge(2, 3);
    graph.add_edge(2, 4);
    graph.add_edge(3, 4);

    return graph;
}

TEST_CASE("Graph nodes are created correctly") {
    auto graph = get_graph();

    REQUIRE(graph.get_node(1) == "Upper left");
    REQUIRE(graph.get_node(2) == "Upper right");
    REQUIRE(graph.get_node(3) == "Lower left");
    REQUIRE(graph.get_node(4) == "Lower right");
}

TEST_CASE("Graph edges are created correctly") {
    auto graph = get_graph();

    REQUIRE(graph.get_adjacency_list(1) == std::unordered_set<int>{2,3,4});
    REQUIRE(graph.get_adjacency_list(2) == std::unordered_set<int>{1,3,4});
    REQUIRE(graph.get_adjacency_list(3) == std::unordered_set<int>{2,1,4});
    REQUIRE(graph.get_adjacency_list(4) == std::unordered_set<int>{2,3,1});
}