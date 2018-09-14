#include <iostream>
#include <iomanip>
#include <utility>
#include "List.hpp"
#include "Book.hpp"
#include "Novel.hpp"
#include "GraphicNovel.hpp"

const int WIDTH = 55;

bool defConstr();
bool paramConstr();
bool copConstr();
bool movConstr();
bool copAss();
bool movAss();
bool size();
bool capacity();
bool insempt();
bool ins();
bool inssort();
bool search(bool flag);
bool ersempt();
bool ers(bool flag);
bool cat();
bool sort();

void runTests()
{
    char fill = std::cout.fill('.');

    std::cout << std::left << std::setw(WIDTH) << "Default Constructor, size, capacity, Destructor" << defConstr() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Parameterized Constructor, at, Destructor" << paramConstr() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Copy Constructor, insert" << copConstr() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Move Constructor, Destructor" << movConstr() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Copy Assignment" << copAss() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Move Assignment" << movAss() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "size" << size() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "capacity" << capacity() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "insert (on empty)" << insempt() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "insert" << ins() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "insert (basic sorting)" << inssort() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "search (exists)" << search(true) << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "search (does not exist)" << search(false) << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "erase (on empty)" << ersempt() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "erase (exists)" << ers(true) << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "erase (does not exist)" << ers(false) << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "const at" << cat() << std::endl;
    std::cout << std::left << std::setw(WIDTH) << "Sorting" << sort() << std::endl;
    
    std::cout.fill(fill);
}

bool defConstr()
{
    List<Book*> list;

    return list.size() == 0 && 
           list.capacity() == 0;
}

bool paramConstr()
{
    List<Book*> list(new Novel("Lee", "Harper", "Go Set a Watchman", 2015));

    return list.size() == 1 && 
           list.capacity() == 1 && 
           list.at(0)->author() == "Harper Lee" && 
           list.at(0)->title() == "Go Set a Watchman" &&
           list.at(0)->year() == 2015;
}

bool copConstr()
{
    List<Book*> one(new Novel("Punke", "Michael", "The Revenant: A Novel of Revenge", 2001));
    one.insert(new Novel("Card", "Orson Scott", "Ender's Game", 1985));
    one.insert(new GraphicNovel("Miller", "Frank", "Klaus Janson", "The Dark Knight Returns", 1986));
    List<Book*> two = one;

    return two.size() == 3 && 
           two.capacity() == 3 && 
           two.at(0)->author() == "Orson Scott Card" && 
           two.at(1)->author() == "Frank Miller" && 
           two.at(2)->author() == "Michael Punke" &&
           one.at(0)->author() == "Orson Scott Card" && 
           one.at(1)->author() == "Frank Miller" && 
           one.at(2)->author() == "Michael Punke";
}

bool movConstr()
{
    List<Book*> one(new Novel("Punke", "Michael", "The Revenant: A Novel of Revenge", 2001));
    one.insert(new Novel("Card", "Orson Scott", "Ender's Game", 1985));
    one.insert(new GraphicNovel("Miller", "Frank", "Klaus Janson", "The Dark Knight Returns", 1986));
    List<Book*> two = std::move(one);

    return two.size() == 3 && 
           two.capacity() == 4 && 
           two.at(0)->author() == "Orson Scott Card" && 
           two.at(1)->author() == "Frank Miller" && 
           two.at(2)->author() == "Michael Punke";
}

bool copAss()
{
    List<Book*> one(new Novel("Jacques", "Brian", "Redwall", 1986));
    List<Book*> two(new Novel("Endore", "Guy", "The Werewolf of Paris: A Novel", 1933));

    one = one;
    one = two;

    return one.at(0)->author() == "Guy Endore" && 
           one.at(0)->title() == "The Werewolf of Paris: A Novel" && 
           one.at(0)->year() == 1933 &&
           two.at(0)->author() == "Guy Endore" && 
           two.at(0)->title() == "The Werewolf of Paris: A Novel" && 
           two.at(0)->year() == 1933;
}

bool movAss()
{
    List<Book*> one(new Novel("Jacques", "Brian", "Redwall", 1986));
    List<Book*> two(new Novel("Endore", "Guy", "The Werewolf of Paris: A Novel", 1933));

    one = std::move(one);
    one = std::move(two);

    return one.at(0)->author() == "Guy Endore" && 
           one.at(0)->title() == "The Werewolf of Paris: A Novel" && 
           one.at(0)->year() == 1933;
}

