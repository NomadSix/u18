// File Name: BST.hpp
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 6

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <stdexcept>
#include "Queue.hpp"
using namespace std;

template <typename T>
class BST {
public:
    // Default Ctor
    BST();
    // Parameterized Ctor
    BST(const T& item);
    // Copy Ctor
    BST(BST& copy);
    // Move Ctor
    BST(BST&& move);
    // Dtor
    ~BST();

    class preorder_iterator;
    class inorder_iterator;
    class postorder_iterator;
    // function prbegin; pr = preorder
    preorder_iterator prbegin();
    // function prend
    preorder_iterator prend();
    inorder_iterator begin();
    inorder_iterator begin() const;
    inorder_iterator end();
    // inorder_iterator end() const;
    // function pobegin; po = postorder
    postorder_iterator pobegin();
    // function poend
    postorder_iterator poend();

    // function empty; does not throw exceptions
    bool empty() const noexcept;
    // function min; l-value, throws underflow if empty
    T& min();
    // function min; read-only, throws underflow if empty
    T& min() const;
    // function max; l-value, throws underflow if empty
    T& max();
    // function max; read-only, throws underflow if empty
    T& max() const;

    // function insert; does not throw exceptions
    void insert(T val) noexcept;
    // function emplace; does not throw exceptions
    template <typename... Args>
    void emplace(Args&&... args) noexcept;
    // function erase; takes a type T, throws invalid_argument if empty or cannot be found
    void erase(T key);    

    // function clear; does not throw exceptions
    void clear() noexcept;

    // copy assignment operator overload
    const BST& operator =(BST<T>&);
    // move assignment operator overload
    BST& operator =(BST<T>&&);
private:
    class Node;
    Node* root;
    Queue<T> _queue;
    // Private data and helper functions go here
    Node* rinsert(Node *node, T key) noexcept;
    void eraseHelper(Node *node, T key);
    void walk(Node* node);
    void prwalk(Node* node);
    void powalk(Node* node);
    void copyTree(Node* curr, Node* sub);
    void transplant(Node* curr, Node* sub);
    void clearTree(Node* node);
    Node* search(Node* node, T key);
};

// NODE CLASS
template <typename T>
class BST<T>::Node {
public:
    // Public Node Functions
    Node(T val);
    Node* left();
    Node* right();
    Node* parent();
    void setLeft(Node *node);
    void setRight(Node *node);
    void setParent(Node *node);
    T& key();
private:
    // Private data and helper functions for BST<T>::Node
    T _val;
    Node* _left;
    Node* _right;
    Node* _parent;
};

// INORDER_ITERATOR CLASS
template <typename T>
class BST<T>::inorder_iterator {
public:
    inorder_iterator(Queue<T>);
    T& operator*();
    inorder_iterator& operator++();
    inorder_iterator operator++(int);
    friend bool operator==(const typename BST<T>::inorder_iterator &lhs,  const typename BST<T>::inorder_iterator &rhs)
    {
        return lhs._queue.front() == rhs._queue.front();
    }
    friend bool operator!=(const typename BST<T>::inorder_iterator &lhs,  const typename BST<T>::inorder_iterator &rhs)
    {
        return !(lhs == rhs);
    }
private:
    Queue<T> _queue;
};

// POSTORDER_ITERATOR CLASS
template <typename T>
class BST<T>::postorder_iterator {
public:
    postorder_iterator(Queue<T>);
    T& operator*();
    postorder_iterator& operator++();
    postorder_iterator operator++(int);
    friend bool operator==(const typename BST<T>::postorder_iterator &lhs,  const typename BST<T>::postorder_iterator &rhs)
    {
        return lhs._queue.front() == rhs._queue.front();
    }
    friend bool operator!=(const typename BST<T>::postorder_iterator &lhs,  const typename BST<T>::postorder_iterator &rhs)
    {
        return !(lhs == rhs);
    }
private:
    Queue<T> _queue;
};

// PREORDER_ITERATOR CLASS
template <typename T>
class BST<T>::preorder_iterator {
public:
    preorder_iterator(Queue<T>);
    T& operator*();
    preorder_iterator& operator++();
    preorder_iterator operator++(int);
    friend bool operator==(const typename BST<T>::preorder_iterator &lhs,  const typename BST<T>::preorder_iterator &rhs)
    {
        return lhs._queue.front() == rhs._queue.front();
    }
    friend bool operator!=(const typename BST<T>::preorder_iterator &lhs,  const typename BST<T>::preorder_iterator &rhs)
    {
        return !(lhs == rhs);
    }
private:
    Queue<T> _queue;
};



// BST FINCTOPMS
#include "BST.i"


// NODE FUNCTIONS
#include "Node.i"


// PREORDER_ITERATOR FUNCTIONS
#include "preorder_iterator.i"


// INORDER_ITERATOR FUNCTIONS
#include "inorder_iterator.i"


// POSTORDER_ITERATOR FUNCTIONS
#include "postorder_iterator.i"

#endif