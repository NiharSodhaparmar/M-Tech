System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: ../OutputSnapshots

1. Basic Exponent
    -> Command to Run Program
        g++ BasicExponent.cpp -o BasicExponent & BasicExponent.exe

    1.1 Algorithm

        basicExponent(a,n)
        1.  ans = a                 --------------- O(1)
        2.  for i = 1 to n          --------------- O(n)
        3.      ans = ans * a       --------------- O(n-1)
        4.  return ans              --------------- O(1)

    1.2 Asymptotic Analysis:
        Time Complexity = 1 + n + (n-1) + 1 = 2n + 1
        Time Complexity: O(n)

    1.3 Empirical Analysis:
        Input(a^n)
        a : 1
        n : 10^11
        Time Taken: 2.05566 seconds

        Input(a^n)
        a : 1
        n : 10^12
        Time Taken: 20.5382 seconds

        Here we increase input by factor of 10 so that time compexity should increase approx by factor of 10.
        That we are getting in empirical analysis which is same as asymptotic analysis.

2. Binary Exponent
    -> Command to Run Program
        g++ BinExponent.cpp -o BinExponent & BinExponent.exe

    2.1 Algorithm
        binExponent(a,n)
            1.  if n = 0
            2.      return 1
            3.  ans = binExponent
            4.  if n%2
            5.      return ans * ans * a
            6.  else
            7.      return ans * ans
        
    2.2 Asymptotic Analysis:
        Time Complexity = T(n/2) + 1
        Time Complexity = O(log(n))

    2.3 Empirical Analysis:
        Input(a^n)
        a : 1
        n : 10^11
        Time Taken: 0.001826 seconds

        Input(a^n)
        a : 1
        n : 10^12
        Time Taken: 0.001862 seconds

        Here we increase input by factor of 10 so that time compexity should increase approx by factor of log(10).
        That we are getting in empirical analysis which is same as asymptotic analysis.