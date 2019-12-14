#ifndef FOOD_H
#define FOOD_H
#include "snake.h"
#include <vector>

struct Position { int x,  y; };

class Food  
{
    private:
        int boardWidth, boardHeight;
        Position pos;
    public:
        Food(int boardWidth, int boardHeight);
        void spawn(std::vector<Node::Point> &v);
        bool checkColision(int x, int y, std::vector<Node::Point> &v);
        Position getLocation();        
};
#endif 