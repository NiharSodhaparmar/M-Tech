#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    int lCount;
    int rCount;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
        this->rCount = 0;
        this->lCount = 0;
    }
};

int height(Node *N);
int getLCount(Node *N);
int getRCount(Node *N);
int getBalance(Node *N);
Node *rightRotate(Node *y);
Node *leftRotate(Node *x);
Node *minValueNode(Node *root);
Node *deleteNodeWithKey(Node *root, int key);
void inOrder(Node *root);
Node *insert(Node *root, int key);
pair<Node *, int> deleteKthSmallestElement(Node *root, int k);
bool searchInAVL(Node *root, int key);
void levelOrderTraversal(Node *root);

int main()
{
    Node *root = NULL;

    root = insert(root, 25);
    root = insert(root, 27);
    root = insert(root, 40);
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 13);
    root = insert(root, 29);
    root = insert(root, 17);
    root = insert(root, 15);
    root = insert(root, 11);
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 6);

    cout << "Inorder traversal of the tree : " << endl;
    inOrder(root);
    cout << endl
         << endl;

    cout << "Level traversal of the tree : " << endl;
    levelOrderTraversal(root);
    cout << endl
         << endl;

    vector<int> deleteNodes = {1, 1, 4, 6, 1, 2, 2, 1, 1};

    for (int i = 0; i < deleteNodes.size(); i++)
    {
        int index = deleteNodes[i];
        pair<Node *, int> a = deleteKthSmallestElement(root, index);
        root = a.first;
        int deletedElement = a.second;

        cout << "Inorder traversal of the tree after deleting " << index << "th smallest element (" << deletedElement << ") : " << endl;
        inOrder(root);
        cout << endl
             << endl;

        cout << index << " smallest element (" << deletedElement << ") is present in tree? " << searchInAVL(root, deletedElement) << endl
             << endl;
    }

    return 0;
}

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getLCount(Node *N)
{
    if (N == NULL)
        return 0;

    return N->lCount;
}
int getRCount(Node *N)
{
    if (N == NULL)
        return 0;

    return N->rCount;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    if (T2 == NULL)
        y->lCount = 0;
    else
        y->lCount = getLCount(T2) + getRCount(T2) + 1;

    x->rCount = getLCount(y) + getRCount(y) + 1;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    if (T2 == NULL)
        x->rCount = 0;
    else
        x->rCount = getLCount(T2) + getRCount(T2) + 1;

    y->lCount = getLCount(x) + getRCount(x) + 1;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *root, int key)
{
    // Perform normal BST insertion.
    if (root == NULL)
    {
        Node *tmp = new Node(key);
        return (tmp);
    }

    if (key < root->data)
    {
        root->left = insert(root->left, key);
        root->lCount = root->lCount + 1;
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
        root->rCount = root->rCount + 1;
    }
    else
        return root;

    // Update height of this ancestor Node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of this ancestor Node to check whether this Node became unbalanced
    int balance = getBalance(root);

    // LL Case
    if ((balance > 1) && (key < root->left->data))
        return rightRotate(root);

    // RR Case
    if ((balance < -1) && (key > root->right->data))
        return leftRotate(root);

    // LR Case
    if ((balance > 1) && (key > root->left->data))
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case --> right rotate
    if ((balance < -1) && (key < root->right->data))
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << "data : " << root->data << "\tlCount : " << root->lCount << "\trCount : " << root->rCount << endl;
        inOrder(root->right);
    }
}

Node *deleteNodeWithKey(Node *root, int key)
{
    // STEP 1 : DELETE AS BST.
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNodeWithKey(root->left, key);
        root->lCount--;
    }
    else if (key > root->data)
    {
        root->right = deleteNodeWithKey(root->right, key);
        root->rCount--;
    }

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *tmp = root->left ? root->left : root->right;

            if (tmp == NULL)
            {
                tmp = root;
                root = NULL;
            }
            else
            {
                *root = *tmp;
                root->rCount = 0;
                root->lCount = 0;
            }
            free(tmp);
        }
        else
        {
            Node *tmp = minValueNode(root->right);
            root->data = tmp->data;
            root->right = deleteNodeWithKey(root->right, tmp->data);
            root->rCount--;
        }
    }

    if (root == NULL)
        return root;

    // STEP 1.1 : UPDATE HEIGHT.
    root->height = max(height(root->left), height(root->right)) + 1;

    // STEP 2 : GET BALANCE FACTOR.
    int balance = getBalance(root);

    // STEP 3 : MAINTAIN BALANCE FACTOR

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *minValueNode(Node *root)
{
    Node *tmp = root;

    while (tmp->left)
    {
        tmp = tmp->left;
    }

    return tmp;
}

Node *getKthSmalletElement(Node *root, int k)
{
    if (root == NULL)
        return NULL;

    int count = root->lCount + 1;

    if (count == k)
        return root;

    if (k < count)
        return getKthSmalletElement(root->left, k);
    else
        return getKthSmalletElement(root->right, k - count);
}

pair<Node *, int> deleteKthSmallestElement(Node *root, int k)
{
    Node *tmp = getKthSmalletElement(root, k);

    if (tmp == NULL)
    {
        cout << "Key not founded." << endl;
        pair<Node *, int> a;
        a.first = NULL;
        a.second = INT_MAX;
        return a;
    }

    int key = tmp->data;
    Node *ans = deleteNodeWithKey(root, key);
    pair<Node *, int> a;
    a.first = ans;
    a.second = key;
    return a;
}

bool searchInAVL(Node *root, int key)
{
    if (root == NULL)
        return false;

    if (key == root->data)
        return true;
    else if (key < root->data)
        return searchInAVL(root->left, key);
    else
        return searchInAVL(root->right, key);
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