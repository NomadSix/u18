//Default Constructor
template<typename T>
List<T>::List() : _head(nullptr), _last(nullptr)
{
}

// Constructor that takes first item
template<typename T>
List<T>::List(const T& item)
{
    Node* temp = new Node(item);
    insert(iterator(_head, temp));
}

// Copy constructor
template<typename T>
List<T>::List(const List& copy) 
{
    if (copy._head == nullptr) {
        _head = _last = nullptr;
    } else {
        _head = new Node(copy._head);
        Node* tmpNext = copy._head->_next;
        Node* tmp = _head;

        while (tmpNext != nullptr) {
            tmp->_next = new Node(tmpNext, nullptr, tmp);
            tmp = tmp->_next;
            //tmpOther = tmpOther->_next;
        }
        _last = tmp;
    }
}

// Move constructor
template<typename T>
List<T>::List(List &&move) 
{
    _head = move._head;
    move._head = nullptr;
    _last = move._last;
    move._last = nullptr;
}

// Destructor
template<typename T>
List<T>::~List()
{
    Node *temp = _head;

    while (temp) {
        Node* next = temp->_next;
        delete temp;
        temp = next;
    }
}

// function front; l-value
template<typename T>
T &List<T>::front()
{
    return _head;
}

// function front; return by value
template<typename T>
T &List<T>::front() const
{
    return _head;
}

// function back; l-value
template<typename T>
T &List<T>::back()
{
    return _last;
}

// function back; return by value
template<typename T>
T &List<T>::back() const
{
    return _last;
}

// function begin
template<typename T>
typename List<T>::iterator List<T>::begin()
{
    return iterator(_head);
}

// function end
template<typename T>
typename List<T>::iterator List<T>::end()
{
    return iterator(_last);
}

// function begin const overload
template<typename T>
typename List<T>::const_iterator List<T>::begin() const
{
    return const_iterator(_head);
}

// function end const overload
template<typename T>
typename List<T>::const_iterator List<T>::end() const
{
    return const_iterator(_last);
}

// function rbegin
template<typename T>
typename List<T>::reverse_iterator List<T>::rbegin()
{
    return reverse_iterator(_head);
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::rbegin() const
{
    return const_reverse_iterator(_head);
}

template<typename T>
typename List<T>::reverse_iterator List<T>::rend()
{
    return reverse_iterator(_last);
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::rend() const
{
    return const_reverse_iterator(_last);
}

template<typename T>
typename List<T>::const_iterator List<T>::cbegin() const
{
    return const_iterator(_head);
}

template<typename T>
typename List<T>::const_iterator List<T>::cend() const
{
    return const_iterator(_last);
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::crbegin() const
{
    return const_reverse_iterator(_head);
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::crend() const
{
    return const_reverse_iterator(_last);
}

template<typename T>
typename List<T>::iterator List<T>::search(T item)
{
    auto it = iterator();
    Node *tmp = _head;
    Node *temp = new Node(item);

    while (tmp != temp) {
        it++;
        tmp->next();
    }
    return it;
}

template<typename T>
typename List<T>::const_iterator List<T>::search(T item) const
{
    auto it = const_iterator();
    Node *tmp = _head;
    Node *temp = new Node(item);

    while (tmp != temp) {
        it++;
        tmp->next();
    }
    return it;
}

template<typename T>
typename List<T>::iterator List<T>::erase(T item)
{
    auto it = begin();
    for(it; it != end();) {
        if (++it == item) {
            it._M_invalidate();
        }
    }
    return it;
}

template<typename T>
typename List<T>::const_iterator List<T>::erase(iterator it) const
{
    iterator pos = begin();
    for (pos; pos != it; ) {
        if (++pos == it) {
            pos._M_invalidate();
            break;
        }
    }
    return pos;
}

template<typename T>
void List<T>::push_back(T item)
{
    if (!_head) {
        Node *tmp = new Node(item);
        _head = tmp;
    } else {
        Node *tmp = _head;
        while (tmp->next() != nullptr) {
            tmp = tmp->next();
        }

        Node *in = new Node(item);
        tmp->setNext(in);
    }
}

template<typename T>
void List<T>::push_front(T item)
{
    if (!_head) {
        Node *tmp = new Node(item);
        _head = tmp;
    } else {
        Node *in = new Node(item);
        _head.prev(in);
    }
}

template<typename T>
int List<T>::size() 
{
    int size = 0;
    Node temp = _head;
    while (temp != nullptr) {
        size++;
        temp = temp.next();
    }
    return size;
}

// checks if list is empty
template<typename T>
void List<T>::empty()
{
    return _head == nullptr;
}

// function copy assignment overload;
template<typename T>
const List<T>& List<T>::operator=(List<T>& list)
{
    if (this == &list) {
        return *this;
    }
    ~List();
    new(this) List(list);
    return *this;
}

// function move assignment overload;
template<typename T>
List<T>& List<T>::operator=(List<T>&& list)
{
    if (this == &list) {
        return *this;
    }
    _head = nullptr;
    _last = nullptr;
    swap(*this, list);
    return *this;
}

// function assignment overload iterator
//template<typename T>
//typename List<T>::iterator List<T>::iterator::operator =(const_iterator it)
//{
//
//    return iterator(it);
//}

template<typename T>
typename List<T>::iterator List<T>::insert(iterator loc, T item)
{
    Node *in = new Node(item);

    if (_head) {
        Node *pos = searchHelper(loc);
        Node *prev = _head;

        while (prev->next() == pos && prev->next() == nullptr) {
            prev = prev->next();
        }

        in->setNext(pos);
        prev->setNext(in);
    } else {
        _head = in;
    }
}

template <typename T>
template <typename... Args>
void List<T>::emplace_front(Args&&... args)
{
    _head.prev(T(std::forward<Args>(args)...));
}

template<typename T>
template<typename... Args>
void List<T>::emplace_blask(Args &&... args)
{
    _last.next(T(std::forward<Args>(args)..));
}

template<typename T>
template<typename... Args>
typename List<T>::iterator List<T>::emplace(iterator pos, Args &&... args)
{
    if (_head) {
        Node *item = searchHelper(pos);
        pos.next(T(std::forward<Args>(args)...));
    }
}

template<typename T>
typename List<T>::Node* List<T>::searchHelper(typename List<T>::iterator loc) const
{
    Node *tmp = _head;

    while (tmp != nullptr && tmp != loc) {
        if (tmp == loc) {
            break;
        } else {
            tmp = tmp->next();
        }
    }
    return tmp;
}

// Node member functions

template <typename T>
List<T>::Node::Node(T item) : _res(new T(item)), _next(nullptr)
{
}

template <typename T>
typename List<T>::Node* List<T>::Node::next()
{
    return _next;
}

template <typename T>
typename List<T>::Node* List<T>::Node::prev()
{
    return _prev;
}

template <typename T>
void List<T>::Node::setNext(Node *node)
{
    _next = node;
}

template <typename T>
void List<T>::Node::setPrev(Node *node)
{
    _prev = node;
}

template <typename T>
T& List<T>::Node::key()
{
    return *_res;
}

