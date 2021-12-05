#include "tree.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <vector>

void fill(std::vector<int> &random_numbers)
    {
    int smallest = 0;
    int biggest = 10;
    for (int i = 0; i < random_numbers.size(); i++)
        {
        int random_number = smallest + rand() % (biggest - smallest);
        random_numbers[i] = random_number;
        }
    }

int main()
    {
    size_t size = 0;
    std:: cout << "Enter size of tree A:";
    std:: cin >> size;
    std::vector<int> random_numbers(size);
    fill(random_numbers);

    Tree A;
    A.push(random_numbers);
    random_numbers.clear();
    std:: cout << "'A' tree ";
    A.reverse_print();

    std:: cout << std::endl;
    std:: cout << std::endl;
    std:: cout << std::endl;
    std:: cout << std::endl;
    std:: cout << std::endl;

    std:: cout << "Enter size of tree B:";
    std:: cin >> size;
    random_numbers.resize(size);
    fill(random_numbers);

    Tree B;
    B.push(random_numbers);
    std:: cout << "'B' tree ";
    B.symmetry_print();
    
    A.add_tree(&B);

    std:: cout << std::endl;
    std:: cout << std::endl;
    std:: cout << std::endl;
    std:: cout << std::endl;
    std:: cout << std::endl;

    std:: cout << "'A u B' tree ";
    A.reverse_print();
    }