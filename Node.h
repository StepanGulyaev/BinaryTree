
#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

enum Status 
    {
    LINK_TO_RIGHT = 0, 
    HAS_A_VALUE = 1, 
    };

class Node 
    {
    private:

        Status status; 
        Node* leftSon; 
        Node* rightBrother; 
        int value; 
        
    public:

        explicit Node();
        explicit Node(int);
        explicit Node(Node*, Node*, int);

        ~Node();

        Node* getSon() const;
        void setSon(Node* left_s = nullptr);

        Node* getBrother() const;
        void setBrother(Node* right_b = nullptr);

        const int getValue() const;
        void setValue(int newValue = 0);

        const Status getStatus() const;
    };

#endif 