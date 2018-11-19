
// Default Ctor
template <typename T>
BST<T>::BST() : root(nullptr), size(0)
{}

// Parameterized Ctor
template <typename T>
BST<T>::BST(const T& value): root(new Node(value)), size(1)
{
}

// Copy Ctor
template <typename T>
BST<T>::BST(BST& copy)
{
    for (auto& value : copy) {
        insert(value);
    }
}

// Move Ctor
template <typename T>
BST<T>::BST(BST&& move)
{
    root = move.root;
    move.root = nullptr;
    size = move.size;
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
    return size() != 0;
}
// function min; l-value, throws underflow if empty
template <typename T>
T& BST<T>::min()
{
    return root->key();
}
// function min; read-only, throws underflow if empty
template <typename T>
T& BST<T>::min() const
{  
    return root;
}
// function max; l-value, throws underflow if empty
template <typename T>
T& BST<T>::max(T& val)
{
    if (root == nullptr)
        throw std::underflow_error("function empty can't be run as tree is empty");
    T data = root->val;
    T left = max(root->left);
    T right = max(root->right);
    if (left > data)
        data = left;
    if (right > data)
        data = right;
    return data;
}
// function max; read-only, throws underflow if empty
template <typename T>
T& BST<T>::max(T& val) const
{
    if (root == nullptr)
        throw std::underflow_error("function empty can't be run as tree is empty");
    T data = root->val;
    T left = max(root->left);
    T right = max(root->right);
    if (left > data)
        data = left;
    if (right > data)
        data = right;
    return data;
}

// function insert; does not throw exceptions
template<typename T>
void BST<T>::insert(T& key) const noexcept
{
    // while ()
    // if (key > root->key()){
    //     node->right = insert(node->right, key);
    // } else if (key < root->key()) {
    //     node->left = insert(node->left, key);
    // }
}


// function prbegin; pr = preorder
template <typename T>
typename BST<T>::preorder_iterator prbebin()
{
    return preorder_iterator(root);
}
// function prend
template <typename T>
typename BST<T>::inorder_iterator begin()
{
    return inorder_iterator(root);
}
template <typename T>
typename BST<T>::inorder_iterator end()
{
    auto head = inorder_iterator(root);
    for (auto i = 0; i < size; i++) {
        head++;
    }
    return head;
}
// function pobegin; po = postorder
template <typename T>
typename BST<T>::postorder_iterator pobegin()
{
    return postorder_iterator(root);
}
// function poend
template <typename T>
typename BST<T>::postorder_iterator poend()
{
    auto head = postorder_iterator(root);
    for (auto i = 0; i < size; i++) {
        head++;
    }
    return head;
}