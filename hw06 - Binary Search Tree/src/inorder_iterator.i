
template <typename T>
BST<T>::inorder_iterator::inorder_iterator(typename BST<T>::Node *curr, typename BST<T>::Node *subroot)
    : _curr(curr)
    , _unfinRoot(subroot)
{
}

template <typename T>
T& BST<T>::inorder_iterator::operator*()
{
    return _curr->key();
}

template <typename T>
typename BST<T>::inorder_iterator& BST<T>::inorder_iterator::operator++()
{
    // Empty Check
    if (_curr == nullptr && _unfinRoot == nullptr)
        return *this;
    
    // End Check
    if (_curr->right() == nullptr) {
        Node *rootCheck = _curr;
        while (rootCheck->parent() != nullptr && rootCheck == rootCheck->parent()->right()) {
                rootCheck = rootCheck->parent();
        }
        if (rootCheck->parent() == nullptr) {   // We were at end, rootCheck is at root
            _unfinRoot = _curr;
            _curr = nullptr;

            return *this;
        }
    }

    if (_curr->left() == nullptr && _curr->right() == nullptr) {    // Leaf
        _curr = _unfinRoot;
    } else {                                // Not a Leaf
        if (_curr->right()) {                   // Right Child Exists
            _curr = _curr->right();                 // Go Right
            if (_curr->left()) {                    // Go Left if possible & as far as possible
                while (_curr->left() != nullptr) {
                    _curr = _curr->left();
                    _unfinRoot = _curr->parent();
                }
            } else {                            // Could Not Go Left
                if (_unfinRoot->parent() && _unfinRoot == _unfinRoot->parent()->left()) {
                    if (_curr->parent() == _unfinRoot)
                        _unfinRoot = _unfinRoot->parent();
                } else {
                    findNextSubroot();
                }
            }
        } else {                                // No Right Child
            if (_curr == _unfinRoot) {
                findNextSubroot();
                _curr = _unfinRoot;
            } else {
                _curr = _unfinRoot;
                findNextSubroot();
            }
        }
    }

    return *this;
}

template <typename T>
typename BST<T>::inorder_iterator BST<T>::inorder_iterator::operator++(int)
{
    inorder_iterator tmp = *this;
    ++(*this);

    return tmp;
}

template <typename T>
void BST<T>::inorder_iterator::findNextSubroot()
{
    if (_unfinRoot->key() > _curr->key())   // Do Nothing
        return;

    if (_unfinRoot->parent()) {     // The unfinished root is *not* THE root
        // _unfinRoot = _unfinRoot->parent();
        if (_unfinRoot->parent() && _unfinRoot->parent()->right() == _unfinRoot) {   // _unfinRoot is a right child
            while (_unfinRoot->parent() != nullptr && _unfinRoot == _unfinRoot->parent()->right()) {
                _unfinRoot = _unfinRoot->parent();
            }
            if (_unfinRoot->parent())
                _unfinRoot = _unfinRoot->parent();
        } else {
            _unfinRoot = _unfinRoot->parent();
        }
    } else {    // _unfinRoot is the root
        if (_unfinRoot->right()) {
            _unfinRoot = _unfinRoot->right();
            while (_unfinRoot->left()) {
                _unfinRoot = _unfinRoot->left();
            }
        }
    }
}