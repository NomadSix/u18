// File Name: BST.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 6

// Default Ctor
template <typename T>
BST<T>::BST() 
    : root(nullptr)
{}

// Parameterized Ctor
template <typename T>
BST<T>::BST(const T& value)
    : root(new Node(value))
{}

// Copy Ctor
template <typename T>
BST<T>::BST(BST& copy)
{
    for (auto& value : copy)
        insert(value);
}

// Move Ctor
template <typename T>
BST<T>::BST(BST&& move)
{
    root = move.root;
    move.root = nullptr;
}

template <typename T>
BST<T>::~BST() 
{
    delete root;
}

// function empty; does not throw exceptions
template <typename T>
bool BST<T>::empty() const noexcept
{
    return root == nullptr;
}
// function min; l-value, throws underflow if empty
template <typename T>
T& BST<T>::min()
{
    if (empty())
        throw std::underflow_error("BST is empty");
    return *begin();
}
// function min; read-only, throws underflow if empty
template <typename T>
T& BST<T>::min() const
{  
    if (empty())
        throw std::underflow_error("BST is empty");
    return *begin();
}
// function max; l-value, throws underflow if empty
template <typename T>
T& BST<T>::max()
{
    if (empty())
        throw std::underflow_error("function empty can't be run as tree is empty");
    return *end();
}
// function max; read-only, throws underflow if empty
template <typename T>
T& BST<T>::max() const
{
    if (empty())
        throw std::underflow_error("function empty can't be run as tree is empty");
    return *end();
}

// recursive insert
template <typename T>
typename BST<T>::Node* BST<T>::rinsert(Node *node, T key) noexcept
{
    if (node == nullptr)
        return new Node(key);
    Node *temp = rinsert(key >= node->key() ? node->right() : node->left(), key);
    temp->setParent(node);
    if (key >= node->key())
        node->setRight(temp);
    else
        node->setLeft(temp);
    return node;
}

// function insert; does not throw exceptions
template<typename T>
void BST<T>::insert(T key) noexcept
{
    root = rinsert(root, key);
}


// function emplace; does not throw exceptions
template <typename T>
template <typename... Args>
void BST<T>::emplace(Args&&... args) noexcept
{
    T tmp = T(std::forward<Args>(args)...);
    return insert(tmp);
}
// function erase; takes a type T, throws invalid_argument if empty or cannot be found
template <typename T>
void BST<T>::erase(T key)
{
    eraseHelper(root, key);
}

template <typename T>
void BST<T>::eraseHelper(Node* node, T key) 
{
    if (!node)
        return;

    if (node->key() == key) {
        if (!node->left() && !node->right()) {
            if (node->parent()) {
                if (node->parent()->left() == node) {
                    node->parent()->setLeft(nullptr);
                } else if (node->parent()->right() == node) {
                    node->parent()->setRight(nullptr);
                }
            }
            free(node);
        } else {
            if (node->parent()) {
                if (node->left()) {
                    node->parent()->setLeft(node->left());
                    node->left()->setParent(node->parent());
                } else if (node->right()) {
                    node->parent()->setRight(node->right());
                    node->right()->setParent(node->parent());
                }
            } else {
                if (node->right() && node->left()) {
                    
                } else {
                    delete node;
                }
            }
        }
    } else {
        eraseHelper(node->left(), key);
        eraseHelper(node->right(), key);
    }
}

template <typename T>
typename BST<T>::Node* BST<T>::search(Node* node, T key) 
{
    if (node->key() == key)
        return node;
    search(node->left());
    search(node->right());
    return node;
}

// function clear; does not throw exceptions
template <typename T>
void BST<T>::clear() noexcept
{
    root->setLeft(nullptr);
    root->setRight(nullptr);
    root->setParent(nullptr);
    root = nullptr;
}

// copy assignment operator overload
template <typename T>
const BST<T>& BST<T>::operator =(BST<T>& copy)
{
    auto i = copy.begin();
    while (i != copy.end()) {
        insert(*i);
        i++;
    }
    return *this;
}
// move assignment operator overload
template <typename T>
BST<T>& BST<T>::operator =(BST<T>&& move)
{
    root = move.root;
    return *this;
}

template <typename T>
void BST<T>::walk(Node* node)
{
    if (node == nullptr)
        return;
    walk(node->left());
    _queue.push(node->key());
    walk(node->right());
}
template <typename T>
void BST<T>::prwalk(Node* node)
{
    if (node == nullptr)
        return;
    _queue.push(node->key());
    prwalk(node->left());
    prwalk(node->right());
}
template <typename T>
void BST<T>::powalk(Node* node)
{
    if (node == nullptr)
        return;
    powalk(node->left());
    powalk(node->right());
    _queue.push(node->key());
}

// function prbegin; pr = preorder
template <typename T>
typename BST<T>::preorder_iterator BST<T>::prbegin()
{
    prwalk(root);
    return preorder_iterator(_queue);
}

template <typename T>
typename BST<T>::preorder_iterator BST<T>::prend()
{
    prwalk(root);
    while (_queue.size() != 1)
        _queue.pop();
    return preorder_iterator(_queue);
}
// function prend
template <typename T>
typename BST<T>::inorder_iterator BST<T>::begin() const
{
    return inorder_iterator(Queue<T>());
}
// function prend
template <typename T>
typename BST<T>::inorder_iterator BST<T>::begin()
{
    walk(root);
    return inorder_iterator(_queue);
}
template <typename T>
typename BST<T>::inorder_iterator BST<T>::end()
{
    walk(root);
    while (_queue.size() != 1)
        _queue.pop();
    return inorder_iterator(_queue);
}
// template <typename T>
// typename BST<T>::inorder_iterator BST<T>::end() const
// {
//     return inorder_iterator(_queue);
// }
// function pobegin; po = postorder
template <typename T>
typename BST<T>::postorder_iterator BST<T>::pobegin()
{
    powalk(root);
    return postorder_iterator(_queue);
}
// function poend
template <typename T>
typename BST<T>::postorder_iterator BST<T>::poend()
{
    powalk(root);
    while (_queue.size() != 1)
        _queue.pop();
    return postorder_iterator(_queue);
}