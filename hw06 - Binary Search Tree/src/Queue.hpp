#ifndef QUEUE__HPP
#define QUEUE__HPP
#include <iostream>
#include <utility>
#include "List.hpp"

template <typename T>
class Queue {
public:
    // Default Constructor
    Queue();
    // Parameterized Constructor
    Queue(T val);
    // Copy Constructor
    Queue(Queue &copy);
    // Move Constructor
    Queue(Queue &&move);
    // Destructor
    ~Queue();
    // function empty, does not throw exceptions
    bool empty() const noexcept;
    // function size, does not throw exceptions
    int size() const noexcept;
    // function front, l-value, throws underflow
    T& front();
    // function front, read-only, throws underflow
    const T& front() const;
    // function back, l-value, throws underflow
    T& back();
    // function back, read-only, throws underflow
    const T& back() const;
    // function push, does not throw exceptions
    void push(const T& val);
    // function emplace, does not throw exceptions
    template <class... Args>
    void emplace(Args... args);
    // function pop, throws underflow
    void pop();
    // Copy assignment operator overload
    const Queue&operator =(Queue& copy);
    // Move assignment operator overload
    Queue&operator =(Queue&& move);
private:
    // Private data / underlying container
    List<T> list;
};

// QUEUE IMPLEMENTATION
#include "Queue.i"

#endif