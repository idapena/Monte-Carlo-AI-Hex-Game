#ifndef HEXGAME_GAME_H
#define HEXGAME_GAME_H

/**
 * @brief A class interface representing a generic game life cycle.
 */
class Game {
public:
    /**
     * @brief if the game should end.
     *
     * @return Returns `true` if the game should end, else `false`.
     */
    virtual bool end_game() const = 0;

    /**
     * @brief Inits the game before any update.
     */
    virtual void init() = 0;

    /**
     * @brief Updates the game status.
     */
    virtual void update() = 0;


    /**
     * @brief Clears all remaining data of the game.
     */
    virtual void dispose() = 0;

    /**
     * @brief Defines the game loop.
     */
    void game_loop() {
        init();
        while (!end_game()) {
            update();
        }
        dispose();
    }

    virtual ~Game() = default;
};

#endif //HEXGAME_GAME_H
