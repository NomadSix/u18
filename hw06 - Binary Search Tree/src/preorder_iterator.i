// File Name: preorder_iterator.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 6

template<typename T>
BST<T>::preorder_iterator::preorder_iterator(Queue<T> que)
    : _queue(que)
{
}

template <typename T>
T& BST<T>::preorder_iterator::operator*()
{
    return _queue.front();
}

template <typename T>
typename BST<T>::preorder_iterator& BST<T>::preorder_iterator::operator++()
{
    _queue.pop();
    return *this;
}

template <typename T>
typename BST<T>::preorder_iterator BST<T>::preorder_iterator::operator++(int)
{
    preorder_iterator tmp = *this;
    ++(*this);

    return tmp;
}
