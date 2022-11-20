System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm

    knapSack(W, wt[], val[], n)
        01.  k <- W / wt[0]                               
        02.  for i = 0 to k
        03.     for j = 0 to j < n - i - 1      
        04.             if val[j] < val[j + 1]
        05.                     tmp <- val[j]
        06.                     val[j] <- val[j+1]
        07.                     val[j+1] <- tmp                
        08.     ans <- 0
        09.     for i = 0 to k
        10.             ans <- ans + val[i];
        11. return ans


2. Asymptotic Analysis
    Time complexity : O(1) + O(k*n) + O(1) + O(k)= O(n*k)


3. Empirical Analysis
    1.  Given data:
        Weight  Value
        5       100
        5       20
        5       15

        Max Profit : 120
        Time taken for 3 objects and 10 size knapsack :  0 nanoseconds

    2.  Given data:
        Weight  Value
        5       90
        5       85
        5       80
        5       55
        5       95
        5       15
        5       10

        Max Profit : 175
        Time taken for 7 objects and 10 size knapsack :  0 nanoseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(kn) (for both k is 2) which is matching with the asymptotic analysis.