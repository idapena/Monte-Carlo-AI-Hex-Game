/**
 * @file HexBoard.cpp
 * @brief Implementation file for the `HexBoard` class.
 */

#include "../../include/game/HexBoard.h"

bool HexBoard::is_tile_free(const int &tile) const {
    return graph_.get_node(tile) == PlayerToken::NONE;
}

PlayerToken HexBoard::get_tile(const int &tile) const {
    return graph_.get_node(tile);
}

Graph<int, PlayerToken> HexBoard::get_board_graph() const {
    return Graph{graph_};
}

std::vector<bool> HexBoard::get_board_mask() const {
    return board_mask_;
}

void HexBoard::update_tile(const int tile, const PlayerToken token) {
    graph_.update_node(tile, token);
    board_mask_[tile] = true;
}

const SidePaths<int> &HexBoard::get_sides_paths(const PlayingSide &side) const {
    return side_paths_.find(side)->second;
}

char HexBoard::get_player_token(const PlayerToken &token) const {
    return token_representation_.find(token)->second;
}
