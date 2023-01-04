System Specifications:
Operating System: Windows
Compiler: g++

Program File: NumberOfInversions.cpp
Command to run code: g++ NumberOfInversions.cpp -o NumberOfInversions & NumberOfInversions.exe
Snapshots: Output.jpg

1. Empirical Analysis
    Dataset size: 10
        Inversion Count By Brute Force: 6
        Inversion Count By Merge Sort: 6
        Time taken by Brute Force:
            No of micro seconds: 2131
        Time taken by Merge Sort:
            No of micro seconds: 588

    Dataset size: 100
        Inversion Count By Brute Force: 2182
        Inversion Count By Merge Sort: 2182
        Time taken by Brute Force:
            No of micro seconds: 1312
        Time taken by Merge Sort:
            No of micro seconds: 256

    Dataset size: 1000
        Inversion Count By Brute Force: 244810
        Inversion Count By Merge Sort: 244810
        Time taken by Brute Force:
            No of micro seconds: 5717
        Time taken by Merge Sort:
            No of micro seconds: 1889

    Dataset size: 10000
        Inversion Count By Brute Force: 24526481
        Inversion Count By Merge Sort: 24526481
        Time taken by Brute Force:
            No of micro seconds: 466375
        Time taken by Merge Sort:
            No of micro seconds: 5447

    Dataset size: 100000
        Inversion Count By Brute Force: 2472624329
        Inversion Count By Merge Sort: 2472624329
        Time taken by Brute Force:
            No of micro seconds: 45845511
        Time taken by Merge Sort:
            No of micro seconds: 40278

2. Conclusion
    From the above observations we can see that inversion count using merge sort takes lesser time in O(logn) complexity where as brute force takes more time in O(n^2).