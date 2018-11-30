#include "Album.hpp"

Album::Album(std::string t, std::string a, int y)
    : _title(t)
    , _artist(a)
    , _year(y)
{
}

std::string Album::title() const
{
    return _title;
}

std::string Album::artist() const
{
    return _artist;
}

int Album::year() const
{
    return _year;
}

bool operator ==(const Album &lhs, const Album &rhs)
{
    return (!(lhs < rhs) && !(rhs < lhs));
}

bool operator !=(const Album &lhs, const Album &rhs)
{
    return !(lhs == rhs);
}

bool operator < (const Album &lhs, const Album &rhs)
{
    if (lhs.capitalize() < rhs.capitalize()) {
        return true;
    } else if (lhs._artist == rhs._artist) {
        if (lhs._year < rhs._year) {
            return true;
        } else {
            return false;
        } 
    } else {
        return false;
    }
}

bool operator <=(const Album &lhs, const Album &rhs)
{
    return !(rhs < lhs);
}

bool operator > (const Album &lhs, const Album &rhs)
{
    return (rhs < lhs);
}

bool operator >=(const Album &lhs, const Album &rhs)
{
    return !(lhs < rhs);
}


std::ostream& operator<<(std::ostream& sout, const Album &rhs)
{
    sout << "Album: " << rhs._title << "\n"
         << "By: " << rhs._artist << "\n"
         << "In: " << rhs._year << std::endl;

    return sout;
}

std::string Album::capitalize() const
{
    std::string tmp(_artist);

    for (char &i : tmp) {
        if (i >= 'a' && i <= 'z')
            i -= 32;
    }

    return tmp;
}