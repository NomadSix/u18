// File Name: Book.cpp
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

#ifndef BOOK_CPP
#define BOOK_CPP
#include "Book.hpp"

// Constructor
Book::Book(str last, str first, str title, uint year) : _last(last), _first(first), _title(title), _year(year) {}
// Copy Constructor
Book::Book(const Book& obj) {
	_last = obj._last;
	_first = obj._first;
	_title = obj._title;
	_year = obj._year;
}
// Default Constructor
Book::Book() : Book("", "", "", 0) {}
// Destructor
Book::~Book() {}

// Insertion operator overload
ostream& operator <<(ostream& out, const Book& book) {
	out << book._title << " by " << book._first << " " << book._last << " released in " << book._year;
	book.print(out);
	return out;
}

// Overloaded equality operator ==
bool Book::operator ==(const Book& book) const {
	return (_title == book._title) && (_first == book._first) && (_last == book._last) && (_year == book._year);
}

// Overloaded relational operator <
bool Book::operator <(const Book& book) const {
	if (_last < book._last) {
		return true;
	}
	else if (_last == book._last && _first < book._first) {
		return true;
	}
	else if (_last == book._last && _first == book._first && _title < book._title) {
		return true;
	}
	return false;
}


//return a string representing the calling objects autor name
const str Book::getFirstName() const {
	return _first;
}

//return a string representing the calling objects autor name
const str Book::getLastName() const {
	return _last;
}

const str Book::author() const{
	return _first + " " + _last;
}

//return a string representing the calling objects title
const str Book::title() const {
	return _title;
}

//return a string representing the calling objects release year
const uint Book::year() const {
	return _year;
}
#endif