#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, Node *&tail, int data);
void insertAtTail(Node *&head, Node *&tail, int data);
void inserAtPosition(Node *&head, Node *&tail, int position, int data);
void deleteAtPosition(Node *&head, Node *&tail, int position);
void printLinkedList(Node *head);

int main()
{
    Node *node1 = new Node(10);

    Node *head = node1;
    Node *tail = node1;

    cout << "Print after creating first node: " << endl;
    printLinkedList(head);

    cout << "Print after inserting at head: " << endl;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    printLinkedList(head);

    cout << "Print after inserting at tail: " << endl;
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 1);
    printLinkedList(head);

    cout << "Print after inserting at 4th position: " << endl;
    inserAtPosition(head, tail, 4, 9);
    printLinkedList(head);

    cout << "Print after inserting at 1st position: " << endl;
    inserAtPosition(head, tail, 1, 60);
    printLinkedList(head);

    cout << "Print after inserting at 8th position: " << endl;
    inserAtPosition(head, tail, 8, 0);
    printLinkedList(head);

    cout << "Check for head and tail: " << endl;
    cout << "\thead: " << head->data << endl;
    cout << "\ttail: " << tail->data << endl;

    cout << "Print after deleting at 1st position: " << endl;
    deleteAtPosition(head, tail, 1);
    printLinkedList(head);

    cout << "Print after deleting at 6th position: " << endl;
    deleteAtPosition(head, tail, 6);
    printLinkedList(head);

    cout << "Print after deleting at 6th(last) position: " << endl;
    deleteAtPosition(head, tail, 6);
    printLinkedList(head);

    cout << "Check for head and tail: " << endl;
    cout << "\thead: " << head->data << endl;
    cout << "\ttail: " << tail->data << endl;

    return 0;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
        return;
    }

    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void inserAtPosition(Node *&head, Node *&tail, int position, int data)
{

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int count = 1;
    Node *temp = head;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *nodeToDelete = temp->next;

    if (nodeToDelete->next == NULL)
    {
        tail = temp;
    }

    temp->next = nodeToDelete->next;
    nodeToDelete->next = NULL;
    delete nodeToDelete;
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