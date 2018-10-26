#ifndef STACK_CLASS_HPP
#define STACK_CLASS_HPP

// Necessary includes
#include "List.hpp"

template <typename T>
class Stack {
public:
    // default constructor
    Stack();
    // parameterized constructor that takes first item
    Stack(const T& item);
    // copy constructor
    Stack(const Stack &copy);
    // move constructor
    Stack(Stack &&move);
    // destructor
    ~Stack();

    // function empty; does not throw exceptions
    bool empty() const noexcept;

    // function size; does not throw exceptions
    unsigned int size() const noexcept;

    // function top; l-value; throws underflow if stack is empty
    T& top();

    // function top; read-only; throws underflow if stack is empty
    const T& top() const;

    // function push; does not throw exceptions
    void push(const T& val) noexcept;

    // function emplace; does not throw exceptions
    template <class... Args>
    void emplace(Args&&... args) noexcept;

    // function pop; throws underflow if stack is empty
    void pop();

    // copy assignment operator overload
    const Stack&operator =(Stack&);

    // move assignment operator overload
    Stack&operator =(Stack&&);
private:
    // Private data
    List<T> array;
};



// STACK FUNCTIONS



#endif