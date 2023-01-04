System Specifications:
Operating System: Windows
Compiler: g++

Program File: Program.cpp
Command to run code: g++ Program.cpp -o Program & Program.exe
Snapshots: Output.jpg


1. Algorithm

    getMinGasStation(tankCap, totalDist, gasStations[], n)
        01. fuelRemaining = tankCap
        02. ans[]
        03. if ((totalDist - gasStations[n - 1] > tankCap) || (gasStations[1] - gasStations[0] > tankCap))
        04.     return ans
        05. for i = 1 to n-1
        06.     fuelRemaining = fuelRemaining - (gasStations[i] - gasStations[i - 1])
        07.     if (gasStations[i + 1] - gasStations[i] > tankCap)
        08.         return
        09.     else if (gasStations[i + 1] - gasStations[i] > fuelRemaining)
        10.         ans.push_back(i)
        11.         fuelRemaining = tankCap
        12. return ans


2. Asymptotic Analysis
    Time complexity: O(1) + O(1) + O(1) + O(n) + O(1) = O(n)
    

3. Empirical Analysis
    1.  Tank capacity: 100 kms
        Total distance: 800 kms
        Gas Stations: 100 200 250 300 350 400 420 500 550 650 700

        No of statios that have to stop: 7
        Gas stations where to stop: 200 300 400 500 550 650 700
        Time taken: 22000 nanoseconds

    2.  Tank capacity: 100 kms
        Total distance: 2000 kms
        Gas Stations: 100 200 300 400 500 600 700 800 900 1000 1100 1200 1300 1400 1500 1600 1700 1800 1900

        No of statios that have to stop: 18
        Gas stations where to stop: 200 300 400 500 600 700 800 900 1000 1100 1200 1300 1400 1500 1600 1700 1800 1900
        Time taken: 25000 nanoseconds


4. Conclusion
    For the above inputs we can see that the time taken is approximately O(n) which is matching with the asymptotic analysis.