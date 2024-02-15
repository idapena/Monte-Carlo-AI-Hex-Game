#ifndef HEXGAME_HEXBOARD_H
#define HEXGAME_HEXBOARD_H

#include <iomanip>
#include <memory>
#include "../enums/PlayerToken.h"
#include "../common/Graph.h"
#include "../enums/PlayingSide.h"
#include "../game/GameSettings.h"
#include "../algorithms/PathAlgorithm.h"

template<typename T>
struct SidePaths {
    std::unordered_set<T> starting_positions;
    std::unordered_set<T> ending_positions;
};

/**
 * @brief Represents a board for an Hex game.
 */
class HexBoard {
public:
    const int tiles_per_side; /** Number of tile that exist per side of the board. */;
    const int num_tiles; /** Total amount of tiles that the board has. */

    /**
     * @brief Builds a new hex board.
     *
     * @param tiles_per_side Tiles per side of the square board.
     */
    explicit HexBoard(const int tiles_per_side) :
            graph_(tiles_per_side),
            tiles_per_side(tiles_per_side),
            num_tiles(tiles_per_side * tiles_per_side),
            board_mask_(tiles_per_side * tiles_per_side, false),
            token_representation_() {

        // Define player's tokens representation
        token_representation_.emplace(PlayerToken::PLAYER, 'x');
        token_representation_.emplace(PlayerToken::AI, 'o');
        token_representation_.emplace(PlayerToken::NONE, '*');

        // Add board tiles
        for (int tile_id = 0; tile_id < num_tiles; ++tile_id)
            graph_.add_node(tile_id, PlayerToken::NONE);

        // Link board tiles
        for (int row = 0; row < tiles_per_side; ++row)
            for (int col = 0; col < tiles_per_side; ++col) {
                int current_pos = row * static_cast<int>(tiles_per_side) + col;
                if (row > 0) { // If the tile is not at top of the board
                    graph_.add_edge(current_pos, current_pos - static_cast<int>(tiles_per_side));
                    if (col + 1 < tiles_per_side)
                        graph_.add_edge(current_pos, current_pos + 1 - static_cast<int>(tiles_per_side));
                }

                if (col + 1 < tiles_per_side) // If the tile is not at right of the board
                    graph_.add_edge(current_pos, current_pos + 1);
            }

        // Store winning and ending positions for horizontal player
        side_paths_[PlayingSide::HORIZONTAL] = SidePaths<int>{};
        side_paths_[PlayingSide::VERTICAL] = SidePaths<int>{};
        for (int i = 0; i < tiles_per_side; ++i) {
            side_paths_[PlayingSide::VERTICAL].starting_positions.insert(i);
            side_paths_[PlayingSide::VERTICAL].ending_positions.insert(num_tiles - tiles_per_side + i);
            side_paths_[PlayingSide::HORIZONTAL].starting_positions.insert(i * tiles_per_side);
            side_paths_[PlayingSide::HORIZONTAL].ending_positions.insert(i * tiles_per_side + tiles_per_side - 1);
        }
    };

    /**
     * @brief Checks if the selected tile is free.
     *
     * @param tile Tile to check.
     * @return Returns `true` if the tile is not played, else `false`.
     */
    bool is_tile_free(const int &tile) const;

    /**
    * @brief Gets the content of a tile.
    *
    * @param token Player token.
    * @Return Returns the `char` representation of the player token on board.
    */
    char get_player_token(const PlayerToken &token) const;

    /**
     * @brief Gets the content of a tile.
     *
     * @param tile Tile to get the content.
     * @Return Returns the content of the tile.
     */
    PlayerToken get_tile(const int &tile) const;

    /**
     * @brief Gets a graph_ representation of the board.
     *
     * @return Returns a graph_ representation of the board.
     */
    Graph<int, PlayerToken> get_board_graph() const;

    /**
     * @brief Get a mask of the board occupied tiles.
     *
     * @return Returns a `std::vector<bool>` with the occupied tiles of the board.
     */
    std::vector<bool> get_board_mask() const;

    /**
     * @brief Gets board side paths for the specified side.
     *
     * @return Side paths for the specified side.
     */
    const SidePaths<int> &get_sides_paths(const PlayingSide &side) const;

    /**
     * @brief Sets a token on a specified tile.
     *
     * @param tile Tile to set the content.
     * @param token Tile owner token.
     */
    void update_tile(int tile, PlayerToken token);


    /**
     * @brief Overloaded stream insertion operator for the `HexBoard` class.
     *
     * This operator allows the board to be printed using player tokens and
     * representation.
     *
     * @param out The output stream to print the graph_ to.
     * @param graph The Graph object to be printed.
     * @return A reference to the output stream after printing the graph_.
     */
    friend std::ostream &operator<<(std::ostream &out, const HexBoard &board) {
        std::cout << std::endl << "    ";

        for (int row = 0; row < board.tiles_per_side; ++row)
            std::cout << std::left << std::setw(4) << std::setfill(' ') << row + 1;
        std::cout << std::endl;

        for (int row = 0; row < board.tiles_per_side; ++row) {

            std::cout << std::left << std::setw(4) << std::setfill(' ') << row + 1;

            // Graphical gap
            for (int i = 0; i < row * 2; ++i)
                std::cout << " ";

            // Token row print
            for (int col = 0; col < board.tiles_per_side; ++col) {
                PlayerToken token = board.get_tile(row * board.tiles_per_side + col);
                std::cout << board.token_representation_.find(token)->second;
                if (col + 1 < board.tiles_per_side)
                    std::cout << " - ";
            }
            std::cout << std::endl;

            std::cout << "    ";
            for (int i = 0; i < row * 2 + 1; ++i)
                std::cout << " ";

            if (row + 1 < board.tiles_per_side)
                for (int col = 0; col < board.tiles_per_side; ++col) {
                    if (col > 0)
                        std::cout << "/ ";

                    std::cout << "\\ ";
                }

            std::cout << std::endl;
        }

        return out;
    };

private:
    Graph<int, PlayerToken> graph_;
    std::unordered_map<PlayerToken, char> token_representation_;
    std::unordered_map<PlayingSide, SidePaths<int>> side_paths_;
    std::vector<bool> board_mask_;
};

#endif //HEXGAME_HEXBOARD_H

