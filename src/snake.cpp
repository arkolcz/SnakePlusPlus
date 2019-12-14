#include "../includes/snake.h"

Snake::Snake(int boardWidth, int boardHeight)
{
    // Create head and tail of the snake
    head = new Node();
    tail = new Node();
    // Initialize snake at the center of the board
    head->point.x = boardWidth/2;
    head->point.y = boardHeight/2;
    tail->point.x = boardWidth/2-1;
    tail->point.y = boardHeight/2-1;
    // Assign pointers to next node 
    head->next = tail;
    tail->next = nullptr; 
}

Node::Node(const Node& n)
{
    point.x = n.point.x;
    point.y = n.point.y;
    next = n.next;
}

Snake::~Snake()
{
    // Deallocate snake
    Node* tmp;
    while(head != nullptr)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

void Snake::getLocation(std::vector<Node::Point> &v)
{
    // Get current location of all snake nodes
    Node* n = head;
    Node::Point p;
    while(n != nullptr)
    {
        p = {n->point.x, n->point.y};
        v.push_back(p);
        n = n->next;
    }
}

void Snake::move(char direction)
{
    // Create a new node that will replace current head position in a list
    // Move head to the beginning of the list with updated values
    Node* n = new Node(*head);
    head->next = n;
    switch(direction)
    {
        case 'W': head->point.y += 1; break;
        case 'S': head->point.y -= 1; break;
        case 'A': head->point.x += 1; break;
        case 'D': head->point.x -= 1; break;
    }
}

void Snake::removeLastNode()
{
    Node* current = head;
    while(current->next != tail)
    {
        current = current->next;
    }
    delete tail;
    current->next = nullptr;
    tail = current;
}

void Snake::updateFirstNode(int x, int y)
{
    head->point.x = x;
    head->point.y = y;
}
