#include <iostream>
#include <queue>
using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    pair<int, int> diameter(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        // if diameter in left subtree
        pair<int, int> left = diameter(root->left);

        // if diameter in right subtree
        pair<int, int> right = diameter(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return diameter(root).first - 1;
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

void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
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
            cout << temp->val << " ";

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

int main()
{
    TreeNode *root;
    Solution s;

    // 1 2 3 4 5 -1 -1 -1 -1 -1 -1
    buildTreeFromLevelOrderTraversal(root);

    cout << endl;
    cout << "Level order traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << endl;
    cout << "Max depth of binary tree is: " << s.diameterOfBinaryTree(root) << endl;
}