
#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include "Node.h"
#include <vector>

class Tree 
    {

    private:

        size_t size;
        Node* root;
        bool find(Node*, int) const;
        void insert(Node*, int);
        void reverse_print(Node*, int) const;
        void symmetry_print(Node*,int) const;

    public:

        explicit Tree();
        ~Tree();

        bool find(Tree*, int) const;
        void push(int);
        void push(const std::vector<int> newValues);

        void reverse_print() const;
        void symmetry_print() const;

        void add_tree(Tree*);
        void add_tree(Node*);
    };


#endif //BINARYTREE_TREE_H