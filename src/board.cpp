#include "../includes/board.h" 
#include <iostream>

GameBoard::GameBoard(int x, int y) : width{x}, height{y}
{
    gameBoard = new CellType[width * height];
    clear(); // Initizalize the board with boundries
}

GameBoard::~GameBoard()
{
    delete[] gameBoard;
}

void GameBoard::clear()
{
    // Set board boundries and change everyting else to none
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(i == 0 || i == width - 1 ||
                j == 0 || j == height - 1)
            {
                gameBoard[i + j * width] = CellType::BOUNDRY;
            }
            else
            {
                gameBoard[i + j * width] = CellType::NONE;
            }
        }
    }
}

void GameBoard::draw() const
{
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            switch(gameBoard[i + j * width])
            {
                case CellType::BOUNDRY : std::cout << "#"; break;
                case CellType::SNAKE   : std::cout << "X"; break;
                case CellType::FOOD    : std::cout << "F"; break;
                case CellType::NONE    : std::cout << " "; break;
            }
        }
        std::cout << '\n';
    }
}

void GameBoard::update(std::vector<Node::Point> &snakePosition, Position foodPosition)
{
    // Update snake position
    for(std::vector<Node::Point>::iterator it = snakePosition.begin(); it != snakePosition.end(); ++it)
    {
        gameBoard[it->x + it->y * width] = CellType::SNAKE;
    }
    // Update food position
    gameBoard[foodPosition.x + foodPosition.y * width] = CellType::FOOD;
}
