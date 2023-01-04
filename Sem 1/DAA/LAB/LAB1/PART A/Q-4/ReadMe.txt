System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: ../OutputSnapshots

1. Insertion Sort
    -> Command to Run Program
        g++ InsertionSort.cpp -o InsertionSort & InsertionSort.exe
        
    1.1 Asymptotic Analysis:
        Best Case: O(n)
        Average Case: O(n^2)
        Worst Case: O(n^2)

    1.2 Empirical Analysis:

        1.2.1 Input size : 100000
            Best Case: 0.000726 seconds
            Number of swap: 0

            Average Case: 18.9596 seconds
            Number of swap: 18446744071917719854

            Worst Case: 38.6995 seconds
            Number of swap: 704982704

        1.2.1 Input size : 1000000
            Best Case: 0.008371 seconds
            Average Case: 2007.02 seconds
            Worst Case: 4775.27 seconds

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of 100 in Average and Worst Case and by power of 10 in Best Case.
        That we are getting approx in empirical analysis which is same as asymptotic analysis.

2. Merge Sort
    -> Command to Run Program
        g++ MergeSort.cpp -o MergeSort & MergeSort.exe

    2.1 Asymptotic Analysis:
        Best Case: O(nlog(n))
        Average Case: O(nlog(n))
        Worst Case: O(nlog(n))

    2.2 Empirical Analysis:
        2.2.1 Input size : 100000
            Not Sorted Data: 0.086704 seconds
            Number of swap: 1668928

            Sorted Data: 0.029348 seconds
            Number of swap: 1668928

        2.2.2 Input size : 1000000
            Not Sorted Data: 0.469533 seconds
            Number of swap: 19951424

            Sorted Data: 0.318775 seconds
            Number of swap: 19951424

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of  (6 * 10 * log(10)) / 5 (as per input size).
        That we are getting approx in empirical analysis which is same as asymptotic analysis.

3. Heap Sort
    -> Command to Run Program
        g++ HeapSort.cpp -o HeapSort & HeapSort.exe

    3.1 Asymptotic Analysis:
        Best Case: O(nlog(n))
        Average Case: O(nlog(n))
        Worst Case: O(nlog(n))

    3.2 Empirical Analysis
        3.2.1 Input size : 100000
            Not Sorted Data: 0.050459 seconds
            Number of swap: 1574998

            Sorted Data: 0.048305 seconds
            Number of swap: 1650854

        3.2.2 Input size : 1000000
            Not Sorted Data: 0.607924 seconds
            Number of swap: 19046209

            Sorted Data: 0.514355 seconds
            Number of swap: 19787792

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of (6 * 10 * log(10)) / 5 (as per input size).
        That we are getting approx in empirical analysis which is same as asymptotic analysis.
        
4. Quick Sort
    -> Command to Run Program
        g++ QuickSort.cpp -o QuickSort & QuickSort.exe

    4.1 Asymptotic Analysis:
        Best Case: O(nlog(n))
        Average Case: O(nlog(n))
        Worst Case: O(n^2)

    4.2 Empirical Analysis:
        4.2.1 Input size : 100000
            Not Sorted Data: 0.026131 seconds
            Number of swap: 1070098

        4.2.2 Input size : 1000000
            Not Sorted Data: 0.313292 seconds
            Number of swap: 13453804

        4.2.3 Input size : 1000
            Sorted Data: 0.002076 seconds
            Number of swap: 999

        4.2.4 Input size : 10000
            Sorted Data: 0.130614 seconds
            Number of swap: 9999

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of (6 * 10 * log(10)) / 5 (as per input size) in Best and Average Case and in Worst Case increase factor by 100.
        That we are getting approx in empirical analysis which is same as asymptotic analysis.