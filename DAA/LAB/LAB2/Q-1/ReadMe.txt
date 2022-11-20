System Specifications:
Operating System: Windows
Compiler: g++

Program File: NoOfLevels.cpp
Command to run code: g++ NoOfLevels.cpp -o NoOfLevels & NoOfLevels.exe
Snapshots: Output.jpg

1. getBinaryTreeLevel

    1.1 Alogithm:
        getLevel(root)
        1.  if root == NULL                                        
        2.      return 0                                         
        3.  leftTreeLevel = getLevel(root->left)        
        4.  rightTreeLevel = getLevel(root->right)  
        5.  return 1 + max(leftTreeLevel, rightTreeLevel)          

    1.2 Asymptotic Analysis of Time Complexity
        Time complexity : O(n)

    1.3 Empirical Analysis of Time Complexity
        Time taken to find level 0 of tree: 0 nanoseconds
        Time taken to find level 1 of tree: 0 nanoseconds
        Time taken to find level 2 of tree: 0 nanoseconds
        Time taken to find level 3 of tree: 0 nanoseconds

    1.4 Conclusion
        From above observations we can see that for small inputs we get 0 microseconds which is linear.