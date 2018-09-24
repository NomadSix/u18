// File Name: GraphicNovel.cpp
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

#include "GraphicNovel.hpp"

// Default Constructor
GraphicNovel::GraphicNovel(){}
// Constructor
GraphicNovel::GraphicNovel(str last, str first, str illustrator, str title, uint year) : Book(last, first, title, year), _illustrator(illustrator) {}
// Deconstructor
GraphicNovel::~GraphicNovel(){}

// Virtual function used for abstraction
// Addes the Illustrator to the print of the object 
ostream& GraphicNovel::print(ostream& out) const {
	//return out;
	return out << " Illustrated by " << _illustrator;
}

//return a string representing the calling objects autor name
const str GraphicNovel::getIllName() const {
	return _illustrator;
}

// Assignment overload operator =
const GraphicNovel& GraphicNovel::operator =(const GraphicNovel& book) {
	if (this == &book) {
		return *this;
	}
	_last = book._last;
	_first = book._first;
	_title = book._title;
	_year = book._year;
	_illustrator = book._illustrator;
	return *this;
}