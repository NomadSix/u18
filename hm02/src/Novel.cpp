// File Name: Novel.cpp
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

#include "Novel.hpp"

// Default Constructor
Novel::Novel(){}

// Constructor
Novel::Novel(str last, str first, str title, uint year) : Book(last, first, title, year) {}
//First, last are switched with book ctor

// Destructor
Novel::~Novel() {}

// virtual function used for abstration
ostream& Novel::print(ostream& out) const {
	return out;
}

// assignment operation overload =
const Novel& Novel::operator =(const Novel& book) {
	if (this == &book)
		return *this;

	_last = book._last;
	_first = book._first;
	_title = book._title;
	_year = book._year;
	return *this;
}
