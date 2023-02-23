#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertAtHead(ListNode *&head, int data);
void printLinkedList(ListNode *head);

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        if (head->next == NULL)
        {
            return NULL;
        }

        if (head->next == head)
        {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }

        return NULL;
    }
};

int main()
{
    Solution s;

    ListNode *head = new ListNode(6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Linked List: " << endl;
    printLinkedList(head);
    cout << endl;

    ListNode *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;

    ListNode *startCycleNode = s.detectCycle(head);

    if (startCycleNode == NULL)
    {
        cout << "Cycle Not Present" << endl;
    }
    else
    {
        cout << "Cycle present at " << startCycleNode->val << endl;
    }

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