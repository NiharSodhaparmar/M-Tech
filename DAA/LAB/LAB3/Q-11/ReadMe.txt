System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm
    getMinCost(data[][])
        01.  cost = 0                              
        02.  sort data using second parameter in decreasing order
        03.  month = 1      
        04.  tmp = 0
        05.  for i = 0 to data.size
        06.     if month==1
        07.             tmp = 100
        08.     else
        09.             temp = 100 * data[i][1] * month
        10.     cost += temp
        11.     month++
        12. return cost


2. Asymptotic Analysis
    Time complexity : O(1) + O(n * log(n)) + O(1) + O(1) + O(n+1) + O(1) + O(1)= O(n * log(n))


3. Empirical Analysis
    For n = 10
        Total Cost = 21100
        Time Taken = 13000 nanoseconds
    For n = 100
        Total Cost = 17160100
        Time Taken = 36000 nanoseconds
    For n = 1000
        Total Cost = 16716600100
        Time Taken = 646000 nanoseconds
    For n = 10000
        Total Cost = 531178901732
        Time Taken = 4399000 nanoseconds
    For n = 100000
        Total Cost = 1585449957732
        Time Taken = 45627000 nanoseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(nlogn) which is matching with the asymptotic analysis.