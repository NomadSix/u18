#include <iostream>
#include <iomanip>
#include <random>
#include <stdexcept>
#include "Album.hpp"
#include "List.hpp"
#include "Rando.hpp"

bool defConstr();
bool paramConstr();
bool simpEmpty();
bool front();
bool constFront();
bool back();
bool constBack();
bool pushBack();
bool simpSize();
bool cpyConstr();
bool pushFront();
bool itBegin();
bool itEnd();
bool itRBFL();
bool citBegin();
bool citEnd();
bool citCbegin();
bool citCend();
bool citRBFL();
bool ritCbegin();
bool ritRbegin();
bool ritRend();
bool ritFL();
bool critRbegin();
bool critRend();
bool critCRbegin();
bool critCRend();
bool critFL();
bool search(bool exists);
bool cSearch(bool exists);
bool eraseGivenitem(bool exists);
bool eraseGiveniter();
bool insert();
bool emplace_back();
bool emplace_front();
bool emplace();
bool advSize();
bool advEmpty();
bool copassgnt();
bool movassgnt();

void runTests() {
    const int WIDTH = 50;
    char prev = std::cout.fill('.');

    std::cout << std::setw(WIDTH) << std::left << "Default Ctor, Dtor" << std::right << defConstr() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Parameterized Ctor, Dtor" << std::right << paramConstr() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "empty (simple)" << std::right << simpEmpty() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "simple front" << std::right << front() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "simple const front" << std::right << constFront() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "simple back" << std::right << back() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "simple const back" << std::right << constBack() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "push_back" << std::right << pushBack() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "size (simple)" << std::right << simpSize() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "Copy Constructor" << std::right << cpyConstr() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "push_front" << std::right << pushFront() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "iterator begin" << std::right << itBegin() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "iterator end" << std::right << itEnd() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "iterator range-based for loop" << std::right << itRBFL() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "const iterator begin" << std::right << citBegin() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "const iterator end" << std::right << citEnd()<< std::endl;
    std::cout << std::setw(WIDTH) << std::left << "const iterator cbegin" << std::right << citCbegin() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "const iterator cend" << std::right << citCend() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "const iterator range-based for loop" << std::right << citRBFL() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "reverse iterator begin" << std::right << ritRbegin() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "reverse iterator end" << std::right << ritRend() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "reverse iterator for loop" << std::right << ritFL() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "reverse const iterator rbegin" << std::right << critRbegin() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "reverse const iterator rend" << std::right << critRend()<< std::endl;
    std::cout << std::setw(WIDTH) << std::left << "reverse const iterator crbegin" << std::right << critCRbegin() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "reverse const iterator crend" << std::right << critCRend() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "reverse const iterator for loop" << std::right << critFL() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "search" << std::right << search(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "search (does not exist)" << std::right << search(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "constant search" << std::right << cSearch(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "constant search (does not exist)" << std::right << cSearch(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "erase (provide item)" << std::right << eraseGivenitem(true) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "erase (provide item) (does not exist)" << std::right << eraseGivenitem(false) << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "erase (provide iterator)" << std::right << eraseGiveniter() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "insert" << std::right << insert() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "emplace_back" << std::right << emplace_back() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "emplace front" << std::right << emplace_front() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "emplace" << std::right << emplace() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "size (advanced)" << std::right << advSize() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "empty (advanced)" << std::right << advEmpty() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "copy assignment" << std::right << copassgnt() << std::endl;
    std::cout << std::setw(WIDTH) << std::left << "move assignment" << std::right << movassgnt() << std::endl;

    std::cout.fill(prev);
}

bool defConstr()
{
    List<int> list;

    return 1;   // Simple Test, may look like it passes but still segfaults
}

bool paramConstr()
{
    List<double> list(3.14);

    return 1;   // Simple Test, may look like it passes but still segfaults
}

bool simpEmpty()
{
    List<double> doubList;
    List<int> intList(67);

    return doubList.empty() == true && intList.empty() == false;
}

bool front()
{
    List<int> list(1337);

    return list.front() == 1337;
}

bool constFront()
{
    const List<int> list(1337);

    return list.front() == 1337;
}

bool back()
{
    List<int> list(8956);

    return list.back() == 8956;
}

bool constBack()
{
    const List<int> list(8956);

    return list.back() == 8956;
}

bool pushBack()
{
    List<Album> list;

    Album one("I'll Be Your Girl", "The Decemberists", 2018);
    Album two("Love is Dead", "CHVRCHES", 2018);

    list.push_back(one);
    if (list.back() != one)
        return false;
    

    list.push_back(two);

    return list.back() == two;
}

bool simpSize()
{
    List<Album> list;

    Album one("Kamikaze", "Eminem", 2018);
    Album two("Awaken, My Love!", "Childish Gambino", 2016);

    list.push_back(one);
    if (list.size() != 1)
        return false;
    
    list.push_back(two);

    return list.size() == 2;
}

bool cpyConstr()
{
    List<int> one;

    one.push_back(45);
    one.push_back(24);
    one.push_back(42);

    List<int> two(one);

    return two.size() == 3 && 
           two.front() == 45 && 
           two.back() == 42;
}

bool pushFront()
{
    List<Album> list;

    Album one("I'll Be Your Girl", "The Decemberists", 2018);
    Album two("Love is Dead", "CHVRCHES", 2018);

    list.push_front(one);
    if (list.front() != one)
        return false;


    list.push_front(two);

    return list.front() == two;
}

bool itBegin()
{
    List<int> list(742);

    list.push_back(734);

    List<int>::iterator it = list.begin();

    return *it == 742;

}

bool itEnd()
{
    List<int> list(742);

    list.push_back(734);

    List<int>::iterator it = list.begin();
    ++it;
    ++it;

    return it == list.end();
}

bool itRBFL()
{
    List<int> list;

    list.push_back(576);
    list.push_back(456);
    list.push_front(1234);
    list.push_back(8);
    list.push_back(9856);

    int i = 0;
    int garbage;
    for (auto it : list) {
        ++i;
        garbage = it;
    }
    
    return i == 5 && garbage == 9856;
}

bool citBegin()
{
    List<double> one;

    one.push_front(3.14);
    one.push_front(9.81);
    one.push_back(55.6);
    one.push_back(6.23);

    const List<double> two(one);

    List<double>::const_iterator it = two.begin();

    return *it == 9.81;
}

bool citEnd()
{
    List<double> one;

    one.push_front(3.14);
    one.push_back(6.23);

    const List<double> two(one);

    List<double>::const_iterator it = two.begin();
    it++;
    it++;

    return it == two.end();
}

bool citCbegin()
{
    List<double> one;

    one.push_front(3.14);
    one.push_front(9.81);
    one.push_back(55.6);
    one.push_back(6.23);

    const List<double> two(one);

    List<double>::const_iterator it = two.cbegin();

    return *it == 9.81;
}

bool citCend()
{
    List<double> one;

    one.push_front(3.14);
    one.push_back(6.23);

    const List<double> two(one);

    List<double>::const_iterator it = two.begin();
    it++;
    it++;

    return it == two.cend();
}

bool citRBFL()
{
    List<double> one;

    one.push_front(3.14);
    one.push_front(9.81);
    one.push_back(55.6);
    one.push_back(6.23);

    const List<double> two(one);

    int i = 0;
    double garbage;
    for (auto it : two) {
        ++i;
        garbage = it;
    }

    return i == 4 && garbage == 6.23;
}

bool ritRbegin()
{
    List<int> list(742);

    list.push_back(734);

    List<int>::reverse_iterator it = list.rbegin();

    return *it == 734;
}

bool ritRend()
{
    List<int> list(742);

    list.push_back(734);

    List<int>::reverse_iterator it = list.rbegin();
    ++it;
    ++it;

    return it == list.rend();
}

bool ritFL()
{
    List<int> list;

    list.push_back(576);
    list.push_back(456);
    list.push_front(1234);
    list.push_back(8);
    list.push_back(9856);

    int i = 0;
    int garbage;
    for (List<int>::reverse_iterator rit = list.rbegin(); rit != list.rend(); ++rit) {
        i++;
        garbage = *rit;
    }
    
    return i == 5 && garbage == 1234;
}

bool critRbegin()
{
    List<double> one;

    one.push_front(3.14);
    one.push_front(9.81);
    one.push_back(55.6);
    one.push_back(6.23);

    const List<double> two(one);

    List<double>::const_reverse_iterator it = two.rbegin();

    return *it == 6.23;
}

bool critRend()
{
    List<double> one;

    one.push_front(3.14);
    one.push_back(6.23);

    const List<double> two(one);

    List<double>::const_reverse_iterator it = two.rbegin();
    it++;
    it++;

    return it == two.rend();
}

bool critCRbegin()
{
    List<double> one;

    one.push_front(3.14);
    one.push_front(9.81);
    one.push_back(55.6);
    one.push_back(6.23);

    const List<double> two(one);

    List<double>::const_reverse_iterator it = two.crbegin();

    return *it == 6.23;
}

bool critCRend()
{
    List<double> one;

    one.push_front(3.14);
    one.push_back(6.23);

    const List<double> two(one);

    List<double>::const_reverse_iterator it = two.crbegin();
    it++;
    it++;

    return it == two.crend();
}

bool critFL()
{
    List<double> one;

    one.push_front(3.14);
    one.push_front(9.81);
    one.push_back(55.6);
    one.push_back(6.23);

    const List<double> two(one);

    int i = 0;
    double garbage;
    for (List<double>::const_reverse_iterator crit = two.crbegin(); crit != two.crend(); ++crit) {
        ++i;
        garbage = *crit;
    }

    return i == 4 && garbage == 9.81;
}

bool search(bool exists)
{
    List<int> list;

    list.push_front(20);
    list.push_back(10);

    if (exists)
        list.push_back(55);
    
    try {
        auto it = list.search(55);

        return *it == 55;
    } catch (std::invalid_argument &e) {
        if (exists)
            return false;
        else
            return true;
    }
}

bool cSearch(bool exists)
{
    List<int> list;

    list.push_front(20);
    list.push_back(10);

    if (exists)
        list.push_back(55);

    const List<int> two(list);
    
    try {
        List<int>::const_iterator it = two.search(55);

        return *it == 55;
    } catch (std::invalid_argument &e) {
        if (exists)
            return false;
        else
            return true;
    }
}

bool eraseGivenitem(bool exists)
{
    List<double> list;

    list.push_front(3.14);
    list.push_front(4.67);

    if (exists)
        list.push_back(55.55);
    
    list.push_back(34.3);
    list.push_back(9.81);

    try {
        auto it = list.erase(55.55);

        return *it == 34.3;
    } catch (std::invalid_argument &e) {
        if (exists)
            return false;
        else
            return true;
    }
}

bool eraseGiveniter()
{
    List<double> list;

    list.push_front(3.14);
    list.push_front(4.67);
    list.push_back(55.55);
    list.push_back(34.3);
    list.push_back(9.81);
    List<double>::iterator it = list.begin();
    ++it;
    ++it;
 
    auto after = list.erase(it);

    return *after == 34.3;
}

bool insert()
{
    List<int> list;

    for (int i = 1; i <= 5; i++)
        list.push_back(i * 10);
    
    auto it = list.begin();
    ++it;
    it++;
    ++it;

    auto loc = list.insert(it, 8888);

    if (*loc != 8888)
        return false;
    
    return *(++loc) == 40;
}

bool emplace_back()
{
    List<Album> list;

    list.emplace_back("I'll Be Your Girl", "The Decemberists", 2018);

    if (list.back().artist() != "The Decemberists" || 
            list.back().title() != "I'll Be Your Girl" || 
            list.back().year() != 2018)
        return false;

    list.emplace_back("Love is Dead", "CHVRCHES", 2018);


    return list.back().artist() == "CHVRCHES" && 
           list.back().title() == "Love is Dead" && 
           list.back().year() == 2018;
}

bool emplace_front()
{
    List<Album> list;

    list.emplace_front("I'll Be Your Girl", "The Decemberists", 2018);
    // Album two("Love is Dead", "CHVRCHES", 2018);

    if (list.front().artist() != "The Decemberists" || 
            list.front().title() != "I'll Be Your Girl" || 
            list.front().year() != 2018)
        return false;

    list.emplace_front("Love is Dead", "CHVRCHES", 2018);

    return list.front().artist() == "CHVRCHES" && 
           list.front().title() == "Love is Dead" && 
           list.front().year() == 2018;
}

bool emplace()
{
    List<Album> list;

    list.emplace_back("Dirty Computer", "Janelle Monae", 2018);
    list.emplace_back("Primal Heart", "Kimbra", 2018);
    list.emplace_back("How Did We Get So Dark?", "Royal Blood", 2017);
    list.emplace_back("Wonderful Wonderful", "The Killers", 2017);
    list.emplace_back("A Sailor's Guide to Earth", "Sturgill Simpson", 2016);
    
    auto it = list.begin();
    ++it;
    it++;
    ++it;

    auto loc = list.emplace(it, "The Black Parade", "My Chemical Romance", 2006);

    if ((*loc).artist() != "My Chemical Romance" || 
            (*loc).title() != "The Black Parade" || 
            (*loc).year() != 2006)
        return false;
    
    ++loc;
    
    return (*loc).artist() == "The Killers" && 
           (*loc).title() == "Wonderful Wonderful" && 
           (*loc).year() == 2017; 
}

bool advSize()
{
    Rando engine;
    std::uniform_int_distribution<int> size(30, 60);
    std::uniform_int_distribution<int> takeAway(10, 20);
    std::uniform_int_distribution<int> values(1000, 9999);

    List<int> list;
    int listSize = size(engine);
    int erasures = takeAway(engine);
    std::uniform_int_distribution<int> itJump(0, 10);

    for (int i = 0; i < listSize; i++)
        list.push_back(values(engine));
    
    for (int i = 0; i < erasures; i++) {
        auto it = list.begin();
        int erasing = itJump(engine);
        for (int j = 0; j < erasing; j++) {
            ++it;
        }
        list.erase(it);
    }

    return list.size() == static_cast<unsigned int>(listSize - erasures);
}

bool advEmpty()
{
    Rando engine;
    std::uniform_int_distribution<int> elements(20, 40);
    std::uniform_int_distribution<int> values(1000, 9999);
    List<int> list;

    int listSize = elements(engine);

    for (int i = 0; i < listSize; i++)
        list.push_back(values(engine));

    if (list.empty() != false)
        return false;
    
    auto it = list.begin();
    for (int i = 0; i < listSize; i++) {
        it = list.erase(it);
    }

    return list.empty();
}

bool copassgnt()
{
    List<int> one;
    List<int> two;

    for (int i = 1; i <= 10; i++)
        one.push_front(i * 10);
    
    for (int i = 1; i <= 100; i++)
        two.push_back(i * 100);
    
    one = one;

    two = one;

    return two.size() == one.size() && 
           two.front() == 100 && 
           two.back() == 10;
}

bool movassgnt()
{
    List<int> one;
    List<int> two;

    for (int i = 1; i <= 10; i++)
        one.push_front(i * 10);
    
    for (int i = 1; i <= 100; i++)
        two.push_back(i * 100);
    
    one = std::move(one);

    two = std::move(one);

    return two.size() == 10 && 
           two.front() == 100 && 
           two.back() == 10;
}
