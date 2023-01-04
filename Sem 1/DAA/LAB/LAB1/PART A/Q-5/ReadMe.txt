-> Actual time taken by a program depends on the following factors:

1. CPU utilization
    If CPU is already utilized by some other processes then running time of algorithm will increase.

2. Operating system
    If there is high priority process assigned to the os then it runs the high priority process and program 
    has to wait.

3. Programing language used
    C is faster when compare to Java because it is low level language. Thus many network security applications
    are written in C, where speed matters. And also same for the other language.

4. Parallelism of the Program
    A multi-threaded program that is running on multicore machine will be faster. Sometimes certain number of threads work best for x-core machine.

5. I/O waiting time
    Sometimes I/O bounds like disk read/write speed affect the running time.

6. Amount of available memory
    Higher ram machines runs the processes quickly.

7. Overhead due to many function calls
    There could be a huge overhead on running if a function call is made multiple times for a small function. 
    This could be checked using Profiler like GNU gprof for C. Inline functions that are called many times to 
    avoid the stack overhead.

8. Recursion
    Recursion can cause a lot of overhead which increases the running time of an algorithm.

9. Caching

10. Garbage collection routines

By considering the above factors we can say that emphirical analysis vary to the machine to machine the it is not feasible to do empirical analysis when the goal is to compare two algorithms.