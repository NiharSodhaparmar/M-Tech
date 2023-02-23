#include <iostream>
#include <queue>
using namespace std;

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
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
    // 2 -1 1 3 -1 -1 -1
    // 1 2 3 4 5 -1 6 -1 -1 7 -1 9 -1 8 -1 -1 -1 -1 -1
    buildTreeFromLevelOrderTraversal(root);

    cout << endl;
    cout << "Max depth of binary tree is: " << s.maxDepth(root) << endl;
}