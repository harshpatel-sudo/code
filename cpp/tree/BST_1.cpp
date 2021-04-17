Node* BST::insert_node(int _data, Node *node)
{
    if (node == nullptr)
        {
            node = new Node(_data);
            cout << "added  -" << _data << endl;
        }
    else if (_data > node->data)
    {
        if(node->right == nullptr)
        {
            Node *rightNode = new Node(_data);
            rightNode->right = nullptr;
            rightNode->left = nullptr;
            node->right = rightNode;
            cout << "added right of-" << node->data << endl;
            return rightNode;
        }
        cout << "going right of-" << node->data << endl;
        node = insert_node(_data, node->right);
    }

    else
    {
        if(node->left == nullptr)
        {
            Node *leftNode = new Node(_data);
            leftNode->right = nullptr;
            leftNode->left = nullptr;
            node->left = leftNode;
            cout << "added left of-" << node->data << endl;
            return leftNode;
        }
        cout << "going left of-" << node->data << endl;
        node = insert_node(_data, node->left);
    }

    return node;
}