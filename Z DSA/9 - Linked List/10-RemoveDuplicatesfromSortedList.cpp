#include <iostream>
using namespace std;

/*
Given the head of a sorted linked list, delete all duplicates such that each element
appears only once. Return the linked list sorted as well.
*/

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *temp = head;

        while (temp->next)
        {
            if (temp->val == temp->next->val)
            {
                ListNode *nextNext = temp->next->next;
                ListNode *nodeToDelete = temp->next;
                temp->next = nextNext;
                delete (nodeToDelete);
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};

int main()
{
    Solution s;

    ListNode *head = new ListNode(6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 1);

    cout << "Linked List: " << endl;
    printLinkedList(head);
    cout << endl;

    head = s.deleteDuplicates(head);

    cout << "Linked List after removing duplicates: " << endl;
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