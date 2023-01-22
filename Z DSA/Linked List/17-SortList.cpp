#include <iostream>
using namespace std;

// https://leetcode.com/problems/sort-list/description/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insertAtHead(ListNode *&head, int data);
void printLinkedList(ListNode *head);

class Solution
{
private:
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (!left)
        {
            return right;
        }

        if (!right)
        {
            return left;
        }

        ListNode *temp = new ListNode(-1);
        ListNode *head = temp;

        while (left && right)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }

        if (!left)
        {
            while (right)
            {
                temp->next = right;
                temp = temp->next;
                right = right->next;
            }
        }

        if (!right)
        {
            while (left)
            {
                temp->next = left;
                temp = temp->next;
                left = left->next;
            }
        }

        return head->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        ListNode *ans = merge(left, right);

        return ans;
    }
};

int main()
{
    Solution s;

    ListNode *head = new ListNode(4);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 7);
    insertAtHead(head, 4);
    insertAtHead(head, 12);
    insertAtHead(head, 8);
    insertAtHead(head, 3);

    cout << "Linked List: " << endl;
    printLinkedList(head);

    head = s.sortList(head);

    cout << "Linked List after sorting: " << endl;
    printLinkedList(head);
    cout << endl;

    return 0;
}

void insertAtHead(ListNode *&head, int data)
{
    if (head == NULL)
    {
        ListNode *temp = new ListNode(data);
        head = temp;
        return;
    }

    ListNode *temp = new ListNode(data);
    temp->next = head;
    head = temp;
}

void printLinkedList(ListNode *head)
{
    if (head == NULL)
    {
        cout << "Lnked List is empty: " << endl;
    }

    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}