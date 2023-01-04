System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: ./OutputSnapshots

-> Command to Run Program
    g++ Program7.cpp -o Program7 & Program7.exe

1. Code 1

    1.  f o r i = 1 t o n
    2.      f o r j = 1 t o i
    3.          x = x + 1

    1.1 Asymptotic Analysis:
        
        i   |   j       |   no. of times x = x+1 runs

        1       1           1
        2       1 to 2      2
        3       1 to 3      3
        .       .           .
        .       .           .
        n       1 to n      n

        Time Complexity = 1 + 2 + 3 + ... + n = n(n+1)/2
        Time Complexity = O(n^2)

    1.2 Empirical Analysis:
        1.2.1 Input size: 1000
            Time Taken: 0.002708 seconds

        1.2.1 Input size: 10000
            Time Taken: 0.085534 seconds

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of 100.
        That we are getting approx in empirical analysis which is same as asymptotic analysis.

2. Code 2

    1.  j=n
    2.  whil e ( j >= 1 ){
    3.      f o r i = 1 t o j
    4.          x = x + 1
    5.      j = n/2
    6.  }

    2.1 Asymptotic Analysis
        
        j       |       i       |   no. of times x = x+1 runs
    
        n             1 to n       n
        n/2           1 to n       n/2
        n/2           1 to n       n/2
        n/2           1 to n       n/2
        .             .           .
        .             .           .
        .             .           .

        Here j value not changes so that code runs in infinite loop

3. Code 3

    1.  f o r i = 1 t o n
    2.      f o r j = 1 t o i
    3.          f o r k = 1 t o i
    4.              x = x + 1

    3.1 Asymptotic Analysis:

        i       |       j           |       k       |       no. of times x = x+1 runs

        1               1 to 1          1*(1 to 1)          1
        2               1 to 2          2*(1 to 2)          4
        3               1 to 3          3*(1 to 3)          9
        4               1 to 4          4*(1 to 4)          16
        .               .               .                   .
        .               .               .                   .
        .               .               .                   .
        n               1 to n          n*(1 to n)          n^2

        Time Complexity = 1 + 4 + 9 + 16 + ... + n = n(n+1)(2n+1)/6
        Time Complexity = O(n^3)

    3.2 Empirical Analysis:
        3.2.1 Input size: 1000
                Time Taken: 0.551723 seconds

        3.2.1 Input size: 10000
            Time Taken: 936.352 seconds

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of 1000.
        That we are getting approx in empirical analysis which is same as asymptotic analysis.

4. Code 4

    1.  i=n
    2.  w h i l e ( i >= 1 ){
    3.      f o r j = 1 t o n
    4.          x = x + 1
    5.          i = i /2
    6.  }

    3.1 Asymptotic Analysis:
        
        i       |       j       |       no. of times x = x+1 runs

        n               1 to n          n
        0               -               -

        Time Complexity = n
        Time Complexity = O(n)

    1.2 Empirical Analysis:
        Time Taken: 0.000562 seconds
        3.2.1 Input size: 1000
                Time Taken: 0.000172 seconds

        3.2.1 Input size: 10000
            Time Taken: 0.000562 seconds

        Here we can increase input by factor of 10 so that time compexity should increase approx by factor of 10.
        That we are getting approx in empirical analysis which is same as asymptotic analysis.