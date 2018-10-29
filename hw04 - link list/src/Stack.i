// File Name: Stack.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 4

// default constructor
template <typename T>
Stack<T>::Stack()
{
    array = List<T>();
}

// parameterized constructor that takes first item
template <typename T>
Stack<T>::Stack(T item)
{
    array.push_front(item);
}

// copy constructor
template <typename T>
Stack<T>::Stack(Stack &copy)
{

    typename List<T>::iterator q = copy.array.begin();
    // while (q != copy.array.end()) {
    //     q++;
    //     array.push_back(*q);
    // }
    for (int i = copy.size(); i > 0; i--) {
        array.push_back(*q);
        q++;
    }
}

// move constructor
template <typename T>
Stack<T>::Stack(Stack &&move)
{
    array = move.array;
}

// destructor
template <typename T>
Stack<T>::~Stack()
{
}

// function empty; does not throw exceptions
template <typename T>
bool Stack<T>::empty() const noexcept
{
    return array.empty();
}

// function size; does not throw exceptions
template <typename T>
unsigned int Stack<T>::size() const noexcept
{
    return array.size();
}

// function top; l-value; throws underflow if stack is empty
template <typename T>
T Stack<T>::top()
{
    if (array.size() == 0) {
        throw std::underflow_error("stack is empty");
    } else {
        typename List<T>::iterator q = array.begin();
        for (int i = array.size(); i > 1; i--) {
            q++;
        }
        return *q;
    }
}

// function top; read-only; throws underflow if stack is empty
template <typename T>
const T Stack<T>::top() const
{
    if (array.size() == 0) {
        throw std::underflow_error("stack is empty");
    } else {
        typename List<T>::const_iterator q = array.begin();
        for (int i = array.size(); i > 1; i--) {
            q++;
        }
        return *q;
    }
}

// function push; does not throw exceptions
template <typename T>
void Stack<T>::push(T val) noexcept
{
    array.push_back(val);
}

// function emplace; does not throw exceptions
template <typename T>
template <class... Args>
void Stack<T>::emplace(Args&&... args) noexcept
{
    // T tmp = T(std::forward<Args>(args)...);
    array.emplace_back(args...);
}

// function pop; throws underflow if stack is empty
template <typename T>
void Stack<T>::pop()
{
    if (array.size() == 0) {
        throw std::underflow_error("stack is empty");
    }
    // array.erase(array.at(array.size()));
    // array.erase(array.end()--);
    
    typename List<T>::iterator q = array.begin();
    for (int i = array.size(); i > 1; i--) {
        q++;
    }
    array.erase(q);
}

// copy assignment operator overload
template <typename T>
const Stack<T>& Stack<T>::operator =(Stack& copy)
{
    if (array.begin() != copy.array.begin()) {
        typename List<T>::iterator q = array.begin();
        for (int i = array.size(); i > 0; i--) {
            array.erase(q);
            q++;
        }
        q = copy.array.begin();
        for (int i = copy.size(); i > 0; i--) {
            array.push_back(*q);
            q++;
        }
    }
    return *this;
}

// move assignment operator overload
template <typename T>
Stack<T>& Stack<T>::operator =(Stack&& move)
{
    array = move.array;
    return *this;
}