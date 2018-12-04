#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <vector>
#include "Album.hpp"
#include "BST.hpp"

bool dctor();
bool pctor();
bool empty(bool f);
bool insert();
bool min(bool throwing);
bool max(bool throwing);
bool emplace();
bool clear();
bool prbegin();
bool prend();
bool priter();
bool begin();
bool end();
bool pobegin();
bool poend();
bool poiter();
bool cctor();
bool mtor();
bool minConst(bool throwing);
bool maxConst(bool throwing);
bool eraseLeaf();
bool eraseexc();
bool eraseSingle(bool left);
bool eraseTwo();
bool eraseRoot();
bool advPritLine(bool left);
bool advPritJagged(bool left);
bool advPoitLine(bool left);
bool advPoitJagged(bool left);

void runTests()
{
    using std::cout;
    using std::setw;
    using std::left;
    using std::endl;

    const unsigned int WIDTH = 55;

    char prev = cout.fill('.');
    std::cout << setw(WIDTH) << left << "Default Ctor, Dtor" << (dctor()) << endl;
    std::cout << setw(WIDTH) << left << "Parameterized Ctor, Dtor" << (pctor()) << endl;
    std::cout << setw(WIDTH) << left << "empty()" << (empty(true)) << endl;
    std::cout << setw(WIDTH) << left << "insert()" << (insert()) << endl;
    std::cout << setw(WIDTH) << left << "empty() (Now with insert()!)" << (empty(false)) << endl;
    std::cout << setw(WIDTH) << left << "min()" << (min(false)) << endl;
    std::cout << setw(WIDTH) << left << "min() (exception)" << (min(true)) << endl;
    std::cout << setw(WIDTH) << left << "max()" << (max(false)) << endl;
    std::cout << setw(WIDTH) << left << "max() (exception)" << (max(true)) << endl;
    std::cout << setw(WIDTH) << left << "emplace()" << (emplace()) << endl;
    std::cout << setw(WIDTH) << left << "clear()" << (clear()) << endl;
    std::cout << setw(WIDTH) << left << "prbegin()" << (prbegin()) << endl;
    std::cout << setw(WIDTH) << left << "prend()" << (prend()) << endl;
    std::cout << setw(WIDTH) << left << "preorder iteration" << (priter()) << endl;
    std::cout << setw(WIDTH) << left << "begin()" << (begin()) << endl;
    std::cout << setw(WIDTH) << left << "end()" << (end()) << endl;
    std::cout << setw(WIDTH) << left << "pobegin()" << (pobegin()) << endl;
    std::cout << setw(WIDTH) << left << "poend()" << (poend()) << endl;
    std::cout << setw(WIDTH) << left << "postorder iteration" << (poiter()) << endl;
    std::cout << setw(WIDTH) << left << "Copy Ctor" << (cctor()) << endl; //SEGMENTATION
    std::cout << setw(WIDTH) << left << "Move Ctor" << (mtor()) << endl;
    // std::cout << setw(WIDTH) << left << "min() (const)" << (minConst(false)) << endl;
    std::cout << setw(WIDTH) << left << "min() (const, exception)" << (minConst(true)) << endl;
    // std::cout << setw(WIDTH) << left << "max() (const)" << (maxConst(false)) << endl; // SEGMENTATION
    std::cout << setw(WIDTH) << left << "max() (const, exception)" << (maxConst(true)) << endl;
    std::cout << setw(WIDTH) << left << "erase() (leaf)" << (eraseLeaf()) << endl;
    std::cout << setw(WIDTH) << left << "erase() (exception)" << (eraseexc()) << endl;
    std::cout << setw(WIDTH) << left << "erase() (one child (left))" << (eraseSingle(true)) << endl;
    std::cout << setw(WIDTH) << left << "erase() (one child (right))" << (eraseSingle(false)) << endl;
    std::cout << setw(WIDTH) << left << "erase() (two children)" << (eraseTwo()) << endl;
    std::cout << setw(WIDTH) << left << "erase() (root)" << (eraseRoot()) << endl;
    std::cout << setw(WIDTH) << left << "adv. preorder iterator ('list' down left)" << (advPritLine(true)) << endl;
    std::cout << setw(WIDTH) << left << "adv. preorder iterator ('list' down right)" << (advPritLine(false)) << endl; 
    std::cout << setw(WIDTH) << left << "adv. preorder iterator (lightning going left first)" << (advPritJagged(true))     << endl;
    std::cout << setw(WIDTH) << left << "adv. preorder iterator (lightning going right first)" << (advPritJagged(false)) << endl;   
    std::cout << setw(WIDTH) << left << "adv. postorder iterator ('list' down left)" << (advPoitLine(true)) << endl;
    std::cout << setw(WIDTH) << left << "adv. postorder iterator ('list' down right)" << (advPoitLine(false)) << endl; 
    std::cout << setw(WIDTH) << left << "adv. postorder iterator (lightning going left first)" << (advPoitJagged(true))     << endl;
    std::cout << setw(WIDTH) << left << "adv. postorder iterator (lightning going right first)" << (advPoitJagged(false)) << endl;
    
    cout.fill(prev);
}

