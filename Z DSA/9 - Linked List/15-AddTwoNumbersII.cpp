#include <iostream>
using namespace std;

// https://leetcode.com/problems/add-two-numbers-ii/

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
    ListNode *reverse(ListNode *head)
    {
        ListNode *nextNode, *prevNode = NULL;

        while (head)
        {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }

        return prevNode;
    }

    ListNode *add(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
        {
            return NULL;
        }
        else if (!l1)
        {
            return l2;
        }
        else if (!l2)
        {
            return l1;
        }

        ListNode *l = new ListNode(-1);
        ListNode *head = l;
        int carry = 0;

        while (l1 && l2)
        {
            int value = l1->val + l2->val + carry;
            carry = value / 10;
            value = value % 10;
            l->next = new ListNode(value);
            l = l->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (!l2)
        {
            while (l1)
            {
                int value = l1->val + carry;
                carry = value / 10;
                value = value % 10;
                l->next = new ListNode(value);
                l = l->next;
                l1 = l1->next;
            }
        }

        if (!l1)
        {
            while (l2)
            {
                int value = l2->val + carry;
                carry = value / 10;
                value = value % 10;
                l->next = new ListNode(value);
                l = l->next;
                l2 = l2->next;
            }
        }

        if (carry)
        {
            l->next = new ListNode(carry);
        }

        return head->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode *head = add(l1, l2);
        return reverse(head);
    }
};

int main()
{
    Solution s;

    ListNode *head1 = new ListNode(3);
    insertAtHead(head1, 4);
    insertAtHead(head1, 2);
    insertAtHead(head1, 7);

    ListNode *head2 = new ListNode(4);
    insertAtHead(head2, 6);
    insertAtHead(head2, 5);

    cout << "Linked List1: " << endl;
    printLinkedList(head1);
    cout << endl;

    cout << "Linked List2: " << endl;
    printLinkedList(head2);
    cout << endl;

    ListNode *head = s.addTwoNumbers(head1, head2);

    cout << "Linked List after adding: " << endl;
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
        cout << "Lnked List is empty" << endl;
    }

    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}