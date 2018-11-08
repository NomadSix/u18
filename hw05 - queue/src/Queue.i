
// Default Constructor
template <typename T>
Queue<T>::Queue()
{
    list = List<T>();
}

// Parameterized Constructor
template <typename T>
Queue<T>::Queue(T val)
{
    list.push_front(val);
}

// Copy Constructor
template <typename T>
Queue<T>::Queue(Queue &copy)
{
    auto q = copy.list.begin();
    for (size_t i = copy.size(); i > 0; i--) {
        list.push_back(*q);
        q++;
    }
}

// Move Constructor
template <typename T>
Queue<T>::Queue(Queue &&move)
{
    list = move.list;
}

// Destructor
template <typename T>
Queue<T>::~Queue()
{}

// function empty, does not throw exceptions
template <typename T>
bool Queue<T>::empty() const noexcept
{
    return list.empty();
}

// function size, does not throw exceptions
template <typename T>
size_t Queue<T>::size() const noexcept
{
    return list.size();
}

// function front, l-value, throws underflow
template <typename T>
T& Queue<T>::front()
{
    if (list.size() == 0)
        throw std::underflow_error("stack is empty");
    return *list.begin();
}

// function front, read-only, throws underflow
template <typename T>
const T& Queue<T>::front() const
{
    if (list.size() == 0)
        throw std::underflow_error("stack is empty");
    return *list.begin();
}

// function back, l-value, throws underflow
template <typename T>
T& Queue<T>::back()
{
    if (list.size() == 0)
        throw std::underflow_error("stack is empty");
    auto q = list.begin();
    for (size_t i = list.size(); i > 1; i--) {
        q++;
    }
    return *q;
}

// function back, read-only, throws underflow
template <typename T>
const T& Queue<T>::back() const
{
    if (list.size() == 0)
        throw std::underflow_error("stack is empty");
    auto q = list.begin();
    for (size_t i = list.size(); i > 1; i--) {
        q++;
    }
    return *q;
}

// function push, does not throw exceptions
template <typename T>
void Queue<T>::push(const T& val)
{
    list.push_back(val);
}

// function emplace, does not throw exceptions
template <typename T>
template <class... Args>
void Queue<T>::emplace(Args... args)
{
    list.emplace_back(args...);
}

// function pop, throws underflow
template <typename T>
void Queue<T>::pop()
{
    if (list.size() == 0)
        throw std::underflow_error("stack is empty");
    list.erase(list.begin());
}

// Copy assignment operator overload
template <typename T>
const Queue<T>& Queue<T>::operator =(Queue& copy)
{
    if (list.begin() != copy.list.begin()) {

        //pop all vals in queue
        for (size_t i = list.size(); i > 0; i--) {
            pop();
        }
        //copy over vals from other queue
        auto q = copy.list.begin();
        for (size_t i = copy.list.size(); i > 0; i--) {
            list.push_back(*q);
            q++;
        }
    }
    return *this;
}

// Move assignment operator overload
template <typename T>
Queue<T>& Queue<T>::operator =(Queue&& move)
{
    if (list.begin() == move.list.begin())
        return *this;
    list = move.list;
    return *this;
}