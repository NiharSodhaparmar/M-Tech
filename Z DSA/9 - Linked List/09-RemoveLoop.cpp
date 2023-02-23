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

Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

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

        Node *temp = slow->next;

        while (temp->next != slow)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }

    return head;
}

int main()
{

    Node *head = new Node(6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "Linked List: " << endl;
    printLinkedList(head);
    cout << endl;

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;

    head = removeLoop(head);

    cout << "Linked List After removing loop: " << endl;
    printLinkedList(head);

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