#ifndef GAME_H
#define GAME_H
#include "snake.h"
#include "board.h"
#include "food.h"

class Game
{
    private:
        int width;
        int height;
        int gamePace;
        bool isGameOver;
        char direction;
        GameBoard board;
        Snake snake;
        Food food;
    public:
        Game();
        void keyPressListener();
        void start();
        void checkMoveResult(std::vector<Node::Point> &v);
        void handleBoundryColision(int &x, int &y);
};
#endif 