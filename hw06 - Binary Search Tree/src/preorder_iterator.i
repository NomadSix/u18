
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

template <typename T>
typename BST<T>::preorder_iterator BST<T>::preorder_iterator::operator++(int)
{
    preorder_iterator tmp = *this;
    ++(*this);

    return tmp;
}

template <typename T>
void BST<T>::preorder_iterator::findNextSubroot()
{
    // if (_unfinRoot->key() > _curr->key())
    //     return;
    if (_unfinRoot->parent()) { // is not the root
        if (_unfinRoot == _unfinRoot->parent()->right()) {
            _unfinRoot = _unfinRoot->parent();
        }
        if (_unfinRoot->left()) {
            _unfinRoot = _unfinRoot->left();
        } else {
            while (_unfinRoot->right() == false)
                _unfinRoot = _unfinRoot->parent();
            _unfinRoot = _unfinRoot->right();
        }
    } else { // is root
        if (_unfinRoot->left())
            _unfinRoot = _unfinRoot->left();
    }
}