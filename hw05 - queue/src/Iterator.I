// File Name: Iterator.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 4

template <typename T>
List<T>::iterator::iterator(Node *node) : _res(node)
{
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++()
{
    _res = _res->next();
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int num)
{
    iterator tmp = *this;
    ++(*this);

    return tmp;
}

template <typename T>
typename List<T>::iterator& List<T>::iterator::operator+(int num)
{
    for (int i = 0; _res != nullptr && i < num; ++i) {
        _res = _res->next();
    }
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator--()
{
    iterator tmp = *this;
    --(*this);

    return tmp;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int num)
{
    for (int i = 0; _res != nullptr && i < num; ++i) {
        _res = _res->prev();
    }
    return *this;
}

template <typename T>
T& List<T>::iterator::operator*()
{
    return _res->key();
}

// function assignment overload iterator
template<typename T>
typename List<T>::iterator List<T>::iterator::operator =(const_iterator it)
{
    if (*this == it)
        return *this;
    *this->_res = *it.getRes();
    return *this;
}

template<typename T>
typename List<T>::Node* List<T>::iterator::getRes()
{
    return _res;
}