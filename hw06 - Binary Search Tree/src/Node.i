
template <typename T>
BST<T>::Node::Node(T val)
    : _val(val)
    , _left(nullptr)
    , _right(nullptr)
    , _parent(nullptr)
{}

template <typename T>
typename BST<T>::Node* BST<T>::Node::left()
{
    return _left;
}

template <typename T>
typename BST<T>::Node* BST<T>::Node::right()
{
    return _right;
}

template <typename T>
typename BST<T>::Node* BST<T>::Node::parent()
{
    return _parent;
}

template <typename T>
void BST<T>::Node::setLeft(Node *node)
{
    _left = node;
}

template <typename T>
void BST<T>::Node::setRight(Node *node)
{
    _right = node;
}

template <typename T>
void BST<T>::Node::setParent(Node *node)
{
    _parent = node;
}

template <typename T>
T& BST<T>::Node::key()
{
    return _val;
}