
template <typename T>
List<T>::const_iterator::const_iterator(Node *node) : _res(node)
{
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++()
{
    _res = _res->next();
    return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int num)
{
    const_iterator tmp = *this;
    ++(*this);

    return tmp;
}

template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator+(int num)
{
    for (int i = 0; _res != nullptr && i < num; ++i) {
        _res = _res->next();
    }
    return *this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--()
{
    const_iterator tmp = *this;
    --(*this);

    return tmp;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int num)
{
    for (int i = 0; _res != nullptr && i < num; ++i) {
        _res = _res->prev();
    }
    return *this;
}

template <typename T>
T& List<T>::const_iterator::operator*()
{
    return _res->key();
}

// function assignment overload const_iterator
template<typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator =(const_iterator it)
{
    return const_iterator(it);
}

template<typename T>
typename List<T>::Node* List<T>::const_iterator::getRes()
{
    return _res;
}