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
    int getLengthOfLinkedList(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }

        // step 1: reverse k nodes
        ListNode *currNode = head;
        ListNode *nextNode, *prevNode = NULL;
        int count = 0;

        while (count < k && currNode != NULL)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
            count++;
        }

        // step 2: recursion dekh lega
        int length = getLengthOfLinkedList(nextNode);

        if (nextNode != NULL && length >= k)
        {
            head->next = reverseKGroup(nextNode, k);
        }
        else
        {
            head->next = nextNode;
        }

        // step3: return head of reversed list
        return prevNode;
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
    printLinkedList(head);
    cout << endl;

    int k = 4;
    ListNode *reversedHead = s.reverseKGroup(head, k);
    cout << "Reverse Linked List with " << k << " groups:" << endl;
    printLinkedList(reversedHead);
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