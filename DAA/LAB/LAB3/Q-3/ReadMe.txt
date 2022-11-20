System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm

    maxRevenue(m, x[], revenue[], n, t)
            01.  ans[m+1]  <- {0}                               
            02.  nxtbb = 0
            03.  for i = 1 to m  
            04.     if (nxtbb < n)
            05.             if (x[nxtbb] != i)
            06.                     ans[i] = ans[i - 1]
            07.             else
            08.                     if (i <= t)
            09.                             ans[i] = max(ans[i - 1], revenue[nxtbb]);
            10.                     else
            11                             ans[i] = max(ans[i - t - 1] + revenue[nxtbb], ans[i - 1]);
            12.                     nxtbb++; 
            13.     else
            14.             ans[i] = ans[i - 1]
            15.  return ans[m]


2. Asymptotic Analysis
    Time complexity : O(m+1) + O(1) + O(m) + O(1) = O(m)


3. Empirical Analysis
    Max revenue for m = 100 and t = 2: 73
    Time taken: 4 microseconds

    Max revenue for m = 1000 and t = 2: 911
    Time taken: 19 microseconds

    Max revenue for m = 10000 and t = 2: 8695
    Time taken: 158 microseconds

    Max revenue for m = 100000 and t = 2: 86460
    Time taken: 2287 microseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(m) which is matching with the asymptotic analysis.
