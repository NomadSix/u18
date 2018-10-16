
template <typename T>
List<T>::reverse_iterator::reverse_iterator(Node *node) : _res(node)
{
}

template <typename T>
List<T>::reverse_iterator List<T>::reverse_iterator::operator++()
{
    _res = _res->next();
    return *this;
}

template <typename T>
const List<T>::reverse_iterator List<T>::reverse_iterator::operator++(int num)
{
    reverse_iterator tmp = *this;
    ++(*this);

    return tmp;
}

template <typename T>
List<T>::reverse_iterator List<T>::reverse_iterator::operator--()
{
    _res = _res->prev();
    return *this;
}

template <typename T>
const List<T>::reverse_iterator List<T>::reverse_iterator::operator--(int num)
{
    reverse_iterator tmp = *this;
    --(*this);

    return tmp;
}

template <typename T>
T& List<T>::reverse_iterator::operator*()
{
    return _res->key();
}