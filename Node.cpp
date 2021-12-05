#include "Node.h"
#include "stdexcept"


Node::Node() 
    {
    leftSon = nullptr;
    rightBrother = nullptr;
    value = 0;
    status = LINK_TO_RIGHT;

    }

Node::Node(int newValue) 
    {
    leftSon = nullptr;
    rightBrother = nullptr;
    value = newValue;
    status = HAS_A_VALUE;
    }

Node::Node(Node *left_s, Node *right_b, const int newValue) 
    {
    leftSon = left_s;
    rightBrother = right_b;
    value = newValue;
    status = HAS_A_VALUE;
    }

Node::~Node() 
    {
    // Just destructor
    }

Node* Node::getSon() const 
    {
    return leftSon;
    }

void Node::setSon(Node* left_s) 
    {
    leftSon = left_s;
    }

Node* Node::getBrother() const 
    {
    return rightBrother;
    }

void Node::setBrother(Node* right_b) 
    {
    rightBrother = right_b;
    }

const int Node::getValue() const 
    {
    if (status == LINK_TO_RIGHT)
        throw std::runtime_error("Попытка получения значения вершины, у которой статус является ссылочным!");
    return value;
    }   

void Node::setValue(const int newValue) 
    {
    status = HAS_A_VALUE;
    value = newValue;
    }

const Status Node::getStatus() const 
    {
    return status;
    }



