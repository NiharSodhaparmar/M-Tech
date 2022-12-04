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

void insertNode(Node *&tail, int element, int data);
void deleteNode(Node *&tail, int data);
void printCircularLinkedList(Node *tail);

int main()
{
    Node *tail = NULL;

    cout << "Print after creating nodes: " << endl;
    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 7, 9);
    insertNode(tail, 7, 8);
    printCircularLinkedList(tail);
    cout << endl;

    cout << "Print after deleting nodes: " << endl;
    deleteNode(tail, 8);
    deleteNode(tail, 9);
    deleteNode(tail, 3);
    deleteNode(tail, 5);
    deleteNode(tail, 7);
    printCircularLinkedList(tail);

    return 0;
}

void insertNode(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        tail->next = tail;
        return;
    }

    Node *temp = tail;

    while (temp->data != element)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&tail, int data)
{
    if (tail == NULL)
    {
        cout << "Linked List is empty." << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != data)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;

    // 1 node list
    if (curr == prev)
    {
        tail = NULL;
    }
    // >2 node list
    else if (tail == curr)
    {
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
}

void printCircularLinkedList(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is Empty." << endl;
        return;
    }

    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}