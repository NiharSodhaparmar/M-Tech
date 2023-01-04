System Specifications:
Operating System: Windows
Compiler: g++

Program File: LectureScheduling.cpp
Command to run code: g++ LectureScheduling.cpp -o LectureScheduling & LectureScheduling.exe
Snapshots: Output.jpg


1. Algorithm

    getNumberOfClassroomScheduled(lectures, n)
        01.  d <- Φ   /* ans =  Set of selected mutually compatible jobs */                                 
        02.  sort lectures by their start time                                          
        03.  for j = 1 to n
        04.      if lecture j is compatible with some classroom k 
        05.              schedule lecture j in class room k
        06.      else
        07.          allocate a new classroom d + 1
        08.          schedule lecture j in classroom d + 1
        09.          d <- (d + 1)    
        10.  return d


2. Asymptotic Analysis
    Time complexity : O(1) + O(nlogn) + O(n) + O(1) = O(nlogn)


3. Empirical Analysis
    Answer : 6
    Time taken for 10 activities : 8000 nanoseconds

    Answer : 10
    Time taken for 20 activities : 14000 nanoseconds

    Answer : 19
    Time taken for 30 activities : 17000 nanoseconds

    Answer : 20
    Time taken for 40 activities : 58000 nanoseconds

    Answer : 30
    Time taken for 50 activities : 27000 nanoseconds

    Answer : 32
    Time taken for 60 activities : 38000 nanoseconds

    Answer : 37
    Time taken for 70 activities : 46000 nanoseconds

    Answer : 37
    Time taken for 80 activities : 74000 nanoseconds

    Answer : 51
    Time taken for 90 activities : 54000 nanoseconds

    Answer : 53
    Time taken for 100 activities : 2012000 nanoseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(nlogn) which is matching with the asymptotic analysis.