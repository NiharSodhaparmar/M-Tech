#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data);
void printLinkedList(Node *head);

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    while (curr)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    if (oneHead->next)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main()
{

    Node *head = new Node(2);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);

    cout << "Linked List: " << endl;
    printLinkedList(head);
    cout << endl;

    head = sortList(head);

    cout << "Linked List after sorting: " << endl;
    printLinkedList(head);
    cout << endl;

    return 0;
}

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        return;
    }

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printLinkedList(Node *head)
{
    if (head == NULL)
    {
        cout << "Lnked List is empty: " << endl;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}