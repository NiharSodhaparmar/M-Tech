System Specifications:
Operating System: Windows
Compiler: g++

Program File: CountingSort.cpp
Command to run code: g++ CountingSort.cpp -o CountingSort & CountingSort.exe
Snapshots: ./Output

1.1 Algorithm

    countSort(arr, n)
    1.    max = INT_MIN                                     --------------- O(1)
    2.    for i=0 to n                                      --------------- O(n)
    3.        if arr[i] > max                               --------------- O(n-1)
    4.            max = arr[i]                              --------------- O(n-1)
    5.    countArr[max + 1]                                 --------------- O(1)
    6.    tmp[n]                                            --------------- O(1)
    7.    for i=0 to n                                      --------------- O(n)
    8.        ++countArr[arr[i]]                            --------------- O(n-1)  
    9.    for i=1 to max                                    --------------- O(k)
    10.       countArr[i] = countArr[i] + countArr[i - 1]   --------------- O(k-1)
    11.    for i=n-1 to 0                                   --------------- O(n)
    12.       tmp[--countArr[arr[i]]] = arr[i]              --------------- O(n-1)
    13.    for i=0 to n                                     --------------- O(n)
    14.       arr[i] = tmp[i];                              --------------- O(n-1)

1.2 Asymptotic Analysis
    Time Complexity =  O(n + k)

1.3 Empirical Analysis:
    Input Size : 10000
    Time Complexity: 262 microseconds
        
    Input Size : 100000
    Time Complexity: 2562 microseconds

1.4 Conclusion
    Here for input size 10000 and 100000 we get time 262 microseconds and 2562 microseconds. Which is linear.