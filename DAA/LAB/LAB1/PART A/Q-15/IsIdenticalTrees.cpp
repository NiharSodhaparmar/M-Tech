#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data:" << endl;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for the left of " << data << ":" << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for the right of " << data << ":" << endl;
    root->right = buildTree(root->right);

    return root;
}

bool isIdenticalTree(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;

    bool op1 = isIdenticalTree(root1->left, root2->left);
    bool op2 = isIdenticalTree(root1->right, root2->right);
    bool op3 = root1->data == root2->data;

    if (op1 && op2 && op3)
        return true;
    else
        return false;
}

int main()
{
    Node *root1, *root2;

    // Binary Tree Data
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // First Binary Tree
    cout << "Enter data for first tree" << endl;
    root1 = buildTree(root1);

    // Second Binary Tree
    cout << endl;
    cout << "Enter data for second tree" << endl;
    root2 = buildTree(root1);

    auto start = high_resolution_clock::now();

    // Check two tree is identical or not
    bool isIdentical = isIdenticalTree(root1, root2);

    auto end = high_resolution_clock::now();

    cout << endl;
    if (isIdentical)
        cout << "Two trees are identical" << endl;
    else
        cout << "Two trees are not identical" << endl;

    cout << endl;

    cout << "Time taken" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
    return 0;
}