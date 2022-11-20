#include <iostream>
#include <chrono>
using namespace std;
using namespace std ::chrono;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrderTraversal(Node *root);
int getLevel(Node *root);
int max(int a, int b);

int main()
{
    // Level 0
    Node *root = NULL;

    auto start = high_resolution_clock::now();
    int level = getLevel(root);
    auto end = high_resolution_clock::now();

    cout << "Level Of Tree: " << endl;
    cout << level << endl;

    cout << "Time taken to find level of a tree : " << duration_cast<nanoseconds>(end - start).count() << " nanosecond" << endl;
    cout << endl;

    // Level 1
    root = new Node(1);

    start = high_resolution_clock::now();
    level = getLevel(root);
    end = high_resolution_clock::now();

    cout << "Level Of Tree: " << endl;
    cout << level << endl;

    cout << "Time taken to find level of a tree : " << duration_cast<nanoseconds>(end - start).count() << " nanosecond" << endl;
    cout << endl;

    // Level 2
    root->left = new Node(2);
    root->right = new Node(3);

    start = high_resolution_clock::now();
    level = getLevel(root);
    end = high_resolution_clock::now();

    cout << "Level Of Tree: " << endl;
    cout << level << endl;

    cout << "Time taken to find level of a tree : " << duration_cast<nanoseconds>(end - start).count() << " nanosecond" << endl;
    cout << endl;

    // Level 3
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // cout << endl;
    // cout << "Pre traversal of tree:" << endl;
    // preOrderTraversal(root);
    // cout << endl;

    start = high_resolution_clock::now();
    level = getLevel(root);
    end = high_resolution_clock::now();

    cout << "Level Of Tree: " << endl;
    cout << level << endl;

    cout << "Time taken to find level of a tree : " << duration_cast<nanoseconds>(end - start).count() << " nanosecond" << endl;
    cout << endl;
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int getLevel(Node *root)
{
    if (root == NULL)
        return 0;

    int leftTreeLevel = getLevel(root->left);
    int rightTreeLevel = getLevel(root->right);

    return (1 + max(leftTreeLevel, rightTreeLevel));
}

int max(int a, int b)
{
    return a > b ? a : b;
}