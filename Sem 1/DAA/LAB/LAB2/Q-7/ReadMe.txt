System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program7.cpp
Command to run code: g++ Program7.cpp -o Program7 & Program7.exe
Snapshots: Output.jpg

1. Empirical Analysis
    1.1 Dataset Size : 10000
            Time taken for start as pivot           : 2565000 nanoseconds
            Time taken for end as pivot             : 182000 nanoseconds
            Time taken for median of three as pivot : 7469000 nanoseconds
            Time taken for random as pivot          : 9976000 nanoseconds

    1.2 Dataset Size : 100000
            Time taken for start as pivot           : 22320000 nanoseconds
            Time taken for end as pivot             : 1694000 nanoseconds
            Time taken for median of three as pivot : 58929000 nanoseconds
            Time taken for random as pivot          : 106146000 nanoseconds

2. Conclusion
    From above observation it is clear that median of three as pivot approach is best suitable for quicksort.
    So, if
        t1 = time taken by start as pivot
        t2 = time taken by end as pivot
        t3 = time taken by median of three as pivot
        t4 = time taken by random as pivot
        
        then, t2 < t1 < t3 < t4
