#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data) {}
};

class BST
{
private:
    Node *root;
    Node *insert_node(int _data, Node *node);

public:
    void insert(int _data);
    BST() : root(nullptr) {}
};

void BST::insert(int _data)
{
    if (root != nullptr)
    {
        Node *node = insert_node(_data, root);
        cout << "1 =  " << &(node) << endl;
    }
    else
    {
        root = new Node(_data);
        root->left = root->right = NULL;
        cout << "2 =  " << &(*root) << endl;
    }
}

Node *BST::insert_node(int _data, Node *node)
{
    cout << "3 = " << &(*node) << endl;
    if (node == nullptr)
    {
        node = new Node(_data);
    }
    else if (_data > node->data)
    {
        cout << "4 = " << &(node->right) << endl;
        //node->right=new Node(_data);
        node = insert_node(_data, node->right);
    }
    else
        node = insert_node(_data, node->left);
    return node;
}
int main()
{
    BST bst;
    bst.insert(0);
    bst.insert(5);
    bst.insert(6);
    bst.insert(4);
    bst.insert(3);
    bst.insert(4);  
    bst.insert(1);
    return 0;
}