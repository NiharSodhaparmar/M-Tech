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

bool isCircularApproach1(Node *head)
{
    if (head == NULL)
        return true;

    Node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return false;

    return true;
}

bool isCircularApproach2(Node *head)
{
    if (head == NULL)
        return true;

    if (head->next == NULL)
    {
        return false;
    }

    if (head->next == head)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow == fast)
    {
        return true;
    }

    return false;
}

void insertAtHead(Node *&head, int data);
void printLinkedList(Node *head);

int main()
{
    Node *head = new Node(6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printLinkedList(head);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;

    cout << "Is Linked List is circular(approach1)? : " << isCircularApproach1(head) << endl;
    cout << "Is Linked List is circular(approach2)? : " << isCircularApproach2(head) << endl;
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