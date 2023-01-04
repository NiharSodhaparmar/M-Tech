#include <bits/stdc++.h>
using namespace std;

enum Color
{
    RED,
    BLACK
};

class Node
{
public:
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data = data;
        left = right = parent = NULL;
        this->color = RED;
    }
};

// Insert as BST
Node *BSTInsert(Node *root, Node *pt)
{
    if (root == NULL)
        return pt;

    if (pt->data < root->data)
    {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    return root;
}

// Inorder Traversal
void inorderHelper(Node *root)
{
    if (root == NULL)
        return;

    inorderHelper(root->left);
    cout << root->data << " ";
    inorderHelper(root->right);
}

// Red-Black Tree Class
class RBTree
{
private:
    Node *root;

protected:
    // Rotate Left
    void rotateLeft(Node *&root, Node *&pt)
    {
        Node *pt_right = pt->right;

        pt->right = pt_right->left;

        if (pt->right != NULL)
            pt->right->parent = pt;

        pt_right->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_right;

        else if (pt == pt->parent->left)
            pt->parent->left = pt_right;

        else
            pt->parent->right = pt_right;

        pt_right->left = pt;
        pt->parent = pt_right;
    };

    // Rotate Right
    void rotateRight(Node *&root, Node *&pt)
    {
        Node *pt_left = pt->left;

        pt->left = pt_left->right;

        if (pt->left != NULL)
            pt->left->parent = pt;

        pt_left->parent = pt->parent;

        if (pt->parent == NULL)
            root = pt_left;

        else if (pt == pt->parent->left)
            pt->parent->left = pt_left;

        else
            pt->parent->right = pt_left;

        pt_left->right = pt;
        pt->parent = pt_left;
    };

    // Fix violation after inserting node
    void fixViolation(Node *&root, Node *&pt)
    {
        Node *parent_pt = NULL;
        Node *grand_parent_pt = NULL;

        while ((pt != root) && (pt->color != BLACK) &&
               (pt->parent->color == RED))
        {

            parent_pt = pt->parent;
            grand_parent_pt = pt->parent->parent;

            /* Case : A
                Parent of pt is left child
                of Grand-parent of pt */
            if (parent_pt == grand_parent_pt->left)
            {

                Node *uncle_pt = grand_parent_pt->right;

                /* Case : 1
                The uncle of pt is also red
                Only Recoloring required */
                if (uncle_pt != NULL && uncle_pt->color ==
                                            RED)
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }

                else
                {
                    /* Case : 2
                    pt is right child of its parent
                    Left-rotation required */
                    if (pt == parent_pt->right)
                    {
                        rotateLeft(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    /* Case : 3
                    pt is left child of its parent
                    Right-rotation required */
                    rotateRight(root, grand_parent_pt);
                    swap(parent_pt->color,
                         grand_parent_pt->color);
                    pt = parent_pt;
                }
            }

            /* Case : B
            Parent of pt is right child
            of Grand-parent of pt */
            else
            {
                Node *uncle_pt = grand_parent_pt->left;

                /* Case : 1
                    The uncle of pt is also red
                    Only Recoloring required */
                if ((uncle_pt != NULL) && (uncle_pt->color ==
                                           RED))
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    /* Case : 2
                    pt is left child of its parent
                    Right-rotation required */
                    if (pt == parent_pt->left)
                    {
                        rotateRight(root, parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    /* Case : 3
                    pt is right child of its parent
                    Left-rotation required */
                    rotateLeft(root, grand_parent_pt);
                    swap(parent_pt->color,
                         grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }

        root->color = BLACK;
    };

public:
    // Constructor
    RBTree() { root = NULL; }

    // RB Insert
    void insert(const int &data)
    {
        Node *pt = new Node(data);

        root = BSTInsert(root, pt);

        fixViolation(root, pt);
    };

    // Inorder Traversal
    void inorder() { inorderHelper(root); };
};

int main()
{
    RBTree tree;

    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    cout << "Inorder Traversal of Created Tree\n";
    tree.inorder();

    return 0;
}
