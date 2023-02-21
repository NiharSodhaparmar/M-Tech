#include <iostream>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inOrder(BinaryTreeNode<int> *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inOrder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int count = 0;
    inOrder(root, count);
    return count;
}