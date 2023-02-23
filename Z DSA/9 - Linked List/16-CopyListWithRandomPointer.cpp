#include <iostream>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (!head)
            return NULL;

        Node *temp = head;
        Node *newTemp = new Node(head->val);
        Node *newHead = newTemp;

        unordered_map<Node *, Node *> nodeData;
        nodeData[temp] = newTemp;

        while (temp->next)
        {
            Node *node = new Node(temp->next->val);
            newTemp->next = node;
            nodeData[temp->next] = node;
            temp = temp->next;
            newTemp = newTemp->next;
        }

        newTemp->next = NULL;

        temp = head;
        newTemp = newHead;

        while (newTemp)
        {
            newTemp->random = nodeData[temp->random];
            newTemp = newTemp->next;
            temp = temp->next;
        }

        return newHead;
    }
};

// geeks for geeks
// class Solution
// {
//     public:
//     Node *copyList(Node *head)
//     {
//         if(!head)
//             return NULL;

//         Node *temp = head;
//         Node *newTemp = new Node(head->data);
//         Node *newHead = newTemp;

//         // step1: create new ll without random pointer
//         while(temp->next)
//         {
//             Node *node = new Node(temp->next->data);
//             newTemp->next = node;
//             temp = temp->next;
//             newTemp = newTemp->next;
//         }
//         newTemp->next = NULL;

//         // step2: insert nodes of new ll between original list
//         temp = head;
//         newTemp = newHead;
//         while(temp && newTemp)
//         {
//             Node* next = temp -> next;
//             temp -> next = newTemp;
//             temp = next;

//             next = newTemp -> next;
//             newTemp -> next = newTemp;
//             newTemp  = next;
//         }

//         // step3: set random pointers
//         temp = head;
//         newTemp = newHead;
//         while(temp && newTemp)
//         {
//             if(temp->arb)
//             {
//                 newTemp->arb = temp->arb->next;
//             }
//             else
//             {
//                 newTemp->arb = NULL;
//             }
//             temp = temp->next;
//             newTemp = newTemp->next;
//         }

//         temp = head;
//         newTemp = newHead;
//         while(temp && newTemp)
//         {
//             temp->next = temp->next ? temp->next->next : temp->next;
//             temp = temp->next;

//             newTemp->next = newTemp->next ? newTemp->next->next : newTemp->next;
//             newTemp = newTemp->next;
//         }

//         return newHead;
//     }

// };