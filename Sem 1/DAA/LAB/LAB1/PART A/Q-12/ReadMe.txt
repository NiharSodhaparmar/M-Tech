System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: ./OutputSnapshots

-> Command to Run Program
    g++ ConcatenateBST.cpp -o ConcatenateBST & ConcatenateBST.exe

1.  Concatenate BST

    1.1 Algorithm
        concatenate(root1, root2)
        1.  minNode = root2                     --------------- O(1)
        2.  while minNode->left                 --------------- O(h + 1)
        3.      minNode = minNode->left         --------------- O(h)
        4.  minNode->left = root1               --------------- O(1)
        5.  return root2                        --------------- O(1)

    1.2 Asymptotic Analysis
        Time compexity = 1 + h + 1 + h + 1 + 1 = 2h + 4
        Time Complexity =  O(h)