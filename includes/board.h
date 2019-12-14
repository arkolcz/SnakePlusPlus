#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include <vector>
#include "snake.h"
#include "food.h"

enum class CellType { NONE = 0, BOUNDRY, SNAKE, FOOD };

class GameBoard
{
    private: 
        int width, height;
    public:
        CellType* gameBoard;
        GameBoard(int x, int y);
        ~GameBoard();
        void clear();
        void draw() const;
        void update(std::vector<Node::Point> &v, Position foodPosition);
};
#endif