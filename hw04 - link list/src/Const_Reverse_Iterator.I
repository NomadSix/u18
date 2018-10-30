// File Name: Const_Reverse_Iterator.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 4

template <typename T>
List<T>::const_reverse_iterator::const_reverse_iterator(Node *node) : _res(node)
{
}

template <typename T>
typename List<T>::const_reverse_iterator List<T>::const_reverse_iterator::operator++()
{
    _res = _res->prev();
    return *this;
}

template <typename T>
typename List<T>::const_reverse_iterator List<T>::const_reverse_iterator::operator++(int num)
{
    const_reverse_iterator tmp = *this;
    ++(*this);

    return tmp;
}

template <typename T>
typename List<T>::const_reverse_iterator List<T>::const_reverse_iterator::operator--()
{
    _res = _res->next();
    return *this;
}

template <typename T>
typename List<T>::const_reverse_iterator List<T>::const_reverse_iterator::operator--(int num)
{
    const_reverse_iterator tmp = *this;
    --(*this);

    return tmp;
}

template <typename T>
T& List<T>::const_reverse_iterator::operator*()
{
    return _res->key();
}