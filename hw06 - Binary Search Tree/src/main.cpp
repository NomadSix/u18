// File Name: main.cpp
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 6

#include "test_interface.hpp"
#include <iostream>
#include "BST.hpp"
int main()
{
    runTests();
    // BST<int> t;
    // t.insert(66);
    // t.insert(44);
    // t.insert(33);
    // t.insert(55);
    // t.insert(77);
    // t.insert(68);
    // t.insert(72);
    // t.insert(70);
    // t.insert(71);
    // t.insert(88);
    // for (auto i : t)
    //     std::cout << i << ' ';
    // std::cout << '\n';

    return 0;
}
/*
 *          66
 *         /  \
 *        /    \
 *      44     77
 *     /  \   /  \
 *   33  55  68  88
 *             \
 *              72
 *             /
 *           70
 *             \
 *              71
 */
// full tree preorder : 66 44 33 55 77 68 72 70 71 88
// full tree inorder  : 33 44 55 66 68 70 71 72 77 88
// full tree postorder: 33 55 44 71 70 72 68 88 77 66

// After deleting root 66
/*
 *            68
 *           /  \
 *          /    \
 *        44      77
 *       /  \    /  \
 *     33   55  72   88
 *             /
 *           70
 *             \
 *              71
 */
// full tree preorder : 68 44 33 55 77 72 70 71 88
// full tree inorder  : 33 44 55 68 70 71 72 77 88
// full tree postorder: 33 55 44 71 70 72 88 77 68