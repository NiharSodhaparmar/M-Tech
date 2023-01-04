System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: ./OutputSnapshots

-> Command to Run Program
    g++ Program17.cpp -o Program17 & Program17.exe

1. Algorithm
    
    getMinDistance(nums, n)
    1.  min = INT_MAX                               --------------- O(1)
    2.  for i = 1 to n                              --------------- O(n)
    3.      if((nums[i+1] - nums[i]) < min)         --------------- O(n)
    4.          min = nums[i+1] - nums[i]           --------------- O(n)
    5.  return min                                  --------------- O(1)

2. Asymptotic Analysis
    Time Complexity = 1 + n + n + n + 1 = O(2 + 3n)
    Time Complexity = O(n)

3. Empirical Analysis
    Input Size: 100000
    Time Taken: 0.000459

    Input Size: 100000
    Time Taken: 0.00461 seconds

    Here we can increase input by factor of 10 so that time compexity should increase approx by factor of 10.
    That we are getting approx in empirical analysis which is same as asymptotic analysis.