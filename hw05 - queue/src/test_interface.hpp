#include <iostream>
#include <iomanip>
#include <utility>
#include "Album.hpp"
#include "Queue.hpp"
#include "Rando.hpp"

bool defCtor();
bool parmCtor();
bool simpEmpty();
bool simpSize();
bool push();
bool front(bool empty);
bool back(bool empty);
bool copyCtor();
bool movCtor();
bool constFront(bool empty);
bool constBack(bool empty);
bool emplace();
bool pop(bool empty);
bool advSize();
bool advEmpty();
bool cpyAssgnt();
bool movAssgnt();

void runTests()
{
    const int WIDTH = 50;
    char prev = std::cout.fill('.');

    std::cout << std::setw(WIDTH) << std::left << "Default Ctor, Dtor" << defCtor() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Parameterized Ctor, Dtor" << parmCtor() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "empty() (simple)" << simpEmpty() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "size() (simple)" << simpSize() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "push()" << push() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "front()" << front(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "front() (on empty)" << front(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "back()" << back(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "back() (on empty)" << back(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Copy Ctor" << copyCtor() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Move Ctor" << movCtor() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "front() const" << constFront(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "front() const (on empty)" << constFront(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "back() const" << constBack(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "back() const (on empty" << constBack(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "emplace()" << emplace() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "pop()" << pop(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "pop() (on empty)" << pop(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "size() (advanced)" << advSize() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "empty() (advanced)" << advEmpty() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Copy Assignment" << cpyAssgnt() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Move Assignment" << movAssgnt() << std::endl;
    // std::cout << std::setw(WIDTH) << std::left << "" << 0 << std::endl;
    // std::cout << std::setw(WIDTH) << std::left << "" << 0 << std::endl;
    // std::cout << std::setw(WIDTH) << std::left << "" << 0 << std::endl;
    // std::cout << std::setw(WIDTH) << std::left << "" << 0 << std::endl;
    // std::cout << std::setw(WIDTH) << std::left << "" << 0 << std::endl;
    // std::cout << std::setw(WIDTH) << std::left << "" << 0 << std::endl;
    // std::cout << std::setw(WIDTH) << std::left << "" << 0 << std::endl;
    // std::cout << std::setw(WIDTH) << std::left << "" << 0 << std::endl;

    std::cout.fill(prev);
}

bool defCtor()
{
    Queue<double> q;

    return true;
}

bool parmCtor()
{
    Queue<double> q(3.14);

    return true;
}

bool simpEmpty()
{
    Queue<int> one;

    if (!one.empty())
        return false;
    
    Queue<int> two(57);

    return !two.empty();
}

bool simpSize()
{
    Queue<int> one;

    if (one.size() != 0)
        return false;
    
    Queue<int> two(57);

    return two.size() == 1;
}

bool push()
{
    Queue<int> q;
    Rando<size_t> engine;
    std::uniform_int_distribution<int> pushes(10, 30);
    std::uniform_int_distribution<int> values(1000, 9999);
    size_t numPushes = pushes(engine);

    for (size_t i = 0; i < numPushes; i++)
        q.push(values(engine));
    
    return q.size() == numPushes;
}

bool front(bool empty)
{
    Queue<int> q;

    if (empty) {
        try {
            q.front();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        q.push(55);
        if (q.front() != 55)
            return false;
        
        q.push(66);
        if (q.front() != 55)
            return false;
    }

    return true;
}

bool back(bool empty)
{
    Queue<int> q;

    if (empty) {
        try {
            q.back();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        q.push(55);
        if (q.back() != 55)
            return false;
        
        q.push(66);
        if (q.back() != 66)
            return false;
    }

    return true;
}

bool copyCtor()
{
    Queue<int> one;

    one.push(345);
    one.push(67);
    one.push(798);

    Queue<int> two(one);

    return (two.size() == 3) && 
           (two.front() == 345) && 
           (two.back() == 798);
}

bool movCtor()
{
    Queue<int> one;

    one.push(345);
    one.push(67);
    one.push(798);

    Queue<int> two(std::move(one));

    return (two.size() == 3) && 
           (two.front() == 345) && 
           (two.back() == 798);
}

bool constFront(bool empty)
{
    Queue<int> q;
    const Queue<int> r;

    if (empty) {
        try {
            r.front();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        q.push(55); 
        q.push(66);
        const Queue<int> s(q);

        return s.front() == 55;
    }

    return false;
}

bool constBack(bool empty)
{
    Queue<int> q;
    const Queue<int> r;

    if (empty) {
        try {
            r.back();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        q.push(55);
        q.push(66);
        const Queue<int> s(q);
        
        return s.back() == 66;
    }

    return false;
}

bool emplace()
{
    Queue<Album> q;

    q.emplace("Mirror Master", "Young the Giant", 2018);
    q.emplace("Kind of Blue", "Miles Davis", 1959);
    q.emplace("Body Talk", "Robyn", 2010);

    return q.size() == 3 && 
           q.front() == Album("Mirror Master", "Young the Giant", 2018) && 
           q.back() == Album("Body Talk", "Robyn", 2010);
}

bool pop(bool empty)
{
    Queue<char> q;

    if (empty) {
        try {
            q.pop();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        q.push('s');
        q.push('p');
        q.push('a');

        q.pop();
        if (q.front() != 'p')
            return false;
        
        q.pop();
        if (q.front() != 'a')
            return false;
        
        q.pop();

        return q.empty();
    }

    return false;
}

bool advSize()
{
    Rando<size_t> engine;
    std::uniform_int_distribution<int> qSize(30, 60);
    std::uniform_int_distribution<int> pops(10, 20);
    std::uniform_int_distribution<int> values(1000, 9999);
    Queue<int> q;

    int size = qSize(engine);
    int toErase = pops(engine);

    for (int i = 0; i < size; i++)
        q.push(values(engine));
    
    for (int i = 0; i < toErase; i++)
        q.pop();
    
    return q.size() == static_cast<size_t>(size - toErase);
}

bool advEmpty()
{
    Rando<size_t> engine;
    std::uniform_int_distribution<int> qSize(30, 60);
    std::uniform_int_distribution<int> values(1000, 9999);
    Queue<int> q;

    if (!q.empty())
        return false;

    int size = qSize(engine);
    for (int i = 0; i < size; i++)
        q.push(values(engine));
    if (q.empty())
        return false;
    
    for (int i = 0; i < size; i++)
        q.pop();
    
    return q.empty();
}

bool cpyAssgnt()
{
    Queue<int> one(77);
    Queue<int> two;

    one.push(66);
    one.push(55);
    one.push(44);

    two.push(78);
    two.push(67);
    two.push(56);
    two.push(45);
    two.push(34);

    one = one;

    two = one;
    
    if (two.size() != 4)
        return false;
    
    int val = 77;
    while (!two.empty()) {
        if (two.front() != val) {
            return false;
        } else {
            val -= 11;
            two.pop();
        }
    }

    return two.empty();
}

bool movAssgnt()
{
    Queue<int> one(77);
    Queue<int> two;

    one.push(66);
    one.push(55);
    one.push(44);

    two.push(78);
    two.push(67);
    two.push(56);
    two.push(45);
    two.push(34);

    one = std::move(one);

    two = std::move(one);
    
    if (two.size() != 4)
        return false;
    
    int val = 77;
    while (!two.empty()) {
        if (two.front() != val) {
            return false;
        } else {
            val -= 11;
            two.pop();
        }
    }

    return two.empty();
}
