System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: ./OutputSnapshots

-> Command to Run Program
    g++ Program9.cpp -o Program9 & Program9.exe 100000

1. Bubble Sort
    1.1 Asymptotic Analysis:
        Best Case: O(n^2)
        Average Case: O(n^2)
        Worst Case: O(n^2)

    1.2 Empirical Analysis:
        Input size: 100000
        Average Case: 36.005 seconds

        Input size : 10000
        Average Case: 0.258339 seconds

2. Insertion Sort
    2.1 Asymptotic Analysis:
        Best Case: O(n)
        Average Case: O(n^2)
        Worst Case: O(n^2)

    2.2 Empirical Analysis:
        Input size : 100000
        Average Case: 9.63479 seconds

        Input size : 10000
        Average Case: 0.06281 seconds

3. MergeSort
    3.1 Asymptotic Analysis:
        Best Case: O(nlog(n))
        Average Case: O(nlog(n))
        Worst Case: O(nlog(n))

    3.2 Empirical Analysis:
        Input size : 100000
        Average Case: 0.003271 seconds

        Input size : 10000
        Average Case: 0.00273 seconds

4. Improved MergeSort
    4.1 Asymptotic Analysis:
        Best Case: O(nlog(n))
        Average Case: O(nlog(n))
        Worst Case: O(nlog(n))

    4.2 Empirical Analysis:
        Input size : 100000
        Average Case: 0.341858 seconds

        Input size : 10000
        Average Case: 0.002792 seconds

    Merge Sort time compexity is remains nlog(n) but it reduces the comparisions.
    If two halves is already sorted then no need to sort.

5. Semi Bubble Sort
    4.1 Asymptotic Analysis:
        Best Case: O(n)
        Average Case: O(n^2)
        Worst Case: O(n^2)

    4.2 Empirical Analysis:
        Input size : 100000
        Average Case: 0.346348 seconds

        Input size : 10000
        Average Case: 0.30979 seconds

    Bubble sort complexity remains O(n^2) for average but it sorts from both ends 
    so compexity improves by factor of 2.