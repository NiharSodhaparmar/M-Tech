System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Empirical Analysis

    Data set size : 10
    Total Profit using optimal Solution : 145781
    Total Profit using given   Solution : 99760.4
    Time Taken using optimal Solution : 16000 nanoseconds
    Time Taken using given   Solution : 3000 nanoseconds
    Ratio = F*(I)/F(I)                  : 1.46131

    Data set size : 100
    Total Profit using optimal Solution : 391826
    Total Profit using given   Solution : 4058.39
    Time Taken using optimal Solution : 40000 nanoseconds
    Time Taken using given   Solution : 29000 nanoseconds
    Ratio = F*(I)/F(I)                  : 96.5472

    Data set size : 1000
    Total Profit using optimal Solution : 1.29057e+06
    Total Profit using given   Solution : 56.0652
    Time Taken using optimal Solution : 557000 nanoseconds
    Time Taken using given   Solution : 354000 nanoseconds
    Ratio = F*(I)/F(I)                  : 23019.1

    Data set size : 10000
    Total Profit using optimal Solution : 3.98814e+06
    Total Profit using given   Solution : 94.734
    Time Taken using optimal Solution : 4651000 nanoseconds
    Time Taken using given   Solution : 3672000 nanoseconds
    Ratio = F*(I)/F(I)                  : 42098.3

    Data set size : 100000
    Total Profit using optimal Solution : 1.31796e+07
    Total Profit using given   Solution : 3.54268
    Time Taken using optimal Solution : 55993000 nanoseconds
    Time Taken using given   Solution : 47615000 nanoseconds
    Ratio = F*(I)/F(I)                  : 3.72023e+06
    

2. Conclusion
    From the outputs we can see that optimal answer is always greater than or equal greedy answer.