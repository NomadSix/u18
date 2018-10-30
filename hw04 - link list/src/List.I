// File Name: List.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 4

//Default Constructor
template<typename T>
List<T>::List()
{
    _head = _last = nullptr;
}

// Constructor that takes first item
template<typename T>
List<T>::List(const T& item)
{
//    Node *node = new Node(item);
//    _head->setNext(node);
//    node->setPrev(_head);
//    node->setNext(_last);
    _head = _last = nullptr;
    push_front(item);
}

// Copy constructor
template<typename T>
List<T>::List(const List& copy) 
{
    if (copy._head == nullptr) {
        _head = _last = nullptr;
    } else {
        _head = new Node(copy._head->key());
        Node* tmpCopy = copy._head;
        Node* tmp = _head;

        while (true) {
            tmpCopy = tmpCopy->next();
            if (!tmpCopy) break;
            Node *tmpIn = new Node(tmpCopy->key());
            tmpIn->setPrev(tmp);
            tmp->setNext(tmpIn);
            tmp = tmpIn;
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
    ~move();
}

// Destructor
template<typename T>
List<T>::~List()
{
    while (_head) {
        Node *tmp = _head;
        _head = _head->next();
        delete tmp;
    }
}

// function front; l-value
template<typename T>
T &List<T>::front()
{
    return _head->key();
}

// function front; return by value
template<typename T>
T &List<T>::front() const
{
    return _head->key();
}

// function back; l-value
template<typename T>
T &List<T>::back()
{
    return _last->key();
}

// function back; return by value
template<typename T>
T &List<T>::back() const
{
    return _last->key();
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
    return iterator(_last->next());
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
    return const_iterator(nullptr);
}

// function rbegin
template<typename T>
typename List<T>::reverse_iterator List<T>::rbegin()
{
    return reverse_iterator(_last);
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::rbegin() const
{
    return const_reverse_iterator(_last);
}

template<typename T>
typename List<T>::reverse_iterator List<T>::rend()
{
    return reverse_iterator(nullptr);
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::rend() const
{
    return const_reverse_iterator(nullptr);
}

template<typename T>
typename List<T>::const_iterator List<T>::cbegin() const
{
    return const_iterator(_head);
}

template<typename T>
typename List<T>::const_iterator List<T>::cend() const
{
    return const_iterator(nullptr);
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::crbegin() const
{
    return const_reverse_iterator(_last);
}

template<typename T>
typename List<T>::const_reverse_iterator List<T>::crend() const
{
    return const_reverse_iterator(nullptr);
}

template<typename T>
typename List<T>::iterator List<T>::search(T item)
{
    for (auto in = begin(); in != end(); in++) {
        if (*in == item)
            return in;
    }
    throw std::invalid_argument("search term not in list");
}

template<typename T>
typename List<T>::const_iterator List<T>::search(T item) const
{
    for (auto in = cbegin(); in != cend(); in++) {
        if (*in == item)
            return in;
    }
    throw std::invalid_argument("search term not in list");
}

template<typename T>
typename List<T>::iterator List<T>::erase(T item)
{
    iterator it = begin();
    for (it = begin(); it != _last; ++it) {
        if (*it == item) {
            //change prev and next
            Node* tmp = it.getRes();
            if (tmp->next()) tmp->next()->setPrev(tmp->prev());
            if (tmp->prev()) tmp->prev()->setNext(tmp->next());
            auto tore = iterator(tmp->next());
            delete tmp;
            return tore;
        }
    }
    throw std::invalid_argument("erase term not in list");
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator it)
{
    for (iterator i = begin(); i != end(); i++) {
        if (i == it) {
            Node* tmp = it.getRes();
            if (tmp->next())
                tmp->next()->setPrev(tmp->prev());
            else
                _last = tmp->prev();
            if (tmp->prev())
                tmp->prev()->setNext(tmp->next());
            else
                _head = tmp->next();
            auto toReturn = tmp->next();
            delete tmp;
            return iterator(toReturn);
        }
    }
    return begin();
    //throw std::invalid_argument("item not in list");
}

template<typename T>
void List<T>::push_back(T item)
{
    if (_last == nullptr) {
        push_front(item);
    } else {
        insert(_last, item);
    }
}

template<typename T>
void List<T>::push_front(T item)
{
    Node *in = new Node(item);
    if (_head == nullptr) {
        _head = _last = in;
        in->setPrev(nullptr);
        in->setNext(nullptr);
    } else {
        //insert(begin(), in->key());
        in->setNext(_head);
        _head = in;
    }
}

template<typename T>
typename List<T>::iterator List<T>::insert(iterator loc, T item)
{
    Node *in = new Node(item);
    if (!_head) {
        _head = _last = in;
        return iterator(_head);
    }
    //Node *pos = searchHelper(loc);
    Node *pos = loc.getRes();
    if (pos->next() == nullptr) {
        in->setNext(nullptr);
        _last = in;
    } else {
        in->setNext(pos->next());
        pos->next()->setPrev(in);
    }
    in->setPrev(pos);
    pos->setNext(in);

    return iterator(pos->next());
}

template<typename T>
unsigned int List<T>::size() const
{
    if (!_head)
        return 0;
    unsigned int size = 0;
    Node *temp = _head;
    while (temp) {
        size++;
        if (temp)
            temp = temp->next();
    }
//    delete temp;
    return size;
}

// checks if list is empty
template<typename T>
bool List<T>::empty() const
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
    while (_head) {
        Node *tmp = _head;
        _head = _head->next();
        delete tmp;
    }
    while (list._head) {
        push_back(list._head->key());
        list._head = list._head->next();
    }
    return *this;
}

// function move assignment overload;
template<typename T>
List<T>& List<T>::operator=(List<T>&& list)
{
    if (this == &list) {
        return *this;
    }
    _head = list._head;
    _last = list._last;
    //~list();
    return *this;
}

template<typename T>
typename List<T>::Node *List<T>::searchHelper(iterator loc)
{
    for (iterator it = begin(); it != end(); it++) {
        if (it == loc) {
            return  it.getRes();
        }
    }
    return nullptr;
}

// Node member functions

template <typename T>
List<T>::Node::Node(T item) : _res(new T(item)), _next(nullptr), _prev(nullptr)
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

