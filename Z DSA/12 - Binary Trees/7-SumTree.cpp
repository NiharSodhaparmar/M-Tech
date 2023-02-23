#include <iostream>
#include <queue>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sum-tree/1

struct Node
{
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution
{
private:
    pair<bool, int> checkSumTree(Node *root)
    {
        if (root == NULL)
        {
            return make_pair(true, 0);
        }

        if (root->left == NULL && root->right == NULL)
        {
            return make_pair(true, root->data);
        }

        pair<bool, int> left = checkSumTree(root->left);
        pair<bool, int> right = checkSumTree(root->right);

        bool checkRoot = (root->data == (left.second + right.second));

        pair<int, int> ans;
        ans.second = root->data + left.second + right.second;

        if (left.first && right.first && checkRoot)
        {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }

        return ans;
    }

public:
    bool isSumTree(Node *root)
    {
        return checkSumTree(root).first;
    }
};

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

int main()
{
    Node *root;
    Solution s;

    // 3 1 2 -1 -1 -1 -1
    // 10 20 30 10 10 -1 -1 -1 -1 -1 -1
    buildTreeFromLevelOrderTraversal(root);

    cout << endl;
    cout << "Is Sum Tree?: " << (s.isSumTree(root) ? "True" : "False") << endl;
}