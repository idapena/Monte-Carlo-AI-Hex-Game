#ifndef HEXGAME_HEXGAME_H
#define HEXGAME_HEXGAME_H

#include <memory>
#include "Game.h"
#include "../common/Graph.h"
#include "../enums/PlayerToken.h"
#include "HexBoard.h"
#include "../player/Player.h"
#include "../algorithms/DepthFirstSearch.h"

/**
 * @brief A hex game implementation that uses the `Game` interface.
 */
class HexGame : public Game {
public:
    explicit HexGame() : board_(nullptr), players_() {}

    bool end_game() const override;

    void init() override;

    void update() override;

    void dispose() override;

private:
    bool end_game_ = false;
    std::unique_ptr<HexBoard> board_;
    std::vector<std::unique_ptr<Player>> players_;
    std::unique_ptr<DepthFirstSearch<int, PlayerToken>> path_algorithm_;

    void process_player_turn(const Player &player);

    void analyse_board(const Player &player);

    void end_game_summary(const Player &player, const std::set<int> &path);

};


#endif //HEXGAME_HEXGAME_H
