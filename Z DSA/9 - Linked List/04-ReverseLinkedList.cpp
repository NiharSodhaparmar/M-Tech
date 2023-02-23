#include <iostream>
using namespace std;

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
    ListNode *reverseList(ListNode *head)
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
};

int main()
{
    Solution s;

    ListNode *head = new ListNode(10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);
    insertAtHead(head, 60);
    printLinkedList(head);
    cout << endl;

    ListNode *reverseHead = s.reverseList(head);
    printLinkedList(reverseHead);

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