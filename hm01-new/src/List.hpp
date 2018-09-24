/*
 * Template class that will be used to hold pointers to things
 * Sorted array list, depends on operator< existing for the type being held
 */
// File Name: List.hpp
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP
typedef unsigned int uint;

// Any necessary includes
#include <stdexcept>
using namespace std;

// It's a template class
template <class T>
class List {
public:
    // Default Constructor
	List();
    // Constructor that takes first item of list
	List(T);
    // Copy Constructor
	List(const List&);
    // Move Constructor
	List(List&&);
    // Destructor
	~List();
    // Copy assignment operator overload
	const List& operator =(List&);
    // Move assignment operator overload
	List& operator =(List&&);
	// Overloaded array operator []
	T operator [](uint) const;
    // function size; does not throw exceptions
	uint size() const noexcept;
    // function capacity; does not throw exceptions
	uint capacity() const noexcept;
    // function insert; does not throw exceptions
	void insert(T) noexcept;
    // function erase; throws underflow_error if empty, range_error if item doesn't exist
	void erase (T);
    // function at; throws out_of_range exception; returns a const value
	const T& at(const uint) const; //TODO find out what params
    // function at; throws out_of_range exception; returns l-value
	T& at(const uint); //TODO fing out what params
    // function search; throws domain error if item doesn't exist
	int search(const T&);
    // function sort changes the order of the array
	void sort(T*, uint);
private:
    // variable that gives us our dynamic array
    uint _size;
    uint _capacity;
    T *array;
	static const int ARRAY_MULT = 2;
};


// LIST CLASS FUNCTION IMPLEMENTATIONS
#include "List.i"

#endif











