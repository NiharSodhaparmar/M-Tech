#include <iostream>
#include <unordered_map>
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

Node *removeDuplicatesApproach1(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp)
    {
        Node *curr = temp->next;
        Node *prev = temp;

        while (curr)
        {
            if (curr->data == temp->data)
            {
                Node *nodeToDelete = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete (nodeToDelete);
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        temp = temp->next;
    }

    return head;
}

Node *removeDuplicatesApproach2(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    unordered_map<int, bool> visited;
    Node *temp = head;
    Node *prev = head;

    while (temp)
    {
        if (visited[temp->data])
        {
            Node *nodeToDelete = temp;
            prev->next = temp->next;
            delete (nodeToDelete);
        }
        else
        {
            prev = temp;
            visited[temp->data] = true;
        }
        temp = temp->next;
    }

    return head;
}

int main()
{

    Node *head = new Node(6);
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

    // Node *head1 = removeDuplicatesApproach1(head);

    // cout << "Linked List after removing duplicates(approach1): " << endl;
    // printLinkedList(head1);
    // cout << endl;

    Node *head2 = removeDuplicatesApproach2(head);
    cout << "Linked List after removing duplicates(approach2): " << endl;
    printLinkedList(head2);
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