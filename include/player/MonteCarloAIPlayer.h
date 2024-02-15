#ifndef HEXGAME_MONTECARLOAIPLAYER_H
#define HEXGAME_MONTECARLOAIPLAYER_H

#include <bitset>
#include <random>
#include "Player.h"

class MonteCarloAIPlayer : public Player {
public:
    explicit MonteCarloAIPlayer(PlayingSide side, PathAlgorithm<int, PlayerToken> &path_algorithm) :
            Player(PlayerToken::AI, side),
            path_algorithm_(path_algorithm),
            samples_per_move(GameSettings::get_ai_samples_per_move()) {}

    int get_next_move(const HexBoard &board) const override;

private:
    PathAlgorithm<int, PlayerToken> &path_algorithm_;
    int samples_per_move;
};


#endif //HEXGAME_MONTECARLOAIPLAYER_H
