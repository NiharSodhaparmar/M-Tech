System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm

    getMaximumSelectedActivitiesByFirst(jobs, n)
        1.  ans <- Φ   /* ans =  Set of selected mutually compatible jobs */
        2.  sort jobs by their finish time in increasing order                                  
        3.  i = 0       
        4.  for j = 1 to n
        5.      if j.start >= i.end
        6.          ans = ans U {j}
        7.          i = j
        8.  return ans

    getMaximumSelectedActivitiesByLast(jobs, n)
        1.  ans <- Φ   /* ans =  Set of selected mutually compatible jobs */
        2.  sort jobs by their finish time in descreasing order                                  
        3.  i = 0       
        4.  for j = 1 to n
        5.      if j.start >= i.end
        6.          ans = ans U {j}
        7.          i = j
        8.  return ans

2. Asymptotic Analysis
    For Both Algorithm
    Time complexity : O(1) + O(nlogn) + O(1) + O(n) + O(1) = O(nlogn)


3. Empirical Analysis
    Total Activity : 10
        When selecting first activity first No of activities selected: 4
        when selecting first activity first : 7000 nanoseconds
        When selecting last activity first No of activities selected: 3
        when selecting last activity first : 13000 nanoseconds
Total Activity : 100
        When selecting first activity first No of activities selected: 11
        when selecting first activity first : 23000 nanoseconds
        When selecting last activity first No of activities selected: 4
        when selecting last activity first : 38000 nanoseconds
Total Activity : 1000
        When selecting first activity first No of activities selected: 52
        when selecting first activity first : 231000 nanoseconds
        When selecting last activity first No of activities selected: 6
        when selecting last activity first : 394000 nanoseconds
Total Activity : 10000
        When selecting first activity first No of activities selected: 411
        when selecting first activity first : 2796000 nanoseconds
        When selecting last activity first No of activities selected: 17
        when selecting last activity first : 5320000 nanoseconds


4. Conclusion
    From the above outputs we can see time taken is approximately O(nlogn) which is matching with the asymptotic analysis. But we can see that by selecting first activity first we get the optimal answer.