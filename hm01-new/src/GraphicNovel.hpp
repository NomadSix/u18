// File Name: GraphicNovel.h
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

#ifndef GRAPHICNOVEL_HPP_
#define GRAPHICNOVEL_HPP_

#include "Book.hpp"
#include <string>
#include <iostream>
using namespace std;
typedef unsigned int uint;

class GraphicNovel: public Book {
public:
	// Default Constructor
	GraphicNovel();
	// Constructor
	GraphicNovel(str, str, str, str, uint);
	// Destructor
	virtual ~GraphicNovel();
	//return a string representing the calling objects illustrator name
	const str getIllName() const;
	// Virtual function used for abstraction
	// Addes the Illustrator to the print of the object
	virtual ostream& print(ostream&) const;
	// Assignment overload operator =
	const GraphicNovel& operator =(const GraphicNovel& book);
private:
	str _illustrator;
};

#endif /* GRAPHICGRAPHICNOVEL_HPP_ */












