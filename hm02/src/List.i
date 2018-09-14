// File Name: List.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

// Default Constructor
template <class T>
List<T>::List() : _begin(alloc.allocate(0)), _end(_begin), _cap(_begin) {
	cout << " default ";
}


// Constructor that takes first item of list
template <class T>
List<T>::List(T item) : _begin(alloc.allocate(0)), _end(_begin), _cap(_begin + 1) 
{
	cout << " construct ";
	alloc.construct(_end++, item);
}

// Copy Constructor
template <class T>
List<T>::List(const List<T>& list) 
{
	cout << " copy ";
	_begin = list._begin;
	_end = list._end;
	_cap = list._end;

	for (T* i = _begin; i != _begin; i++) {
		alloc.construct(_end++, move(*i));
	}

}

// Move Constructor
template <class T>
List<T>::List(List&& list) : _begin(alloc.allocate(0)), _end(_begin), _cap(_begin + 1) 
{
	cout << " move ";
	*this = std::move(list);
}

// Destructor
template <class T>
List<T>::~List() 
{
	cout << " decon ";
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
	cout << " =copy ";
	if (this == &list) {
		return *this;
	}

	while (_end != _begin) {
		alloc.destroy(--_end);
	}
	alloc.deallocate(_begin, capacity());

	_begin = alloc.allocate(list.capacity());
	_end = list._end;
	_cap = list._cap;
	for (size_t i = 0; i < list.size(); i ++) {
		alloc.construct(_end++, list._begin[i]);
	}
	//sort(array, _size);
	return *this;
}

// Move assignment operator overload
template <class T>
List<T>& List<T>::operator =(List<T>&& list) 
{
	cout << " = move ";
	if (this != &list) {
		_begin = list._begin;
		_end = list._end;
		_cap = list._cap;
		
		while(_end != _begin) {
			alloc.destroy(--_end);
		}
		alloc.deallocate(_begin, capacity());

		for(size_t i = 0; i < list.size(); i++) {
			alloc.construct(_end++, list._begin[i]);
		}
		list._begin = list._end = list._cap = nullptr;

		
		while(list._end != list._begin) {
			list.alloc.destroy(--list._end);
		}
		list.alloc.deallocate(list._begin, list.capacity());
		
	}
	//sort(array, _size);
	return *this;
}

// Overloaded array operator []
template <class T>
T List<T>::operator [](uint index) const 
{
	return *(_begin + index);
}


// function size; does not throw exceptions
template <class T>
uint List<T>::size() const noexcept 
{
	cout << " size " << (_end - _begin);
	return _end - _begin;
}


// function capacity; does not throw exceptions
template <class T>
uint List<T>::capacity() const noexcept 
{
	cout << " cap " << (_cap - _begin);
	return _cap - _begin;
}

// function sort change the order of the array
template <class T>
void List<T>::sort(T* list, uint count) 
{
	T t;
	for (size_t i = 1; i < count; i++) {
		for (size_t j = count-1; j >= i; j--) {
			if (*list[j] < *list[j-1]) {
				t = list[j-1];
				list[j-1] = list[j];
				list[j] = t;
			}
		}
	}
}

template <class T>
void List<T>::grow()
{
	if (_begin == nullptr) {
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
	
	while(_end != _begin){
		alloc.destroy(--_end);
	}
	alloc.deallocate(_begin, capacity());
	
	_begin = tempBegin;
	_end = tempEnd;
	_cap = tempCap;
	cout << " grow " << (_end - _begin) << " " << (_cap - _begin);
}

// function insert; does not throw exceptions
template <class T>
void List<T>::insert(T item) noexcept 
{
	cout << " insert ";
	if (_end == _cap) {
		grow();
	}
	alloc.construct(_end++, item);
}

// function erase; throws underflow_error if empty, range_error if item doesn't exist
template <class T>
void List<T>::erase(T item) 
{
	cout << " erase ";
	if (size() == 0)
		throw std::underflow_error("error can't erase item: list is empty");
	try {
		search(item);
	} catch(std::domain_error& e) {
		throw std::range_error("");
	}
	
	for (size_t i = 0; i < size(); i++) {
		if (*(_begin + i) != item) {
			//array[i] = array[i+1];
			alloc.construct(_end++, *(_begin + i + 1));
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
	cout << " at ";
	if (index > size())
		throw std::out_of_range("error checking index: index out of range");
	return _begin[index];
}