bool size()
{
    List<Book*> list;

    if (list.size() == 0) {
        list.insert(new GraphicNovel("Loeb", "Jeph", "Tim Sale", "The Long Halloween", 1996));
        if (list.size() == 1) {
            list.insert(new Novel("Follett", "Ken", "The Pillars of the Earth", 1989));
            if (list.size() == 2) {
                list.insert(new Novel("Doyle", "Sir Arthur Conan", "The Hound of the Baskervilles", 1902));
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }

    return list.size() == 3;
}

bool capacity()
{
    List<Book*> list;

    if (list.capacity() == 0) {
        list.insert(new GraphicNovel("Loeb", "Jeph", "Tim Sale", "The Long Halloween", 1996));
        if (list.capacity() == 1) {
            list.insert(new Novel("Follett", "Ken", "The Pillars of the Earth", 1989));
            if (list.capacity() == 2) {
                list.insert(new Novel("Doyle", "Sir Arthur Conan", "The Hound of the Baskervilles", 1902));
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }

    return list.capacity() == 4;
}

bool insempt()
{
    List<int*> list;
    list.insert(new int(509));

    return list.size() == 1 &&
           list.capacity() == 1 && 
           *(list.at(0)) == 509;
}

bool ins()
{
    List<Book*> list(new GraphicNovel("Moore", "Alan", "Brian Bolland", "Batman: The Killing Joke", 1988));

    list.insert(new GraphicNovel("Waid", "Mark", "Alex Ross", "Kingdom Come", 1996));
    
    return list.size() == 2 && 
           list.capacity() == 2 && 
           list.at(0)->author() == "Alan Moore" && 
           list.at(0)->title() == "Batman: The Killing Joke" && 
           list.at(0)->year() == 1988 && 
           list.at(1)->author() == "Mark Waid" && 
           list.at(1)->title() == "Kingdom Come" && 
           list.at(1)->year() == 1996;
}

bool inssort()
{
    List<Book*> list(new GraphicNovel("Waid", "Mark", "Alex Ross", "Kingdom Come", 1996));

    list.insert(new GraphicNovel("Moore", "Alan", "Brian Bolland", "Batman: The Killing Joke", 1988));
    list.insert(new Novel("Moore", "Alan", "Jerusalem", 2016));
    
    return list.size() == 3 && 
           list.capacity() == 4 && 
           list.at(0)->author() == "Alan Moore" && 
           list.at(0)->title() == "Batman: The Killing Joke" && 
           list.at(0)->year() == 1988 && 
           list.at(1)->author() == "Alan Moore" && 
           list.at(1)->title() == "Jerusalem" && 
           list.at(1)->year() == 2016 && 
           list.at(2)->author() == "Mark Waid" && 
           list.at(2)->title() == "Kingdom Come" && 
           list.at(2)->year() == 1996;
}

bool search(bool flag)
{
    List<Book*> list(new Novel("Hart", "Carolyn", "Ghost Times Two", 2016));
    Novel diary("Palahniuk", "Chuck", "Diary", 2003);
    if (flag) {
        list.insert(&diary);
    }
    int loc;
    try {
        loc = list.search(&diary);

        return loc == 1;
    } catch(std::domain_error &e) {
        if (!flag) {
            return true;
        } else {
            return false;
        }
    } catch(...) {
        return false;
    }
}

bool ersempt()
{
    List<Book*> list;
    Novel book("Follett", "Ken", "The Pillars of the Earth", 1989);

    try {
        list.erase(&book);
    } catch(std::underflow_error &e) {
        return true;
    } catch(std::range_error &e) {
        return false;
    } catch(...) {
        return false;
    }

    return false;
}

bool ers(bool flag)
{
    List<Book*> list(new Novel("Hart", "Carolyn", "Ghost Times Two", 2016));
    list.insert(new Novel("Palahniuk", "Chuck", "Diary", 2003));

    GraphicNovel metal("Snyder", "Scott", "Greg Capullo", "Dark Nights: Metal", 2017);
    if (flag) {
        list.insert(&metal);
    }

    try {
        list.erase(&metal);

        return list.size() == 2 && 
               list.capacity() == 4;
    } catch(std::range_error &e) {
        if (!flag) {
            return true;
        } else {
            return false;
        }
    } catch(std::domain_error &e) {
        return false;
    } catch(...) {
        return false;
    }
}

bool cat()
{
    const List<Book*> list(new Novel("Palahniuk", "Chuck", "Fight Club", 1996));
    
    return list.at(0)->author() == "Chuck Palahniuk" && 
           list.at(0)->title() == "Fight Club" && 
           list.at(0)->year() == 1996;
}

bool sort()
{
    List<Book*> list;
    list.insert(
        new Novel(
            "Fitzgerald", 
            "Margaret A.", 
            "Nurse Practicioner Certification Examination and Practice Preparation", 
            2017
        )
    );
    list.insert(new Novel("Fitzgerald", "F. Scott", "The Great Gatsby", 1925));
    list.insert(new Novel("Fitzgerald", "F. Scott", "This Side of Paradise", 1920));
    list.insert(new Novel("Steinbeck", "John", "The Grapes of Wrath", 1939));
    list.insert(new Novel("Steinbeck", "John", "Of Mice and Men", 1937));
    list.insert(new GraphicNovel("Meltzer", "Brad", "Rags Morales", "Identity Crisis", 2004));

    return list.at(0)->title() == "The Great Gatsby" && 
           list.at(1)->title() == "This Side of Paradise" && 
           list.at(2)->title() == "Nurse Practicioner Certification Examination and Practice Preparation" && 
           list.at(3)->title() == "Identity Crisis" && 
           list.at(4)->title() == "Of Mice and Men" && 
           list.at(5)->title() == "The Grapes of Wrath";
}