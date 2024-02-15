#include "../../include/player/MonteCarloAIPlayer.h"

int MonteCarloAIPlayer::get_next_move(const HexBoard &board) const {
    Graph<int, PlayerToken> graph = board.get_board_graph();
    std::vector<bool> board_mask = board.get_board_mask();
    SidePaths<int> positions = board.get_sides_paths(side);

    // Move stats
    std::vector<int> tile_stats = std::vector<int>(board.num_tiles, 0);

    // Get free positions
    auto free_positions = std::vector<int>();
    for (int pos = 0; pos < board.num_tiles; ++pos)
        if (!board_mask[pos]) free_positions.push_back(pos);

    // Generate a random function
    std::random_device rd;
    std::mt19937 g(rd());

    for (int sample = 0; sample < samples_per_move; ++sample) {
        // Randomly sort the positions
        std::shuffle(free_positions.begin(), free_positions.end(), g);

        for (int i = 0; i < free_positions.size(); ++i) {
            if (i % 2 == 0)
                graph.update_node(free_positions[i], PlayerToken::AI);
            else
                graph.update_node(free_positions[i], PlayerToken::PLAYER);
        }

        // Analyze board
        auto path = path_algorithm_.get_path(
                graph,
                positions.starting_positions,
                positions.ending_positions,
                [](const PlayerToken &token) { return token == PlayerToken::AI; }
        );

        // If AI won, update stats
        if (!path.empty())
            for (int i = 0; i < free_positions.size(); i += 2)
                tile_stats[free_positions[i]] += 1;

    }

    int max = 0;
    for (int i = 0; i < tile_stats.size(); i++)
        if (tile_stats[max] < tile_stats[i])
            max = i;

    return max;
};