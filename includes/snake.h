#ifndef SNAKE_H
#define SNAKE_H
#include <vector> 

struct Node 
{
    struct Point { int x, y; } point; 
    Node* next;
    Node() = default;
    Node(const Node &n);
};

class Snake
{
    private: 
        Node* head;
        Node* tail;  
    public:
        Snake(int boardWidth, int boardHeight);
        ~Snake();
        void getLocation(std::vector<Node::Point> &v);
        void move(char direction);
        void removeLastNode();
        void updateFirstNode(int x, int y);
};
#endif