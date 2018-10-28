// File Name: List.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

// Default Constructor
template <class T>
List<T>::List() : _begin(alloc.allocate(0)), _end(_begin), _cap(_begin) {}


// Constructor that takes first item of list
template <class T>
List<T>::List(T item) : _begin(alloc.allocate(1)), _end(_begin), _cap(_begin + 1) 
{
	//cout << " construct ";
	alloc.construct(_end++, item);
}

// Copy Constructor
template <typename T>
List<T>::List(const List &rhs) : _begin(alloc.allocate(rhs.size())), _end(_begin), _cap(_begin + rhs.size()) 
{
	for (size_t i = 0; i < rhs.size(); i++) 
		alloc.construct(_end++, rhs._begin[i]); 
} 

// Move Constructor
template <class T>
List<T>::List(List&& list) 
{
	*this = std::move(list);
}

// Destructor
template <class T>
List<T>::~List() 
{
	//cout << " decon ";
	if (_begin) {        
		while (_end != _begin) {
            alloc.destroy(--_end);
        }
        alloc.deallocate(_begin, capacity());
	}
    _begin = _end = _cap = nullptr;
}

// Copy assignment operator overload
template <class T>
const List<T>& List<T>::operator =(List<T>& list)
{
	//cout << " =copy ";
	if (this == &list) {
		return *this;
	}

	_begin = alloc.allocate(list.capacity());
	_end = _begin;
	_cap = list._cap;
	for (size_t i = 0; i < list.size(); i ++) {
		alloc.construct(_end++, list._begin[i]);
	}
	return *this;
}

// Move assignment operator overload
template <class T>
List<T>& List<T>::operator =(List<T>&& list) 
{
	if (this == &list) {
		return *this;
	}

	_begin = list._begin;
	_end = list._end;
	_cap = list._cap;
	list._begin = list._end = list._cap = nullptr;

	return *this;
}

// Overloaded array operator []
template <class T>
T List<T>::operator [](uint index) const 
{
	return _begin[index];
}


// function size; does not throw exceptions
template <class T>
uint List<T>::size() const noexcept 
{
	return _end - _begin;
}

// function capacity; does not throw exceptions
template <class T>
uint List<T>::capacity() const noexcept 
{
	return _cap - _begin;
}

template <class T>
void List<T>::grow()
{
	if (capacity() == 0) {
		_begin = alloc.allocate(1);
		_end = _begin;
		_cap = _begin + 1;
		return;
	}

	T* tempBegin = alloc.allocate(capacity() * 2);
	T* tempEnd = tempBegin;
	T* tempCap = tempBegin + (capacity() * 2);
	
	for (T* i = _begin; i != _end; i++) {
		alloc.construct(tempEnd++, move(*i));
	}
	
	_begin = tempBegin;
	_end = tempEnd;
	_cap = tempCap;
}

template <class T>
void List<T>::shiftBack(int index)	
{
	for(int i = size()-1; i >= index; i--){
		_begin[i+1] = _begin[i];
	}
	_end++;
}

// function insert; does not throw exceptions
template <class T>
void List<T>::insert(T item) noexcept 
{
	//cout << " insert ";
	if (capacity() == size()) {
		grow();
	}
	uint index = 0;
	// while(index <= size() && *item < *_begin[index]) {
	while(index < size()) {
		if (*item < *_begin[index])
			break;
		else 
			index++;
	}
	shiftBack(index);
	_begin[index] = item;
}

// function erase; throws underflow_error if empty, range_error if item doesn't exist
template <class T>
void List<T>::erase(T item) 
{
	//cout << " erase ";
	if (size() == 0)
		throw std::underflow_error("error can't erase item: list is empty");
	try {
		search(item);
	} catch(std::domain_error& e) {
		throw std::range_error("");
	}
	
	for (size_t i = 0; i < size() - 1; i++) {
		if (_begin[i] != item) {
			_begin[i] = _begin[i+1];
		}
	}
	_end--;
}


// function search; throws domain error if item doesn't exist
template <class T>
int List<T>::search(const T& item) 
{
	for (size_t i = 0; i < size(); i++) {
		if (_begin[i] == item) {
			return i;
		}
	}
	throw std::domain_error("error searching list: item doesn't exist");
}

// function at; throws out_of_range exception; returns a const value
template <class T>
const T& List<T>::at(const uint index) const 
{
	if (index > size())
		throw std::out_of_range("error checking index: index out of range");
	return _begin[index];
}

// function at; throws out_of_range exception; returns a const value
template <class T>
T& List<T>::at(const uint index) 
{
	//cout << " at ";
	if (index > size())
		throw std::out_of_range("error checking index: index out of range");
	return _begin[index];
}