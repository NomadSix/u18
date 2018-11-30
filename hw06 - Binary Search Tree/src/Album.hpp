#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <iostream>
#include <string>

class Album {
public:
    Album(std::string t, std::string a, int y);
    std::string title() const;
    std::string artist() const;
    int year() const;
    friend bool operator ==(const Album &lhs, const Album &rhs);
    friend bool operator !=(const Album &lhs, const Album &rhs);
    friend bool operator < (const Album &lhs, const Album &rhs);
    friend bool operator <=(const Album &lhs, const Album &rhs);
    friend bool operator > (const Album &lhs, const Album &rhs);
    friend bool operator >=(const Album &lhs, const Album &rhs);

    friend std::ostream& operator<<(std::ostream& sout, const Album &rhs);
private:
    std::string _title;
    std::string _artist;
    int _year;

    std::string capitalize() const;
};

#endif