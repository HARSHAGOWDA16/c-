#ifndef GAME_H
#define GAME_H

#include "location.h"
#include "player.h"

class Game {
private:
    Location ***world;
    Player p;
    int rows;
    int cols;
    int playerRow;
    int playerCol;

public:
    // Constructor & Destructor
    Game();
    ~Game();

    // Methods
    void setUpGame(int rows, int cols);
    void drawGame();
    void playGame();
};

#endif // GAME_H
