#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtHead(struct Node **head, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = (*head);
    (*head) = temp;
}

void printLinkedList(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }

    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    insertAtHead(&head, 15);
    insertAtHead(&head, 20);

    printLinkedList(head);
    return 0;
}