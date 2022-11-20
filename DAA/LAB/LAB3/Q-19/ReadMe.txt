System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg

1. Asymptotic Analysis
    Kruskal's Algorithm Time Complexity : O(E*log(E) + E*V)
    Prims's Algorithm Time Complexity   : O(V^2)

2. Empirical Analysis
    Edges    : 10
    vertices : 10
    Time Taken by Kruskal in microseconds : 21
    Time Taken by Prims in microseconds   : 2

    Edges    : 100
    vertices : 100
    Time Taken by Kruskal in microseconds : 41
    Time Taken by Prims in microseconds   : 125

    Edges    : 1000
    vertices : 1000
    Time Taken by Kruskal in microseconds : 121
    Time Taken by Prims in microseconds   : 4581

    Edges    : 10000
    vertices : 10000
    Time Taken by Kruskal in microseconds : 1827
    Time Taken by Prims in microseconds   : 470379


3. Conclusion
    From the above outputs we can see that the time complexity matches with the O(E*log(E) + E*V) and O(V^2) complexities.