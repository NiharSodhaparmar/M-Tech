#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void buildTreeFromLevelOrderTraversal(Node *&root)
{
    int data;
    queue<Node *> q;
    cout << "Enter data for root: " << endl;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left node data for " << temp->data << endl;
        cin >> data;

        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter right node data for " << temp->data << endl;
        cin >> data;

        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
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
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root = buildTree(root);

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildTreeFromLevelOrderTraversal(root);

    cout << endl;
    cout << "Levelorder traversal: " << endl;
    levelOrderTraversal(root);

    cout << endl;
    cout << "Inorder traversal: " << endl;
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Preorder traversal: " << endl;
    preOrder(root);
    cout << endl;

    cout << endl;
    cout << "Postorder traversal: " << endl;
    postOrder(root);
    cout << endl;

    cout << endl;
}