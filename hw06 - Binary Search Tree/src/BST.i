
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
    // if (empty())
    //     throw std::invalid_argument("Tree is empty");
    // auto i = begin();
    // while (*i != key)
    //     i++;
    // // if (*i)
    // //     throw std::invalid_argument("Value can't be found");
    // // delete *i;?
    eraseHelper(root, key);
}

template <typename T>
typename BST<T>::Node* BST<T>::eraseHelper(Node* node, T key) 
{
    if (!node)
        throw std::invalid_argument("Tree is empty");
    
    if (key < node->key()) {
        node->setLeft(eraseHelper(node->left(), key));
    } else if (key > node->key()) {
        node->setRight(eraseHelper(node->right(), key));
    } else {
        if (node->right() && node->left()) {    
            Node *temp = root;  //Find the last element
            while (temp->right()) {
                temp = temp->right();
            }
            node->key() = temp->key();
            node->setLeft(eraseHelper(node->left(), temp->key()));
        } else {
            Node* temp = node;
            if (node->left() == NULL)
                temp = node->right();
            if (node->right() == NULL)
                temp = node->left();
            free(node);
            return temp;
        }
    }
    return node;
}

// function clear; does not throw exceptions
template <typename T>
void BST<T>::clear() noexcept
{

}

// copy assignment operator overload
template <typename T>
const BST<T>& BST<T>::operator =(BST<T>& copy)
{
    if (begin() != copy.begin()) {
        auto i = copy.begin();
        while (*i != 0) {
            root->insert(*i);
            i++;
        }
    }
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
    // while (root->parent() != nullptr)
    //     root = root->parent();
    // while (root->right() != nullptr)
    //     root = root->right();
    return preorder_iterator(nullptr);
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
    powalk(root);
    return postorder_iterator(_queue);
}
// function poend
template <typename T>
typename BST<T>::postorder_iterator BST<T>::poend()
{
    return postorder_iterator(nullptr);
}