
template<typename T>
BST<T>::preorder_iterator::preorder_iterator(Node *curr, Node *subroot) 
    : _curr(curr)
    , _unfinRoot(subroot)
{
}

template <typename T>
T& BST<T>::preorder_iterator::operator*()
{
    return _curr->key();
}

template <typename T>
typename BST<T>::preorder_iterator& BST<T>::preorder_iterator::operator++()
{
    // Check if empty
    if (_curr == nullptr && _unfinRoot == nullptr)
        return *this;
    
    // Check if at end
    
}