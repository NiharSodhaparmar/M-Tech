System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm
    baseStation(house[])
        01. ans[]
        02. sort ans in increasing order
        03. tower = house[0] + 4
        04. ans <- tower
        05. i = 1
        06. while(i < house.size)
        07.     if ((tower + 4) >= house[i])
        08.         i++
        09.     else
        10.         tower = house[i] + 4 
        11.         ans <- tower
        12. return ans


2. Asymptotic Analysis
    Time complexity : O(1) + O(n * log(n)) + O(1) + O(1) + O(1) + O(n) = O(n * log(n))


3. Empirical Analysis
    For Total City : 10
            Number of tower = 10
            Time Tiken = 5000 nanoseconds
    For Total City : 100
            Number of tower = 99
            Time Tiken = 25000 nanoseconds
    For Total City : 1000
            Number of tower = 977
            Time Tiken = 220000 nanoseconds
    For Total City : 10000
            Number of tower = 9070
            Time Tiken = 2679000 nanoseconds
    For Total City : 100000
            Number of tower = 57264
            Time Tiken = 31863000 nanoseconds
    For Total City : 1000000
            Number of tower = 143577
            Time Tiken = 365394000 nanoseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(nlogn) which is matching with the asymptotic analysis.