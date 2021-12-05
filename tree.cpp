
#include "tree.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Tree::Tree() 
    {
    root = nullptr;
    size = 0;
    }   

Tree::~Tree() {}

void Tree::push(int newValue) 
    {
    if (root == nullptr)
        {
        root = new Node(newValue);
        }
    else
        {
        insert(root, newValue);
        }
    }

void Tree::push(std::vector<int> newValues)
    {
    for (size_t i = 0; i < newValues.size(); i++)
        {
        push(newValues[i]);
        }
    }



void Tree::insert(Node* subroot, int newValue) 
    {
    if (subroot == nullptr) {return;}
    int subRootValue = subroot->getValue();

    if (newValue == subRootValue) {return;}
    else if (newValue < subRootValue)
        {
        if (subroot->getSon() == nullptr)
            {
            Node* left_s = new Node(newValue);
            subroot->setSon(left_s);
            return;
            }
        else 
            {
            if (subroot->getSon()->getStatus() == LINK_TO_RIGHT)
                {
                subroot->getSon()->setValue(newValue);
                return;
                }
            else 
                {
                insert(subroot->getSon(), newValue);
                }
            }
        }
    else 
        {
        if (subroot->getSon() == nullptr)
            {
            Node* left_s = new Node();
            subroot->setSon(left_s);
            }
        if (subroot->getSon()->getBrother() == nullptr)
            {
            Node* right_b = new Node(newValue);
            subroot->getSon()->setBrother(right_b);
            return;
            }
        else
            {
            insert(subroot->getSon()->getBrother(),newValue);
            }
        }
    }



void Tree::reverse_print() const
    {
    int wight = 50;
    cout << "reverse_print" << ": " << endl;
    reverse_print(root, wight);
    }

void Tree::symmetry_print() const
    {
    int wight = 50;
    cout << "symmetry_print" << ": " << endl;
    symmetry_print(root, wight);
    }



void Tree::symmetry_print(Node* subroot, int width) const
    {
    string value = subroot->getStatus() == LINK_TO_RIGHT ? " " : to_string(subroot->getValue());
    if (subroot->getSon() != nullptr)
        {
        symmetry_print(subroot->getSon(),width - 3);
        }

    if (subroot->getStatus() == HAS_A_VALUE)
        {
        cout << setw(width) << value << endl;
        }

    if (subroot->getBrother() != nullptr)
        {
        symmetry_print(subroot->getBrother(),width + 12);
        }
    }

void Tree::reverse_print(Node* subroot, int width) const
    {
    string value = subroot->getStatus() == LINK_TO_RIGHT ? " " : to_string(subroot->getValue());

    if (subroot->getSon() != nullptr)
        {
        reverse_print(subroot->getSon(),width - 4);
        }

    if (subroot->getBrother() != nullptr)
        {
        reverse_print(subroot->getBrother(),width + 12);
        }

    if (subroot->getStatus() == HAS_A_VALUE)
        {
        cout << setw(width) << value << endl;
        }
    }
    

bool Tree::find(Node* subroot, int value_s) const 
    {

    int subRootValue;
    if (subroot == nullptr)
        {
        return false;
        }

    if (subroot->getStatus() == HAS_A_VALUE)
        {
        subRootValue = subroot->getValue();
        }
    else {return false;}

    if (value_s == subRootValue) 
        {
        return true;
        }

    else if (value_s < subRootValue) 
        {
        return find(subroot->getSon(), value_s);
        } 
    else 
        {
        if (subroot->getSon() != nullptr)
            {
            return find(subroot->getSon()->getBrother(), value_s);
            }
        }
    return false;
    }


bool Tree::find(Tree* subtree, int value_s) const 
    {
    Node* subroot = subtree->root;
    return find(subroot, value_s);
    }

void Tree::add_tree(Tree* subtree)
    {
    Node* subroot = subtree->root;
    add_tree(subroot);
    }

void Tree::add_tree(Node* subroot)
    {
    if (subroot->getStatus() == HAS_A_VALUE)
        {
        if (find(this, subroot->getValue()) == false )
            {
            push(subroot->getValue());
            }
        }
    if (subroot->getSon() != nullptr)
        {
        add_tree(subroot->getSon());
        }
    if (subroot->getBrother() != nullptr)
        {
        add_tree(subroot->getBrother());
        }
    }