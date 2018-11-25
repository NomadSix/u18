
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
bool BST<T>::empty() noexcept
{
    return root == nullptr;
}
// function min; l-value, throws underflow if empty
template <typename T>
T& BST<T>::min()
{
    if (empty())
        throw std::underflow_error("BST is empty");
    return root->key();
}
// function min; read-only, throws underflow if empty
template <typename T>
T& BST<T>::min() const
{  
    if (empty())
        throw std::underflow_error("BST is empty");
    return root;
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
    if (empty())
        throw std::invalid_argument("Tree is empty");
    auto i = begin();
    while (*i)
        i++;
    if (*i)
        throw std::invalid_argument("Value can't be found");
    *i = NULL;
}

// function clear; does not throw exceptions
template <typename T>
void BST<T>::clear() noexcept
{

}

// copy assignment operator overload
template <typename T>
const BST<T>& BST<T>::operator =(BST<T>&)
{

}
// move assignment operator overload
template <typename T>
BST<T>& BST<T>::operator =(BST<T>&&)
{

}


// function prbegin; pr = preorder
template <typename T>
typename BST<T>::preorder_iterator BST<T>::prbebin()
{
    return preorder_iterator(root, nullptr);
}
// function prend
template <typename T>
typename BST<T>::inorder_iterator BST<T>::begin()
{
    while (root->left() != nullptr)
        root = root->left();
    return inorder_iterator(root, root->parent());
}
template <typename T>
typename BST<T>::inorder_iterator BST<T>::end()
{
    while (root->parent() != nullptr)
        root = root->parent();
    while (root->right() != nullptr)
        root = root->right();
    return inorder_iterator(root, root->parent());
}
// function pobegin; po = postorder
template <typename T>
typename BST<T>::postorder_iterator BST<T>::pobegin()
{
    while (root->left() != nullptr)
        root = root->left();
    return postorder_iterator(root, root->parent());
}
// function poend
template <typename T>
typename BST<T>::postorder_iterator BST<T>::poend()
{
    return postorder_iterator(root, nullptr);
}