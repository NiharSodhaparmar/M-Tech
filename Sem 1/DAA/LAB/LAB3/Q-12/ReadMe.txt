System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm
    find_euler_circuit()
        01.  count_outgoing_edge for all vertex                                          
        02.  let stack as s                                                              
        03.  let stack_top , circuit as vector                                       
        04.  s.push(0)                                                                   
        05.  while s is not empty                                                      
        06.     if outgoing_edge[s.top()]                                                  
        07.         push adj of s.top() to s and remove that edge from graph            
        08.         decrement outgoing_edge by 1
        09.     else                    
        10.         circuit.push_back(s.top())                                          
        11.         s.pop()                                                             
        12. print circuit in reverse order 


2. Asymptotic Analysis
    Time complexity : O(E + V)


3. Empirical Analysis
    Edges : 10
    Vertecies : 10
    Euler circuit exist.
    Time taken: 81 microseconds

    Edges : 100
    Vertecies : 100
    Euler circuit exist.
    Time taken: 47 microseconds

    Edges : 1000
    Vertecies : 1000
    Euler circuit exist.
    Time taken: 452 microseconds

    Edges : 10000
    Vertecies : 10000
    Euler circuit exist.
    Time taken: 3219 microseconds


4. Conclusion
    From the above output we can see that time increases linearly which is matching with the our asymptotic analysis complexity O(E + V).