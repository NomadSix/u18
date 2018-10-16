
template <typename T>
List<T>::const_iterator::const_iterator(Node *node) : _res(node)
{
}

template <typename T>
List<T>::const_iterator List<T>::const_iterator::operator++()
{
    _res = _res->next();
    return *this;
}

template <typename T>
const List<T>::const_iterator List<T>::const_iterator::operator++(int num)
{
    const_iterator tmp = *this;
    ++(*this);

    return tmp;
}

template <typename T>
List<T>::const_iterator List<T>::const_iterator::operator--()
{
    _res = _res->prev();
    return *this;
}

template <typename T>
const List<T>::const_iterator List<T>::const_iterator::operator--(int num)
{
    const_iterator tmp = *this;
    --(*this);

    return tmp;
}

template <typename T>
T& List<T>::const_iterator::operator*()
{
    return _res->key();
}