bool dctor()
{
    BST<double> t;

    return true;
}

bool pctor()
{
    BST<double> t(3.14);

    return true;
}

bool empty(bool f)
{
    BST<double> one;
    
    if (f) {
        BST<double> two(3.14);

        if (one.empty()) {
            if (!(two.empty())) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        if (one.empty()) {
            one.insert(9.81);
            return !(one.empty());
        } else {
            return false;
        }
    }
}

bool insert()
{
    BST<int> t;

    t.insert(55);
    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(50);

    return true;
}

bool min(bool throwing)
{
    BST<unsigned long> t;

    if (throwing) {
        try {
            t.min();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        t.insert(45);
        t.insert(67);
        t.insert(23);
        t.insert(98);
        t.insert(78);

        return t.min() == 23;
    }

    return false;
}

bool max(bool throwing)
{
    BST<unsigned long> t;

    if (throwing) {
        try {
            t.max();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        t.insert(45);
        t.insert(67);
        t.insert(23);
        t.insert(98);
        t.insert(78);

        return t.max() == 98;
    }

    return false;
}

bool emplace()
{
    BST<Album> t;

    t.emplace("Trench", "twenty one pilots", 2018);
    t.emplace("Honey", "Robyn", 2018);
    t.emplace("Mirror Master", "Young the Giant", 2018);
    t.emplace("For Ever", "Jungle", 2018);

    return true;
}

bool clear()
{
    BST<int> one;
    BST<int> two(23);

    two.insert(34);
    two.insert(11);
    two.insert(2);

    one.clear();
    two.clear();

    return one.empty() && two.empty();
}

bool prbegin()
{
    BST<int> t;

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(55);
    t.insert(77);
    t.insert(68);
    t.insert(72);
    t.insert(70);
    t.insert(71);
    t.insert(88);

    return *(t.prbegin()) == 66;
}

bool prend()
{
    BST<int> t;

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(71);
    t.insert(88);

    auto it = t.prbegin();
    for (int i = 0; i < 5; i++)
        it++;

    return it == t.prend();
}

bool priter()
{
    BST<int> t;
    std::vector<int> v{66, 44, 33, 55, 77, 68, 72, 70, 71, 88};

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(55);
    t.insert(77);
    t.insert(68);
    t.insert(72);
    t.insert(70);
    t.insert(71);
    t.insert(88);

    unsigned int i = 0;
    for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
        if (*it != v.at(i))
            return false;
    }

    return true;
}

bool begin()
{
    BST<int> t;

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(55);
    t.insert(77);
    t.insert(68);
    t.insert(72);
    t.insert(70);
    t.insert(71);
    t.insert(88);

    return *(t.begin()) == 33;
}

bool end()
{
    BST<int> t;

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(71);
    t.insert(88);

    auto it = t.begin();
    for (int i = 0; i < 5; i++)
        it++;

    return it == t.end();
}

bool pobegin()
{
    BST<int> t;

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(55);
    t.insert(77);
    t.insert(68);
    t.insert(72);
    t.insert(70);
    t.insert(71);
    t.insert(88);

    return *(t.pobegin()) == 33;
}

bool poend()
{
    BST<int> t;

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(71);
    t.insert(88);

    auto it = t.pobegin();
    for (int i = 0; i < 5; i++)
        it++;

    return it == t.poend();
}

bool poiter()
{
    BST<int> t;
    std::vector<int> v{33, 55, 44, 71, 70, 72, 68, 88, 77, 66};

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(55);
    t.insert(77);
    t.insert(68);
    t.insert(72);
    t.insert(70);
    t.insert(71);
    t.insert(88);

    unsigned int i = 0;
    for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
        if (*it != v.at(i))
            return false;
    }

    return true;
}

bool cctor()
{
    BST<int> s;
    std::vector<int> pr{66, 44, 33, 55, 77, 68, 72, 70, 71, 88};
    std::vector<int> in{33, 44, 55, 66, 68, 70, 71, 72, 77, 88};
    std::vector<int> po{33, 55, 44, 71, 70, 72, 68, 88, 77, 66};

    s.insert(66);
    s.insert(44);
    s.insert(33);
    s.insert(55);
    s.insert(77);
    s.insert(68);
    s.insert(72);
    s.insert(70);
    s.insert(71);
    s.insert(88);

    BST<int> t(s);

    unsigned int i = 0;
    for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
        if (*it != pr.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.begin(); it != t.end(); ++i, ++it) {
        if (*it != in.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
        if (*it != po.at(i))
            return false;
    }

    return true;
}

bool mtor()
{
    BST<int> s;
    std::vector<int> pr{66, 44, 33, 55, 77, 68, 72, 70, 71, 88};
    std::vector<int> in{33, 44, 55, 66, 68, 70, 71, 72, 77, 88};
    std::vector<int> po{33, 55, 44, 71, 70, 72, 68, 88, 77, 66};

    s.insert(66);
    s.insert(44);
    s.insert(33);
    s.insert(55);
    s.insert(77);
    s.insert(68);
    s.insert(72);
    s.insert(70);
    s.insert(71);
    s.insert(88);

    BST<int> t(std::move(s));

    unsigned int i = 0;
    for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
        if (*it != pr.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.begin(); it != t.end(); ++i, ++it) {
        if (*it != in.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
        if (*it != po.at(i))
            return false;
    }

    return true;
}

bool minConst(bool throwing)
{
    BST<unsigned long> t;

    if (!throwing) {
        t.insert(45);
        t.insert(67);
        t.insert(23);
        t.insert(98);
        t.insert(78);
    }

    const BST<unsigned long> u(t);
    if (throwing) {
        try {
            u.min();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
    cout << "hello\n";
        return u.min() == 23;
    }

    return false;
}

bool maxConst(bool throwing)
{
    BST<unsigned long> t;

    if (!throwing) {
        t.insert(45);
        t.insert(67);
        t.insert(23);
        t.insert(98);
        t.insert(78);
    }

    const BST<unsigned long> u(t);
    if (throwing) {
        try {
            u.max();
        } catch (std::underflow_error &e) {
            return true;
        } catch (...) {
            return false;
        }
    } else {
        return u.max() == 98;
    }

    return false;
}

bool eraseLeaf()
{
    BST<int> t;
    std::vector<int> pr{66, 44, 33, 77, 68, 88};
    std::vector<int> in{33, 44, 66, 68, 77, 88};
    std::vector<int> po{33, 44, 68, 88, 77, 66};

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(55);
    t.insert(77);
    t.insert(68);
    t.insert(88);

    t.erase(55);

    unsigned int i = 0;
    for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
        if (*it != pr.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.begin(); it != t.end(); ++i, ++it) {
        if (*it != in.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
        if (*it != po.at(i))
            return false;
    }

    return true;
}

bool eraseexc()
{
    BST<double> t;

    try {
        t.erase(3.14);
    } catch (std::invalid_argument &e) {
        return true;
    } catch (...) {
        return false;
    }

    return false;
}

bool eraseSingle(bool left)
{
    BST<int> t;
    std::vector<int> pr{66, 77, 68, 88};
    std::vector<int> in{66, 68, 77, 88};
    std::vector<int> po{68, 88, 77, 66};
    auto prit = pr.begin();
    auto init = in.begin();
    auto poit = po.begin();
    ++prit;

    t.insert(66);
    t.insert(44);
    t.insert(77);
    t.insert(68);
    t.insert(88);

    if (left) {
        t.insert(33);
        pr.insert(prit, 33);
        in.insert(init, 33);
        po.insert(poit, 33);
    } else {
        t.insert(55);
        pr.insert(prit, 55);
        in.insert(init, 55);
        po.insert(poit, 55);
    }
    
    t.erase(44);

    unsigned int i = 0;
    for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
        if (*it != pr.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.begin(); it != t.end(); ++i, ++it) {
        if (*it != in.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
        if (*it != po.at(i))
            return false;
    }

    return true;
}

bool eraseTwo()
{
    BST<int> t;
    std::vector<int> pr{50, 20, 5, 37, 30, 33, 40, 45, 70, 80};
    std::vector<int> in{5, 20, 30, 33, 37, 40, 45, 50, 70, 80};
    std::vector<int> po{5, 33, 30, 45, 40, 37, 20, 80, 70, 50};

    t.insert(50);
    t.insert(20);
    t.insert(5);
    t.insert(35);
    t.insert(30);
    t.insert(33);
    t.insert(40);
    t.insert(37);
    t.insert(45);
    t.insert(70);
    t.insert(80);

    t.erase(35);

    unsigned int i = 0;
    for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
        if (*it != pr.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.begin(); it != t.end(); ++i, ++it) {
        if (*it != in.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
        if (*it != po.at(i))
            return false;
    }

    return true;
}

bool eraseRoot()
{
    BST<int> t;
    std::vector<int> pr{68, 44, 33, 55, 77, 72, 70, 71, 88};
    std::vector<int> in{33, 44, 55, 68, 70, 71, 72, 77, 88};
    std::vector<int> po{33, 55, 44, 71, 70, 72, 88, 77, 68};

    t.insert(66);
    t.insert(44);
    t.insert(33);
    t.insert(55);
    t.insert(77);
    t.insert(68);
    t.insert(72);
    t.insert(70);
    t.insert(71);
    t.insert(88);

    t.erase(66);

    unsigned int i = 0;
    for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
        if (*it != pr.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.begin(); it != t.end(); ++i, ++it) {
        if (*it != in.at(i))
            return false;
    }

    i = 0;
    for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
        if (*it != po.at(i))
            return false;
    }

    return true;
}

bool advPritLine(bool left)
{
    BST<int> t;
    std::vector<int> l{25, 20, 15, 10, 5};
    std::vector<int> r{5, 10, 15, 20, 25};
    unsigned int i = 0;

    if (left) {
        t.insert(25);
        t.insert(20);
        t.insert(15);
        t.insert(10);
        t.insert(5);

        for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
            if (*it != l.at(i))
                return false;
        }
    } else {
        t.insert(5);
        t.insert(10);
        t.insert(15);
        t.insert(20);
        t.insert(25);

        for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
            if (*it != r.at(i))
                return false;
        }
    }

    return true;
}

bool advPritJagged(bool left)
{
    BST<int> t;
    std::vector<int> l{50, 10, 40, 20, 30};
    std::vector<int> r{50, 90, 60, 80, 70};
    unsigned int i = 0;

    if (left) {
        t.insert(50);
        t.insert(10);
        t.insert(40);
        t.insert(20);
        t.insert(30);

        for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
            if (*it != l.at(i))
                return false;
        }
    } else {
        t.insert(50);
        t.insert(90);
        t.insert(60);
        t.insert(80);
        t.insert(70);

        for (auto it = t.prbegin(); it != t.prend(); ++i, ++it) {
            if (*it != r.at(i))
                return false;
        }
    }

    return true;
}

bool advPoitLine(bool left)
{
    BST<int> t;
    std::vector<int> l{5, 10, 15, 20, 25};
    std::vector<int> r{25, 20, 15, 10, 5};
    unsigned int i = 0;

    if (left) {
        t.insert(25);
        t.insert(20);
        t.insert(15);
        t.insert(10);
        t.insert(5);

        for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
            if (*it != l.at(i))
                return false;
        }
    } else {
        t.insert(5);
        t.insert(10);
        t.insert(15);
        t.insert(20);
        t.insert(25);

        for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
            if (*it != r.at(i))
                return false;
        }
    }

    return true;
}

bool advPoitJagged(bool left)
{
    BST<int> t;
    std::vector<int> l{30, 20, 40, 10, 50};
    std::vector<int> r{70, 80, 60, 90, 50};
    unsigned int i = 0;

    if (left) {
        t.insert(50);
        t.insert(10);
        t.insert(40);
        t.insert(20);
        t.insert(30);

        for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
            if (*it != l.at(i))
                return false;
        }
    } else {
        t.insert(50);
        t.insert(90);
        t.insert(60);
        t.insert(80);
        t.insert(70);

        for (auto it = t.pobegin(); it != t.poend(); ++i, ++it) {
            if (*it != r.at(i))
                return false;
        }
    }

    return true;
}
