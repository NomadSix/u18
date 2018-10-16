#ifndef DOUBLE_LINK_LIST_HPP
#define DOUBLE_LINK_LISH_HPP

// Necessary includes
#include <stdexcept>
using namespace std;

// CLASS DECLARATIONS
template <typename T>
class List
{
public:
    // Default constructor
    List();
    // Constructor that takes first item
    List(const T& copy);
    // Copy constructor
    List(const List&);
    // Move constructor
    List(List&&);
    // Destructor
    ~List();

    // function front; l-value
    T& front();
    // function front; return by value
    T& front() const;
    // function back; l-value
    T& back();
    // function back; return by value
    T& back() const;

    class iterator;
    class reverse_iterator;
    class const_iterator;
    class const_reverse_iterator;
    // function begin
    iterator begin();
    // function begn; const_iterator overload
    const_iterator begin() const;
    // function end
    iterator end();
    // function end; const_iterator overload
    const_iterator end() const;
    // function rbegin
    reverse_iterator rbegin();
    // function rbegin; const_reverse_iterator overload
    const_reverse_iterator rbegin() const;
    // function rend
    reverse_iterator rend();
    // function rend; const_reverse_iterator overload
    const_reverse_iterator rend() const;
    // function cbegin
    const_iterator cbegin() const;
    // function cend
    const_iterator cend() const ;
    // function crbegin
    const_reverse_iterator crbegin() const;
    // function crend
    const_reverse_iterator crend() const;

    // function search; returns iterator
    // throws std::invalid_argument
    iterator search(T);  //TODO arguments

    // function search; returns const_iterator
    // throws std::invalid_argument
    const_iterator search(T) const;    //TODO arguments

    // function erase; returns iterator to one after what was erased
    // throws std::invalid_argument
    iterator erase(T);   //TODO arguments

    // function erase; overload that takes an iterator to what should be erased
    // throws std::invalid_argument
    const_iterator erase(iterator) const;   //TODO arguments

    // function insert; takes an iterator to position
    // where insertion occurs as well as item to insert,
    // returns iterator to inserted item
    iterator insert(iterator loc, T item);

    // function push_back;
    void push_back(T item);

    // function push_front;
    void push_front(T item);

    // function emplace; takes an iterator to position where
    // insertion occurs as well as item constructor parameters,
    // returns iterator to inserted item
    template <typename... Args>
    iterator emplace(iterator pos, Args&&...);
    // function emplace_back; takes item constructor parameters
    template <typename... Args>
    void emplace_blask(Args&&...);
    // function emplace_front; takes item constructor parameters
    template <typename... Args>
    void emplace_front(Args&&...);

    // function size();
    int size();
    // function empty();
    void empty();
    // function copy assignment overload;
    const List& operator =(List<T>&);
    // function move assignment overload;
    List& operator =(List<T>&&);
private:
    class Node;
    Node *_head;
    Node *_last;
    Node *searchHelper(iterator loc) const;
    // Whatever data or helper functions you deem necessary
};

template <typename T>
class List<T>::Node {
public:
    Node(T item);
    Node* next();
    Node* prev();
    void setNext(Node *node);
    T& key();
private:
    T *_res;
    Node *_next;
    Node *_prev;
};

template <typename T>
class List<T>::iterator {
public:
    // Only need one constructor
    iterator(Node*);
    // function prefix increment operator overload
    iterator operator++();
    // function postfix increment operator overload
    const iterator operator++(int);
    // function prefix decrement operator overload
    iterator operator--();
    // function postfix decrement operator overload
    const iterator operator--(int);
    // function de-reference operator overlaod; l-value
    T& operator*();
    // function equivalency operator overload
    friend bool operator==(const typename List<T>::iterator &lhs, const typename List<T>::iterator &rhs)
    {
        return lhs._res == rhs._res;
    }
    // function inequivalency operator overload
    friend bool operator!=(const typename List<T>::iterator &lhs, const typename List<T>::iterator &rhs)
    {
        return !(lhs == rhs);
    }
private:
    // Resource that iterator manages
    List<T>::Node *_res;
};

template <typename T>
class List<T>::reverse_iterator {
public:
    // Only need one constructor
    reverse_iterator(Node *node);
    // function prefix increment operator overload
    reverse_iterator operator++();
    // function postfix increment operator overload
    const reverse_iterator operator++(int);
    // function prefix decrement operator overload
    reverse_iterator operator--();
    // function postfix decrement operator overload
    const reverse_iterator operator--(int);
    // function de-reference operator overlaod; l-value
    T& operator*();
    // function equivalency operator overload
    friend bool operator==(const typename List<T>::reverse_iterator &lhs, const typename List<T>::reverse_iterator &rhs)
    {
        return lhs._res == rhs._res;
    }
    // function inequivalency operator overload
    friend bool operator!=(const typename List<T>::reverse_iterator &lhs, const typename List<T>::reverse_iterator &rhs)
    {
        return lhs._res != rhs._res;
    }
private:
    // Resource that iterator manages
    List<T>::Node *_res;
};

template <typename T> 
class List<T>::const_iterator 
{
public:
    // Only need one constructor
    const_iterator(Node *node);
    // function prefix increment operator overload
    const_iterator operator++();
    // function postfix increment operator overload
    const const_iterator operator++(int);
    // function prefix decrement operator overload
    const_iterator operator--();
    // function postfix decrement operator overload
    const const_iterator operator--(int);
    // function de-reference operator overlaod; l-value
    T& operator*();
    // function equivalency operator overload
    friend bool operator==(const typename List<T>::const_iterator &lhs, const typename List<T>::const_iterator &rhs)
    {
        return lhs._res == rhs._res;
    }
    // function inequivalency operator overload
    friend bool operator!=(const typename List<T>::const_iterator &lhs, const typename List<T>::const_iterator &rhs)
    {
        return lhs._res != rhs._res;
    }
private:
    // Resource that iterator manages
    Node *_res;
};



template <typename T>
class List<T>::const_reverse_iterator {
public:
    // Only need one constructor
    const_reverse_iterator(Node *node);
    // function prefix increment operator overload
    const_reverse_iterator operator++();
    // function postfix increment operator overload
    const const_reverse_iterator operator++(int);
    // function prefix decrement operator overload
    const_reverse_iterator operator--();
    // function postfix decrement operator overload
    const const_reverse_iterator operator--(int);
    // function de-reference operator overlaod; l-value
    T& operator*();
    // function equivalency operator overload
    friend bool operator==(const typename List<T>::const_reverse_iterator &lhs, const typename List<T>::const_reverse_iterator &rhs)
    {
        return lhs._res == rhs._res;
    }
    // function inequivalency operator overload
    friend bool operator!=(const typename List<T>::const_reverse_iterator &lhs, const typename List<T>::const_reverse_iterator &rhs)
    {
        return lhs._res != rhs._res;
    }
private:
    // Resource that iterator manages
    Node *_res;
};


// CLASS IMPLEMENTATIONS BELOW
#include "List.I"

#endif