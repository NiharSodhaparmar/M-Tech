#include <bits/stdc++.h>
using namespace std;

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

Node *buildTree(Node *root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in the right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // Level completed
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void reverseOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    stack<Node *> s;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
                s.push(NULL);
            }
        }
        else
        {
            s.push(temp);

            if (temp->right)
                q.push(temp->right);

            if (temp->left)
                q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        Node *temp = s.top();
        if (temp == NULL)
            cout << endl;
        else
            cout << temp->data << " ";
        s.pop();
    }
}

void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
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

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

Node *buildTreeFromLevelOrder(Node *root)
{
    int data;
    cout << "Enter data for root: " << endl;
    cin >> data;

    root = new Node(data);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter left data for node " << temp->data << " : " << endl;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter right data for node " << temp->data << " : " << endl;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }

    return root;
}

int main()
{
    Node *root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // creating a tree
    // root = buildTree(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    root = buildTreeFromLevelOrder(root);

    cout << endl;
    cout << "Level order traversal of tree" << endl;
    levelOrderTraversal(root);

    cout << endl;
    cout << "Reverse Level order traversal of tree" << endl;
    reverseOrderTraversal(root);

    cout << endl;
    cout << endl;
    cout << "Inorder traversal of tree:" << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << endl;
    cout << "Preorder traversal of tree:" << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << endl;
    cout << "Postorder traversal of tree:" << endl;
    postOrderTraversal(root);
    cout << endl;

    cout << endl;
    return 0;
}