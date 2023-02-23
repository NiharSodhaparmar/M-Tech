#include <iostream>
#include <queue>
using namespace std;

// https://leetcode.com/problems/balanced-binary-tree/description/

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
private:
    pair<bool, int> checkBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return make_pair(true, 0);
        }

        pair<bool, int> left = checkBalanced(root->left);
        pair<bool, int> right = checkBalanced(root->right);

        bool checkHeight = abs(left.second - right.second) <= 1;
        int height = max(left.second, right.second) + 1;

        if (left.first && right.first && checkHeight)
        {
            return make_pair(true, height);
        }
        else
        {
            return make_pair(false, height);
        }
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return checkBalanced(root).first;
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
    TreeNode *root;
    Solution s;

    // 3 9 20 -1 -1 15 7 -1 -1 -1 -1
    // 1 2 2 3 3 -1 -1 4 4 -1 -1 -1 -1 -1 -1
    buildTreeFromLevelOrderTraversal(root);

    cout << endl;
    cout << "Is Tree balanced?: " << (s.isBalanced(root) ? "True" : "False") << endl;
}