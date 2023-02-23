#include <iostream>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *merge(Node *left, Node *right)
{
    if (!left)
        return right;

    if (!right)
        return left;

    Node *temp = new Node(-1);
    Node *head = temp;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }

    if (!left)
    {
        temp->child = right;
        temp = right;
        right = right->child;
    }

    if (!right)
    {
        temp->child = left;
        temp = left;
        left = left->child;
    }

    return head->next;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *down = head;
    Node *right = head->next;
    down->next = NULL;

    right = flattenLinkedList(right);

    Node *ans = merge(down, right);
    return ans;
}