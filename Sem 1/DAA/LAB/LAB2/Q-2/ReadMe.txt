System Specifications:
Operating System: Windows
Compiler: g++

Snapshots: Output.jpg

1. Basic Matrix Multiplication

    Program File: BasicMatrixMultiplication.cpp
    Command to run program : g++ -o BasicMatrixMultiplication BasicMatrixMultiplication.cpp&BasicMatrixMultiplication.exe  

    1.1 Asymptotic Analysis of Time Complexity
        Time complexity : T(n) = 8T(n/2) + O(n^2) = O(n^3)

    1.2 Empirical Analysis of Time Complexity
        Time taken to multipy 10 * 10 matrix : 15 microsecond

        Time taken to multipy 100 * 100  matrix : 17367 microsecond

        Here, we increased input size by factor of 10 and as time complexity is O(n^3), increment in time should by factor of 1000.
        And that is that we are approximately getting.
        Hence our asymptotic analysis of time complexity is proved by empirical analysis.

2. Strassens Matrix Multiplication

    Program File: StrassensMatrixMultiplication.cpp
    Command to run program : g++ -o StrassensMatrixMultiplication StrassensMatrixMultiplication.cpp&StrassensMatrixMultiplication.exe

    2.1 Asymptotic Analysis of Time Complexity
        Time complexity : T(n) = 7T(n/2) + O(n^2) = O(n^2.8074)

    2.2 Empirical Analysis of Time Complexity
        Time taken to multiply matrix of size 10 * 10 : 4461 microsecond
        Time taken to multiply matrix of size 100 * 100 : 1556035 microsecond

    Here, we increased input size by factor of 10 and as time complexity is O(n^2.8074)
    And that is that we are approximately getting.
    Hence our asymptotic analysis of time complexity is proved by empirical analysis.

3. Conclusion
    Although time complexity for strassen matrix multiplication is lesser than that of brute force approach,
    time taken by strassen algorithm is much.
