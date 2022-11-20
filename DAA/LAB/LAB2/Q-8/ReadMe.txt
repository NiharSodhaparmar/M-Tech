System Specifications:
Operating System: Windows
Compiler: g++

Program File: TopologicalOrdering.cpp
Command to run code: g++ TopologicalOrdering.cpp -o TopologicalOrdering & TopologicalOrdering.exe
Snapshots: Output1.jpg, Output2.jpg

Question:
    Does every graph have a topological ordering ? Reason your answer with appropriate justications.
Answer:
    No. Not every graph have a topological ordering. If the graph has a cycle, a topological order cannot exist.
    Imagine the simplest cycle, consisting of two edges: (a, b) and (b, a).
    A topological ordering, if it existed, would have to satisfy that a must come before b and b must come before a.
    This is not possible.


1. Asymptotic Analysis
    Time Complexity : O(N + E), where N is number of vertices and E is number of edges.
    The algorithm is simply DFS with an extra for loop(for N). So time complexity is the same as DFS.

2. Empirical Analysis
    2.1 Adjacency Matrix of the graph
        0       1       0       0       1
        0       0       1       1       0
        0       0       0       0       0
        0       0       0       0       0
        0       0       0       0       0

        Topological order : 0 4 1 3 2
        Time taken for topological ordering: 1000 nanoseconds

    2.2 Adjacency Matrix of the graph
        0       1       1       0       0       0       0       0
        0       0       0       1       1       0       0       0
        0       0       0       0       0       0       0       1
        0       0       0       0       0       1       0       0
        0       0       0       0       0       0       1       0
        0       0       0       0       0       0       0       0
        0       0       0       0       0       0       0       0
        0       0       0       0       0       0       0       0

        Topological order : 0 2 7 1 4 6 3 5
        Time taken for topological ordering: 2000 nanoseconds

3. Conclusion
    From above observation, it can be see that time taken for both is linear which approximately O(N + E),
    which is matching with asymptotic analysis.