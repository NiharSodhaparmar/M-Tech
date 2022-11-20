#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BSTInsert(Node *root, int data);
Node *getMinimumNode(Node *root);
Node *concatenate(Node *root1, Node *root2);
void inorder(Node *root);

int main()
{
    // ifstream input("../SortedDataset10power5.txt");
    // string line;

    vector<int> bst1data = {4, 3, 2, 7, 8, 1, 6};
    vector<int> bst2data = {12, 10, 9, 11, 13};

    // int number = 50000;
    // int count = 0;
    // while (getline(input, line))
    // {
    //     if (count < number)
    //     {
    //         bst1data.push_back(stoi(line));
    //     }
    //     else
    //     {
    //         bst2data.push_back(stoi(line));
    //     }
    // }

    Node *root1, *root2;

    for (int i = 0; i < bst1data.size(); i++)
    {
        root1 = BSTInsert(root1, bst1data[i]);
    }

    for (int i = 0; i < bst2data.size(); i++)
    {
        root2 = BSTInsert(root2, bst2data[i]);
    }

    root2 = concatenate(root1, root2);

    cout << "Inorder traversal of cocatenated BST:" << endl;
    inorder(root2);
}

Node *BSTInsert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->left = BSTInsert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = BSTInsert(root->right, data);
    }

    return root;
}

Node *getMinimumNode(Node *root)
{
    if (root->left == NULL)
        return root;

    return getMinimumNode(root->left);
}

Node *concatenate(Node *root1, Node *root2)
{
    Node *minNode = getMinimumNode(root2);
    minNode->left = root1;
    return root2;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}