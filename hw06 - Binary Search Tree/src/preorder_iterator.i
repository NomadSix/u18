template<typename T>
BST<T>::preorder_iterator::preorder_iterator(Queue<T> que)
    : _queue(que)
{}

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

    // // Check if empty
    // if (_curr == nullptr && _unfinRoot == nullptr)
    //     return *this;
            
    // // End Check
    // if (_curr->right() == nullptr) {
    //     Node *rootCheck = _curr;
    //     while (rootCheck->parent() != nullptr && rootCheck == rootCheck->parent()->right()) {
    //             rootCheck = rootCheck->parent();
    //     }
    //     if (rootCheck->parent() == nullptr) {   // We were at end, rootCheck is at root
    //         _unfinRoot = _curr;
    //         _curr = nullptr;

    //         return *this;
    //     }
    // }

    // if (_curr->left() == nullptr && _curr->right() == nullptr) {
    //     if (_curr->parent()) {
    //         if (_curr != _curr->parent()->right()) {
    //             while (_unfinRoot->right() == nullptr) {
    //                 _unfinRoot = _unfinRoot->parent();
    //             }
    //             _curr = _unfinRoot->right(); 
    //         } else {
    //             // findNextSubroot();
    //             // _curr = _unfinRoot->right();
    //             _unfinRoot = _unfinRoot->parent();
    //             if (_unfinRoot->parent()) {
    //                 _curr = _unfinRoot;
    //                 _unfinRoot = _curr->parent();
    //                 // findNextSubroot();
    //                 while (_unfinRoot->right() == nullptr) {
    //                     // _curr = _unfinRoot->parent();
    //                     _unfinRoot = _curr->parent();
    //                 }
    //                 if (_unfinRoot->right()) {
    //                     _curr = _unfinRoot->right();
    //                 }
    //             } else {
    //                 findNextSubroot();
    //                 _curr = _unfinRoot->right();
    //             }
    //         }
    //     } else {
    //         _curr = _unfinRoot;
    //     }
        
    //     // findNextSubroot();
    //     // _curr =_unfinRoot;
    // } else {
    //     if (_curr->left()) { // go left
    //         _curr = _curr->left();
    //         _unfinRoot = _curr->parent();
    //     } else { // cant go left
    //         if (_curr->right()) {
    //             _curr = _curr->right();
    //             _unfinRoot = _curr->parent();
    //         }
    //         if (_unfinRoot->parent() && _unfinRoot == _unfinRoot->parent()->left()) {
    //             if (_curr->parent() == _unfinRoot)
    //                 _unfinRoot = _unfinRoot->parent();
    //         } else {
    //             findNextSubroot();
    //             if (_curr->left() == nullptr && _curr->right()) {
    //                 _curr = _curr->right();
    //                 _unfinRoot = _curr->parent();
    //             }
    //         }
    //     }
    // }
    // return *this;
}

template <typename T>
typename BST<T>::preorder_iterator BST<T>::preorder_iterator::operator++(int)
{
    preorder_iterator tmp = *this;
    ++(*this);

    return tmp;
}
