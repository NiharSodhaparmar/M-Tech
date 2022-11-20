System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm
    minNumberOfMessage(data, n)
        01.  count <- 0                               
        02.  for i=0 to n-1
        03.     data[i + 1] = data[i + 1] + data[i]
	    04.	count++
        05.  for i=n-1 to 0
        06.     data[i - 1] = data[n - 1]
	    07.	count++

2. Asymptotic Analysis
    Time complexity : O(1) + O(n) + O(n) = O(n) 


3. Empirical Analysis
    Ans : 18
    Time taken for 10 people : 1000 nanoseconds

    Ans : 198
    Time taken for 100 people : 3000 nanoseconds

    Ans : 1998
    Time taken for 1000 people : 15000 nanoseconds

    Ans : 19998
    Time taken for 10000 people : 160000 nanoseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(n) which is matching with the asymptotic analysis.