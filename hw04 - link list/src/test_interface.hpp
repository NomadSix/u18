#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include "Album.hpp"
#include "Stack.hpp"

bool defCtor();
bool parmCtor();
bool simpEmpty();
bool push();
bool simpSize();
bool top(bool empty);
bool pop(bool empty);
bool copyCtor();
bool movCtor();
bool constTop(bool empty);
bool emplace();
bool advSize();
bool advEmpty();
bool copyAssgnt(bool empty);
bool moveAssgnt(bool empty);

void runTests()
{
    const int WIDTH = 50;
    char prev = std::cout.fill('.');

    std::cout << std::setw(WIDTH) << std::left << "Default Ctor, Destructor" << defCtor() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Parameterized Ctor, Destructor" << parmCtor() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "empty() (simple)" << simpEmpty() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "push()" << push() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "size() (simple)" << simpSize() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "top()" << top(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "top() (on empty)" << top(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "pop(), empty()" << pop(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "pop(), (on empty)" << pop(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Copy Ctor" << copyCtor() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Move Ctor" << movCtor() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "top() const" << constTop(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "top() const (on empty)" << constTop(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "emplace()" << emplace() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "size() (advanced)" << advSize() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "empty() (advanced)" << advEmpty() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Copy Assignment" << copyAssgnt(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Copy Assignment (empty)" << copyAssgnt(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Move Assignenment" << moveAssgnt(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Move Assignenment (empty)" << moveAssgnt(true) << std::endl;

    std::cout.fill(prev);
}

bool defCtor()
{
    Stack<double> s;

    return true;
}

bool parmCtor()
{
    Stack<double> s(3.14);

    return true;
}

bool simpEmpty()
{
    Stack<int> one(56);

    if (one.empty())
        return false;
    
    Stack<double> s;

    return s.empty();
}

bool push()
{
    Stack<char> s;

    s.push('!');
    s.push('i');
    s.push('h');

    return true;
}

bool simpSize()
{
    Stack<char> s;

    if (s.size() != 0)
        return false;

    s.push('o');
    if (s.size() != 1)
        return false;
    
    s.push('y');

    return s.size() == 2;
}

bool top(bool empty)
{
    Stack<int> s;

    if (empty) {
        try {
            s.top();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        s.push('!');
        if (s.top() != '!')
            return false;
        
        s.push('i');
        if (s.top() != 'i')
            return false;

        s.push('h');
        return s.top() == 'h';
    }

    return false;
}

bool pop(bool empty)
{
    Stack<int> s;

    if (empty) {
        try {
            s.pop();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        s.push(33);
        s.push(44);
        s.push(55);
        s.push(66);
        s.push(77);

        for (int i = 77; i > 30; i -= 11) {
            if (s.top() != i) {
                return false;
            }
            s.pop();
        }

        return s.empty();
    }

    return false;
}

bool copyCtor()
{
    Stack<int> one;

    one.push(22);
    one.push(33);
    one.push(44);
    one.push(55);

    Stack<int> two(one);

    for (int i = 55; i > 20; i -= 11)
    {
        if (two.top() != i)
            return false;
        
        two.pop();
    }

    return true;
}

bool movCtor()
{
    Stack<int> one;

    one.push(22);
    one.push(33);
    one.push(44);
    one.push(55);

    Stack<int> two(std::move(one));

    for (int i = 55; i > 20; i -= 11)
    {
        if (two.top() != i)
            return false;
        
        two.pop();
    }

    return true;
}

bool constTop(bool empty)
{
    Stack<int> one;

    if (!empty) {
        one.push(22);
        one.push(33);
        one.push(44);
        one.push(55);
    }

    const Stack<int> two(one);

    int topValue;
    try {
        topValue = two.top();
    } catch (std::underflow_error &e) {
        if (empty)
            return true;
        else
            return false;
    } catch (...) {
        return false;
    }
    
    return topValue == 55;
}

bool emplace()
{
    Stack<Album> s;

    s.emplace("Trench", "twenty one pilots", 2018);
    if (s.top() != Album("Trench", "twenty one pilots", 2018))
        return false;

    s.emplace("DAMN", "Kendrick Lamar", 2017);
    if (s.top() != Album("DAMN", "Kendrick Lamar", 2017))
        return false;
    
    s.emplace("Masseduction", "St. Vincent", 2017);
    if (s.top() != Album("Masseduction", "St. Vincent", 2017))
        return false;
    
    return true;
}

bool advSize()
{
    Rando<unsigned long> engine;
    std::uniform_int_distribution<int> size(30, 60);
    std::uniform_int_distribution<int> erase(10, 20);
    std::uniform_int_distribution<int> values(1000, 9999);

    unsigned int stackSize = size(engine);
    unsigned int pops = erase(engine);

    Stack<int> s;

    // Fill Stack
    for (unsigned int i = 0; i < stackSize; i++)
        s.push(values(engine));
    
    if (s.size() != stackSize)
        return false;
    
    for (unsigned int i = 0; i < pops; i++)
        s.pop();
    
    return s.size() == (stackSize - pops);
}

bool advEmpty()
{
    Rando<unsigned int> engine;
    std::uniform_int_distribution<int> size(30, 60);
    std::uniform_int_distribution<int> values(1000, 9999);

    unsigned int stackSize = size(engine);

    Stack<int> s;

    if (!s.empty())
        return false;

    // Fill Stack
    for (unsigned int i = 0; i < stackSize; i++)
        s.push(values(engine));
    
    if (s.empty())
        return false;
    
    for (unsigned int i = 0; i < stackSize; i++)
        s.pop();
    
    return s.empty();
}


bool copyAssgnt(bool empty)
{
    Stack<int> one;
    Stack<int> two;

    if (!empty) {
        one.push(34);
        one.push(45);
        one.push(56);
    }

    one = one;

    two = one;

    if (!empty) {
        for (int i = 56; i > 30; i -= 11) {
            if (two.top() != i)
                return false;
            
            two.pop();
        }
    }
    
    return two.size() == 0;
}

bool moveAssgnt(bool empty)
{
    Stack<int> one;
    Stack<int> two;

    if (!empty) {
        one.push(34);
        one.push(45);
        one.push(56);
    }

    one = std::move(one);

    two = std::move(one);

    if (!empty) {
        for (int i = 56; i > 30; i -= 11) {
            if (two.top() != i)
                return false;
            
            two.pop();
        }
    }
    
    return two.size() == 0;
}
