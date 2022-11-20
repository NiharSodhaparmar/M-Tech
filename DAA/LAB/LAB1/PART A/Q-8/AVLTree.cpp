#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

Node *rightRotate(Node *a)
{
    Node *b = a->left;
    Node *bRight = b->right;

    b->right = a;
    a->left = bRight;

    b->height = max(height(b->left), height(b->right)) + 1;
    a->height = max(height(a->left), height(a->right)) + 1;

    return b;
}

Node *leftRotate(Node *a)
{
    Node *b = a->right;
    Node *bLeft = b->left;

    b->left = a;
    a->right = bLeft;

    b->height = max(height(b->left), height(b->right)) + 1;
    a->height = max(height(a->left), height(a->right)) + 1;

    return b;
}

int getBalance(Node *n)
{
    if (n == NULL)
        return 0;

    return height(n->left) - height(n->right);
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return new Node(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Equal keys not allowed
        return node;

    node->height = max(height(node->left), height(node->right)) + 1;

    int balance = getBalance(node);

    // LL case
    if (balance > 1 && data < node->left->data)
    {
        return rightRotate(node);
    }

    // RR Case
    if (balance < -1 && data > node->right->data)
    {
        return leftRotate(node);
    }

    // LR Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
            30
            / \
           20  40
          / \    \
        10   25  50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    return 0;
}