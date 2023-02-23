#include <iostream>
using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/

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
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == NULL && list2 == NULL)
            return NULL;

        if (list2 == NULL)
            return list1;

        if (list1 == NULL)
            return list2;

        ListNode *head;

        if (list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        ListNode *curr = head;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (!list1)
        {
            curr->next = list2;
        }

        if (!list2)
        {
            curr->next = list1;
        }

        return head;
    }
};

int main()
{
    Solution s;

    ListNode *head1 = new ListNode(4);
    insertAtHead(head1, 2);
    insertAtHead(head1, 1);

    ListNode *head2 = new ListNode(4);
    insertAtHead(head2, 3);
    insertAtHead(head2, 1);

    cout << "Linked List1: " << endl;
    printLinkedList(head1);
    cout << endl;

    cout << "Linked List2: " << endl;
    printLinkedList(head2);
    cout << endl;

    ListNode *head = s.mergeTwoLists(head1, head2);

    cout << "Linked List after merging: " << endl;
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