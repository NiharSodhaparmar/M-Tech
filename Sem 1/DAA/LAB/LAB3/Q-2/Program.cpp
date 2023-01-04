#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <climits>
#include "max_heap.h"
using namespace std;
using namespace std::chrono;

vector<vector<int>> interval_scheduling(vector<int> &start, vector<int> &end)
{
    vector<vector<int>> compatible;
    vector<int> mid_night_job_start;
    vector<int> mid_night_job_end;
    vector<int> normal_job_start;
    vector<int> normal_job_end;

    int i = 0;
    while (i != start.size() - 1)
    {
        if (start[i] > end[i])
        {
            mid_night_job_start.push_back(start[i]);
            mid_night_job_end.push_back(end[i]);
        }
        else
        {
            normal_job_start.push_back(start[i]);
            normal_job_end.push_back(end[i]);
        }
        i++;
    }

    int n = -1;
    max_heapsort(mid_night_job_end, mid_night_job_start, mid_night_job_start.size());
    max_heapsort(normal_job_end, normal_job_start, normal_job_start.size());

    if (mid_night_job_start.size() > 0 && normal_job_end.size() > 0)
    {
        if (mid_night_job_end[0] < normal_job_end[0])
        {
            compatible.push_back({mid_night_job_start[0], mid_night_job_end[0]});
            n = 0;
        }
    }

    for (int i = 0; i < normal_job_end.size(); i++)
    {
        if (n == -1)
        {
            compatible.push_back({normal_job_start[i], normal_job_end[i]});
            n = 0;
        }
        else
        {
            if (normal_job_start[i] >= compatible[n][1])
            {
                compatible.push_back({normal_job_start[i], normal_job_end[i]});
                n++;
            }
        }
    }
    return compatible;
}

void generate_job(vector<int> &start, vector<int> &end, int n)
{
    start.clear();
    end.clear();
    int s;
    int e;
    for (int i = 1; i <= n; i++)
    {
        s = rand() % 24 + 1;
        e = rand() % 24 + 1;
        while (s == e)
        {
            e = rand() % 24 + 1;
        }

        start.push_back(s);
        end.push_back(e);
    }
}

int main()
{
    vector<int> start;
    vector<int> end;
    vector<int> size = {100, 1000, 10000, 100000};
    srand(time(0));
    for (int j = 0; j < size.size(); j++)
    {

        generate_job(start, end, size[j]);
        auto start1 = high_resolution_clock::now();
        vector<vector<int>> interval = interval_scheduling(start, end);
        auto end1 = high_resolution_clock::now();
        cout << "For Job = " << size[j] << endl;
        cout << "\t Time Taken : " << fixed << duration_cast<microseconds>(end1 - start1).count() << setprecision(6) << " Microsecond" << endl;
        cout << "\t Number of Job Select : " << interval.size() << endl;
    }

    return 0;
}