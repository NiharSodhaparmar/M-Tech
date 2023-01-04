System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: ./OutputSnapshots

-> Command to Run Program
    g++ IsIdenticalTrees.cpp -o IsIdenticalTrees & IsIdenticalTrees.exe

1.1 Algorithm:
    isIdenticalTree(root1, root2)
    1.  if root1 == NULL and root2 == NULL
    2.      return true
    3.  if (root1 == NULL and root2 != NULL) or (root1 != NULL and root2 == NULL)
    4.      return false
    5.  op1 = isIdenticalTree(root1->left, root2->left)
    6.  op2 = isIdenticalTree(root1->right, root2->right)
    7.  op3 = root1->data == root2->data
    8.  if op1 and op2 and op3
    9.      return true
    10. else
    11.     return false

1.2 Asymptotic Analysis:
    height of first tree : m
    height of second tree : n

    Time Complexity : min{O(m), O(n)}

1
1.3 Empirical Analysis:
    Input Data:
        For firt tree : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
        For second tree : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    Time Taken : 0.0000006 seconds
