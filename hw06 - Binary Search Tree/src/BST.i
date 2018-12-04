// File Name: BST.i
// Author: Devon Schimming
// Student ID: h865r773
// Assignment Number: 6

// Default Ctor
template <typename T>
BST<T>::BST() 
    : root(nullptr)
{
}

// Parameterized Ctor
template <typename T>
BST<T>::BST(const T& value)
    : root(new Node(value))
{
}

// Copy Ctor
template <typename T>
BST<T>::BST(BST& copy)
{
    // if (copy.root == nullptr)
    //     root = nullptr;
    // else
    //     copyTree(root, copy.root);
    // auto it = copy.begin();=
    // clear();
    root = copy.root;
    // for (auto i : copy) {
    //     insert(i);
    // }
}

template <typename T>
void BST<T>::copyTree(Node* curr, Node* sub)
{
    // if(sub == nullptr) {
    //     curr = nullptr;
    // } else {
    //     curr = new Node(sub->key());
    //     copyTree(curr->left(), sub->left());
    //     copyTree(curr->right(), sub->right());
    // }
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
    while (root->left() != nullptr)
        root = root->left();
    return root->key();
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
    while (root->right() != nullptr)
        root = root->right();
    return root->key();
}
// function max; read-only, throws underflow if empty
template <typename T>
T& BST<T>::max() const
{
    if (empty())
        throw std::underflow_error("function empty can't be run as tree is empty");
    return root->key();
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
    // Node* y = nullptr;
    // Node* x = root;
    // Node* z = new Node(key);
    // while (x != nullptr) {
    //     y = x;
    //     if (z->key() < x->key()) {
    //         x = x->left();
    //     } else {
    //         x = x->right();
    //     }
    // }
    // z->setParent(y);
    // if (y == nullptr)
    //     root = z;
    // else if (z->key() < y->key())
    //     y->setLeft(z);
    // else
    //     y->setRight(z);
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
    // Node* z = search(root, key);
    // if (z->left() == nullptr) {
    //     transplant(z, z->right());
    // } else if (z->right() == nullptr) {
    //     transplant(z, z->left());
    // } else {
    //     auto temp = min();
    //     Node* y = search(root, temp);
    //     if (y != z) {
    //         transplant(y, y->right());
    //         y->setRight(z->right());
    //         y->right()->setParent(y);
    //     }
    //     transplant(z,y);
    //     y->setLeft(z->left());
    //     y->left()->setParent(y);
    // }
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
void BST<T>::transplant(Node* curr, Node* sub)
{
    if (curr->parent() == nullptr) {
        root = sub;
    } else if (curr == curr->parent()->left()) {
        curr->parent()->setLeft(sub);
    } else {
        curr->parent()->setRight(curr);
    }
    if (sub == nullptr)
        sub->setParent(curr->parent());
}

template <typename T>
typename BST<T>::Node* BST<T>::search(Node* node, T key) 
{
    if (node == nullptr || key == node->key())
        return node;
    if (key < node->key())
        return search(node->left(), key);
    else
        return search(node->right(), key);
}

// function clear; does not throw exceptions
template <typename T>
void BST<T>::clear() noexcept
{
    // clearTree(root);
    clearTree(root);
    root = nullptr;
}

template <typename T>
void BST<T>::clearTree(Node* node)
{
    if (node == nullptr)
        return;
    clearTree(node->left());
    delete node;
    clearTree(node->right());
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
    _queue = Queue<T>();
    return preorder_iterator(Queue<T>(max()));
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
    _queue = Queue<T>();
    return inorder_iterator(Queue<T>(max()));
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
    _queue = Queue<T>();
    return postorder_iterator(Queue<T>(root->key()));
}