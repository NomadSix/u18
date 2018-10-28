
// default constructor
template <typename T>
Stack<T>::Stack()
{
    array = List<T*>();
}

// parameterized constructor that takes first item
template <typename T>
Stack<T>::Stack(T item)
{
    array.insert(&item);
}

// copy constructor
template <typename T>
Stack<T>::Stack(Stack &copy)
{
    // if (*this == copy){
    //     return;
    // }

    for (size_t i = 0; i < copy.size(); ++i) {
        array.insert(copy.array.at(i));
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
    return array.size() == 0;
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
        return *array[array.size() - 1];
    }
}

// function top; read-only; throws underflow if stack is empty
template <typename T>
const T Stack<T>::top() const
{
    if (array.size() == 0) {
        throw std::underflow_error("stack is empty");
    } else {
        return *array[array.size() - 1];
    }
}

// function push; does not throw exceptions
template <typename T>
void Stack<T>::push(T val) noexcept
{
    array.insert(&val);
}

// function emplace; does not throw exceptions
template <typename T>
template <class... Args>
void Stack<T>::emplace(Args&&... args) noexcept
{
    T tmp = T(std::forward<Args>(args)...);
    array.insert(&tmp);
}

// function pop; throws underflow if stack is empty
template <typename T>
void Stack<T>::pop()
{
    if (array.size() == 0) {
        throw std::underflow_error("stack is empty");
    }
    array.erase(array.at(array.size()));
}

// copy assignment operator overload
template <typename T>
const Stack<T>& Stack<T>::operator =(Stack& copy)
{

}

// move assignment operator overload
template <typename T>
Stack<T>& Stack<T>::operator =(Stack&& move)
{

}