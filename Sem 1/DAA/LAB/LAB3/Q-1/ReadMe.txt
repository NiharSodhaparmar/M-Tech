System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm

    getSmallestLexicographicalOrder(s)
        01.  count[1...26]                                 
        02.  visited[1...26]
        03.  res
        04.  n = s.size
        05.  for i = 0 to n
        06.      count[s[i] - 'a']++
        07.  for i = 0 to n        
        08.      count[s[i] - 'a']--
        09.     if !visited[s[i] - 'a']
        10.         while res.size > 0 && res.back > s[i] && count[res.back - 'a'] > 0
        11.             visited[res.back - 'a'] = 0
        12.             res.pop
        13.         res += s[i]
        14.         visited[s[i] - 'a'] = 1
        15. return res


2. Asymptotic Analysis
    Time complexity : O(1) + O(1) + O(1) + O(1) + O(n+1) + O(n) + O(n+1) + O(n)= O(n)


3. Empirical Analysis
    Smallest in lexicographical order among all possible results: abefhntidgqcpjmokvxswyrz
    Time taken for string of length 100: 15 microseconds

    Smallest in lexicographical order among all possible results: abcdefghijklmnopqrstuvwxyz
    Time taken for string of length 1000: 24 microseconds

    Smallest in lexicographical order among all possible results: abcdefghijklmnopqrstuvwxyz
    Time taken for string of length 10000: 78 microseconds

    Smallest in lexicographical order among all possible results: abcdefghijklmnopqrstuvwxyz
    Time taken for string of length 100000: 799 microseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately linear which is matching with the asymptotic analysis.