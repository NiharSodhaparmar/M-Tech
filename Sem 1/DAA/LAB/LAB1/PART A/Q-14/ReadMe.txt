System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: ./OutputSnapshots

-> Command to Run Program
    g++ Program14.cpp -o Program14 & Program14.exe

For the given operations I used AVL tree. AVL tree has the Insertion, Search and Delete operations has 
complexity O(log(n)).

For the finding kth smallest element I have maintain lCount and rCount addition field on the node. Manipulation
of this values is done in the O(1) for insertion and deletion.

Where lCount maintains the count of all left subtree node and rCount maintains the rCount of right subtree.

Below is the implemention of node:

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    int lCount;
    int rCount;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
        this->rCount = 0;
        this->lCount = 0;
    }
};


1. Insert:
    Insertion is same as AVL tree. Here, I have to maintain additional lCount and rCount. This can be maintain
    in O(1).

    So, Time Complexity = O(log(n))


2. Member(Search):
    Member(Search) is same as AVL tree.

    So, Time Complexity = O(log(n))


3. Find kth smallest element and Delete
    
    3.1 Algorithm:
        getKthSmalletElement(root, k)
        1.  if root = NULL
        2.      return
        3.  count = root->lCount
        4.  if count = k
        5.      return root
        6.  if k < lCount
        7.      return getKthSmalletElement(root->left, k)
        8.  else
        9.      return getKthSmalletElement(root->right, k - count)

        Time Complexity = T(n/2) + 1 = T(n/2) + 1
        Time Complexity = O(log(n))

    For the deletion I used the delete of AVL tree and maintains lCount and rCount of node which takes O(1).
    So, Time Complexity = O(log(n))

    So, Total Time Complexity for the deletion of kth smallest element is O(log(n)).

4 Empirical Analysis:

    4.1 Input size 100000
        Inserting 100000 elements
        Time Taken: 0.085509 seconds

        Search 1048579
        Time Taken: 0.000613 seconds

        Delete 700000th index
        Time Taken: 0.000005 seconds

    4.2 Input size 1000000
        Inserting 1000000 elements
        Time Taken: 1.57191 seconds

        Search 1048579
        Time Taken: 0.000204 seconds

        Delete 700000th index
        Time Taken: 0.000006 seconds

        Here we can see that all operations performed in log((n)) time.