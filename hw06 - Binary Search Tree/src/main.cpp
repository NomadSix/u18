#include "BST.hpp"
#include <iostream>
int main() {
    BST<int> tree = BST<int>(10);
    tree.insert(50);
    tree.insert(9);
    tree.insert(60);
    tree.insert(8);
    tree.insert(-10);
    // tree.erase(-10);
    auto i = tree.prbegin();
    // cout << tree.max();
    while (i != tree.prend()) {
        cout << *i << endl;
        i++;
        cin.get();
    }
    // i = tree.end();
    // cout << *i << endl;
    return 0;
}