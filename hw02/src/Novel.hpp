// File Name: Novel.hpp
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

#ifndef NOVEL_HPP_
#define NOVEL_HPP_

#include "Book.hpp"
#include <string>
#include <iostream>
using namespace std;
typedef unsigned int uint;

class Novel: public Book {
public:
	// Default Constructor
	Novel();
	// Constructor
	Novel(str, str, str, uint);
	// Destructor
	virtual ~Novel();
	// virtual function used for abstration
	virtual ostream& print(ostream&) const;
	// assignment operation overload =
	const Novel& operator =(const Novel& book);
};
#endif /* NOVEL_HPP_ */
