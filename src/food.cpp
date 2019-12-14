#include "../includes/food.h"
#include <random>

Food::Food(int boardWidth, int boardHeight)
{
    this->boardWidth = boardWidth;
    this->boardHeight = boardHeight;
}

void Food::spawn(std::vector<Node::Point> &v)
{
    // Spawn location can't be snake location
    bool spawnLocationOK = false;
    while(!spawnLocationOK)
    {
        std::random_device rd;
        std::mt19937 eng(rd());
        std::uniform_int_distribution<> distrx(1,boardWidth-2);
        std::uniform_int_distribution<> distry(1,boardHeight-2);
        pos.x = distrx(eng);
        pos.y = distry(eng);
        spawnLocationOK = checkColision(pos.x, pos.y, v);
    }
}

Position Food::getLocation()
{
    return pos;
}

bool Food::checkColision(int x, int y, std::vector<Node::Point> &v)
{
    for(std::vector<Node::Point>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if((it->x == x) && (it->y == y))
        {
            return false;
        }
    }
    return true;
}