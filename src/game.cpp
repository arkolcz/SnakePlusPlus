#include "../includes/game.h"
#include <unistd.h>
#include <iostream>
#ifdef WINDOWS
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif 
    
Game::Game() :
    width{30}, // Board width
    height{30}, // Board height 
    snake{width, height},
    board{width, height},
    food{width, height},
    gamePace{1}, // Represents a delay in seconds introduced to the main game loop
    score{0},
    isGameOver{false} 
{}

void Game::keyPressListener()
{
    // TODO: Create keyPress handling for windows and other systems
    direction = 'W';
}

void Game::handleBoundryColision(int &x, int &y)
{
    // On collision with boundry move snake to the
    // opposite side of the same row/col
    if(x == 0)
    {
        x = width-1;
    }
    else if(x == width-1)
    {
        x = 1;
    }
    else if(y == 0)
    {
        y = height-1;
    }
    else if(y == height-1)
    {
        y = 1;
    }
    snake.updateFirstNode(x, y);
}

void Game::checkMoveResult(std::vector<Node::Point> &v)
{
    /* Check game logic */
    Node::Point &head = v.front();
    switch(board.gameBoard[head.x + head.y * width])
    {
        case CellType::FOOD:
            food.spawn(v);
            score++;
            break;
        case CellType::SNAKE:
            isGameOver = true;
            break;
        case CellType::BOUNDRY:
            handleBoundryColision(head.x, head.y);
            snake.removeLastNode();
            break;
        case CellType::NONE:
            snake.removeLastNode();
            break;
    }
}

void Game::start()
{
    std::vector<Node::Point> snakeLocation;
    food.spawn(snakeLocation); // Spawn initial food
    while(!isGameOver)
    {
        /* Main game loop */
        keyPressListener();
        // Update board with current sanke location
        board.clear();
        snakeLocation.clear();
        snake.getLocation(snakeLocation);
        board.update(snakeLocation, food.getLocation());
        board.draw(score);
        // Make a move and update snake location 
        snake.move(direction);
        snakeLocation.clear();
        snake.getLocation(snakeLocation);
        checkMoveResult(snakeLocation);
        sleep(gamePace);
        system(CLEAR);
    }
}
