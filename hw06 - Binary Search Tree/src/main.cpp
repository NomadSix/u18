#include "BST.hpp"
#include <iostream>
int main() {
    BST<int> tree = BST<int>();
    // tree.insert(60);
    // tree.insert(70);
    // tree.insert(65);
    // tree.insert(80);

    // tree.insert(30);
    // tree.insert(20);
    // tree.insert(40);
    // tree.insert(25);
    // tree.insert(70);
    // tree.insert(60);
    // tree.insert(80);
    // tree.insert(75);
    // tree.insert(19);
    // tree.insert(100);
    // tree.insert(41);
    // tree.insert(18);

    // tree.insert();
    tree.insert(25);
    tree.insert(15);
    tree.insert(10);
    tree.insert(4);
    tree.insert(12);
    tree.insert(22);
    tree.insert(18);
    tree.insert(24);
    tree.insert(50);
    tree.insert(35);
    tree.insert(31);
    tree.insert(30);
    tree.insert(29);
    tree.insert(44);
    tree.insert(70);
    tree.insert(66);
    tree.insert(90);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    // tree.insert(999);


    tree.erase(90);
    tree.erase(70);
    auto i = tree.begin();
    // 
    // cout << tree.max();
    while (*i != 1000) {
        cout << *i << endl;
        i++;
        // cin.get();
    }
    // i++;
    // i = tree.end();
    // cout << *i << endl;
    return 0;
}