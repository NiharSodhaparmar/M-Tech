System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm

    knapSack(W, w[], v[], n)
        01. ans = 0
        02. for i = 0 to n
        03. if (W - w[i] >= 0)
        04.     ans += v[i]
        05.     W -= w[i]
        06. else
        07.     break
        08. return ans


2. Asymptotic Analysis
    Time complexity: O(1) + O(n) + O(n-1) + O(n-1) + O(n-1) + O(1) = O(n)


3. Empirical Analysis
    For n = 10
        Max Profit for W = 330 : 100
        Time taken: 5000 nanoseconds

    For n = 100
            Max Profit for W = 330 : 1000
            Time taken: 3000 nanoseconds

    For n = 1000
            Max Profit for W = 330 : 3300
            Time taken: 6000 nanoseconds

    For n = 10000
            Max Profit for W = 330 : 3300
            Time taken: 37000 nanoseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(n) which is matching with the asymptotic analysis.