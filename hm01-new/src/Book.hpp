// File Name: Book.hpp
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
typedef unsigned int uint;
typedef string str;

class Book {
public:
	// Default Constructor
	Book();
	// Copy Construtor
	Book(const Book&);
	// Constructor
	Book(string, str, str, uint);
	// Destructor
	virtual ~Book();
	//return a string representing the calling objects autor name
	const str getFirstName() const;
	//return a string representing the calling objects autor name
	const str getLastName() const;
	//return the authors first and last name as one string
	const str author() const;
	//return a string representing the calling objects title
	const str title() const;
	//return a string representing the calling objects release year
	const uint year() const;
	// Insertion operator overload
	virtual ostream& print(ostream&) const = 0;
	// Insertion operator overload
	friend ostream& operator <<(ostream& out, const Book& book);
	// Overloaded equality operator ==
	bool operator ==(const Book& book) const;
	// Overloaded relational operator <
	bool operator <(const Book& book) const;
protected:
	str _last;
	str _first;
	str _title;
	uint _year;
};
#endif

