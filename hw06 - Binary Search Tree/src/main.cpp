#include "BST.hpp"
#include <iostream>
int main() {
    BST<int> tree = BST<int>(5);
    std::cout << tree.min();
    // std::cout << "Hello";
    return 0;
}