#include <iostream>
#include <queue>
using namespace std;

// https://leetcode.com/problems/same-tree/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }

        if (p == NULL && q != NULL)
        {
            return false;
        }

        if (p != NULL && q == NULL)
        {
            return false;
        }

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        bool value = p->val == q->val;

        if (left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void buildTreeFromLevelOrderTraversal(TreeNode *&root)
{
    int data;
    queue<TreeNode *> q;
    cout << "Enter data for root: " << endl;
    cin >> data;
    root = new TreeNode(data);
    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        cout << "Enter left node data for " << temp->val << endl;
        cin >> data;

        if (data != -1)
        {
            temp->left = new TreeNode(data);
            q.push(temp->left);
        }

        cout << "Enter right node data for " << temp->val << endl;
        cin >> data;

        if (data != -1)
        {
            temp->right = new TreeNode(data);
            q.push(temp->right);
        }
    }
}

int main()
{
    TreeNode *root1;
    TreeNode *root2;
    Solution s;

    // 1 2 3 -1 -1 -1 -1
    buildTreeFromLevelOrderTraversal(root1);

    // 1 2 3 -1 -1 -1 -1
    buildTreeFromLevelOrderTraversal(root2);

    cout << endl;
    cout << "Is Tree Same?: " << (s.isSameTree(root1, root2) ? "True" : "False") << endl;
}