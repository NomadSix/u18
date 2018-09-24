// File Name: List.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 1

// Default Constructor
template <class T>
List<T>::List() : _size(0), _capacity(0), array(new T[_capacity]) {}


// Constructor that takes first item of list
template <class T>
List<T>::List(T item) : _size(0), _capacity(0), array(new T[_capacity]) {
	insert(item);
}

// Copy Constructor
template <class T>
List<T>::List(const List<T>& list) {
	_size = list._size;
	_capacity = list._size;
	array = new T[list._capacity];
	for (uint i = 0; i < list._size; i++) {
		array[i] = list.array[i];
	}
}

// Move Constructor
template <class T>
List<T>::List(List&& list) : _size(0), _capacity(0), array(nullptr) {
	*this = std::move(list);
}

// Destructor
template <class T>
List<T>::~List() {
	if (array)
		delete [] array;
}

// Copy assignment operator overload
template <class T>
const List<T>& List<T>::operator =(List<T>& list) {
	if (this == &list) {
		return *this;
	}
	delete[] array;
	_capacity = list._capacity;
	_size = list._size;
	array = new T[_capacity];
	for (uint i = 0; i < list._size; i ++) {
		array[i] = list.array[i];
	}
	sort(array, _size);
	return *this;
}

// Move assignment operator overload
template <class T>
List<T>& List<T>::operator =(List<T>&& list) {
	if (this != &list) {
		_size = list._size;
		_capacity = list._capacity;
		delete [] array;
		array = list.array;
		list._size = 0;
		list._capacity = 0;
		list.array = nullptr;
	}
	sort(array, _size);
	return *this;
}

// Overloaded array operator []
template <class T>
T List<T>::operator [](uint index) const {
	return *(array + index);
}


// function size; does not throw exceptions
template <class T>
uint List<T>::size() const noexcept {
	return _size;
}


// function capacity; does not throw exceptions
template <class T>
uint List<T>::capacity() const noexcept {
	return _capacity;
}

// function sort change the order of the array
template <class T>
void List<T>::sort(T* list, uint count) {
	T t;
	for (uint i = 1; i < count; i++) {
		for (uint j = count-1; j >= i; j--) {
			if (*list[j] < *list[j-1]) {
				t = list[j-1];
				list[j-1] = list[j];
				list[j] = t;
			}
		}
	}
}

// function insert; does not throw exceptions
template <class T>
void List<T>::insert(T item) noexcept {
	if (_capacity == _size) {
		//make space
		if (_capacity != 0) {
			_capacity *= ARRAY_MULT;
		} else {
			_capacity = 1;
		}
		//allocate and move
		T* temp = array;
		array = new T[_capacity];
		for (uint i = 0; i < _size; i++) {
			array[i] = temp[i];
		}		
		// deallocate temp array
		delete[] temp;
	}
	array[_size++] = item;
	sort(array, _size);
}

// function erase; throws underflow_error if empty, range_error if item doesn't exist
template <class T>
void List<T>::erase(T item) {
	if (_size == 0)
		throw std::underflow_error("error can't erase item: list is empty");
	try {
		search(item);
	} catch(std::domain_error& e) {
		throw std::range_error("");
	}
	
	for (uint i = 0; i < _size; i++) {
		if (array[i] != item) {
			array[i] = array[i+1];
		}
	}
	_size--;
}


// function search; throws domain error if item doesn't exist
template <class T>
int List<T>::search(const T& item) {
	for (uint i = 0; i < _size; i++) {
		if (array[i] == item) {
			return i;
		}
	}
	throw std::domain_error("error searching list: item doesn't exist");
}

// function at; throws out_of_range exception; returns a const value
template <class T>
const T& List<T>::at(const uint index) const {
	if (index > _size)
		throw std::out_of_range("error checking index: index out of range");
	return array[index];
}

// function at; throws out_of_range exception; returns a const value
template <class T>
T& List<T>::at(const uint index) {
	if (index > _size)
		throw std::out_of_range("error checking index: index out of range");
	return array[index];
}