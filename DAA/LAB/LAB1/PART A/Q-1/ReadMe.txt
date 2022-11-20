System Specifications:
Operating System: Windows
Compiler: g++

Command to run code: g++ Dataset.cpp -o Dataset & Dataset.exe
Snapshots: ./Output

1. Find Duplicates

    1.1 Algorithm
        getNumberOfDuplicates(A)
        1.  n = A.size                                  --------------- O(1)
        2.  numberOfDuplicates = 0                      --------------- O(1)
        3.  for i = 1 to n                              --------------- O(n)
        4.      a = abs(A[i])                           --------------- O(n-1)
        5.      if A[a] < 0                             --------------- O(n-1)
        6.         numberOfDuplicates++                 --------------- O(n-1)
        7.       else                                   
        8.         A[a] = -1 * A[a]                     
        9.  for i = 1 to n                              --------------- O(n)
        10.     if A[i] < 0                             --------------- O(n-1)
        11.        A[i] = -1 * A[i]                     --------------- O(n-1)
        12. return numberOfDuplicates                   --------------- O(1)

    1.2 Asymptotic Analysis
        Considering all statements executes in constant time
        Time compexity = 1 + 1 + n + (n-1) + (n-1) + (n-1) + n + (n-1) + (n-1) + 1 = 7n - 2
        Time Complexity =  O(n)

    1.3 Empirical Analysis:
        Input Size : 100000
        Time Complexity: 0.00257 seconds
        
        Input Size : 1000000
        Time Complexity: 0.030826 seconds

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of 10.
        That we are getting approx in empirical analysis which is same as asymptotic analysis.


2. Remove Duplicates

    2.1 Algorithm
        removeDuplicateNumbers
        1.  n = A.size                                                      --------------- O(1)
        2.  unorderedSet                                                    --------------- O(1)
        3.  for i = 1 to n                                                  --------------- O(n)
        4.  if unorderedSet.find(A[i]) == unorderedSet.end()                
        5.      unorderedSet.insert(A[i])
        6.  else      
        7.      left = A[i] - 1                                             --------------- O(n-1)
        8.      right = A[i] + 1                                            --------------- O(n-1)
        9.      while left > 0 || right < n                                 --------------- O(n*(n-1))
        10.         if left > 0                                             --------------- O((n-1)*(n-1))
        11.             if unorderedSet.find(left) == unorderedSet.end()    --------------- O((n-1)*(n-1))
        12.                 A[i] = left                                     --------------- O((n-1)*(n-1))
        13.                 unorderedSet.insert(left)                       --------------- O((n-1)*(n-1))
        14.                 break                                           --------------- O((n-1)*(n-1))
        15.             left--                                          
        16.         if unorderedSet.find(right) == unorderedSet.end()
        17.             A[i] = right
        18.             unorderedSet.insert(right)
        19.             break
        20.         right++

        2.2 Asymptotic Analysis
            Considering all statements executes in constant time
            Time compexity = 1 + 1 + n + (n-1) + (n-1) + n*(n-1) + 5(n-1)*(n-1) = 6n^2 - 8n + 5
            Time Complexity =  O(n^2)

        2.3 Empirical Analysis:
            Input Size : 100000
            Time Complexity: 0.133161 seconds
            
            Input Size : 1000000
            Time Complexity: 2.70951 seconds

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of 100.
        That we are getting not extactly but approx in empirical analysis which is same as asymptotic analysis.