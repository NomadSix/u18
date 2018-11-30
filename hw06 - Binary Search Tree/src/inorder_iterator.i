// File Name: inorder_iterator.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 6

template <typename T>
BST<T>::inorder_iterator::inorder_iterator(Queue<T> que)
    : _queue(que)
{
}

template <typename T>
T& BST<T>::inorder_iterator::operator*()
{
    return _queue.front();
}

template <typename T>
typename BST<T>::inorder_iterator& BST<T>::inorder_iterator::operator++()
{
    _queue.pop();
    return *this;
}

template <typename T>
typename BST<T>::inorder_iterator BST<T>::inorder_iterator::operator++(int)
{
    inorder_iterator tmp = *this;
    ++(*this);

    return tmp;
}