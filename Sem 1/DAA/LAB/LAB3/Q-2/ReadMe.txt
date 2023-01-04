System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm

    getMaximumSelectedActivities(jobs, n)
        1.  ans <- Φ   /* ans =  Set of selected mutually compatible jobs */
        2.  sort jobs by their finish time                                    
        3.  i = 0       
        4.  for j = 1 to n
        5.      if j.start >= i.end
        6.          ans = ans U {j}
        7.          i = j
        8.  return ans


2. Asymptotic Analysis
    Time complexity : O(1) + O(nlogn) + O(1) + O(n) + O(1) = O(nlogn)


3. Empirical Analysis
    
    For Job = 100
         Time Taken : 44 Microsecond
         Number of Job Select : 8
    For Job = 1000
            Time Taken : 559 Microsecond
            Number of Job Select : 20
    For Job = 10000
            Time Taken : 6375 Microsecond
            Number of Job Select : 24
    For Job = 100000
            Time Taken : 67503 Microsecond
            Number of Job Select : 24


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(nlogn) which is matching with the asymptotic analysis.