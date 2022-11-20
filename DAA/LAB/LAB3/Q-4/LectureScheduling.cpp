#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<pair<int, int>> makePair(vector<int> &st, vector<int> &et, int n);
int minLectureHall_Method1(vector<pair<int, int>> vect, int n);
int minLectureHall_Method2(int st[], int et[], int n);
void generate_job(vector<int> &start, vector<int> &end, int n);

int main()
{
    vector<int> m = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> st;
    vector<int> et;

    srand(time(0));
    for (int k = 0; k < m.size(); k++)
    {
        st.clear();
        et.clear();
        int n = m[k];

        generate_job(st, et, n);

        vector<pair<int, int>> vect = makePair(st, et, n);

        auto start = high_resolution_clock::now();
        int ans = minLectureHall_Method1(vect, n);
        auto end = high_resolution_clock::now();

        cout << endl
             << "Answer : " << ans;

        cout << endl
             << "Time taken for " << n << " activities : " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
    }

    return 0;
}

void generate_job(vector<int> &start, vector<int> &end, int n)
{
    int s;
    int e;
    for (int i = 1; i <= n; i++)
    {
        s = rand() % 24;
        e = s + (rand() % 24);

        start.push_back(s);
        end.push_back(e);
    }
}

vector<pair<int, int>> makePair(vector<int> &st, vector<int> &et, int n)
{
    vector<pair<int, int>> vect;
    for (int i = 0; i < n; i++)
        vect.push_back(make_pair(st[i], et[i]));
    return vect;
}

int minLectureHall_Method1(vector<pair<int, int>> vect, int n)
{
    sort(vect.begin(), vect.end());
    vector<int> time(50);
    int d = 0;

    d++;
    time[d] = vect[0].second;

    for (int i = 1; i < n; i++)
    {
        int flag = 0;
        for (int j = 1; j <= d; j++)
        {
            if (vect[i].first >= time[j])
            {
                time[j] = vect[i].second;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            d++;
            time[d] = vect[i].second;
        }
    }
    return d;
}

int minLectureHall_Method2(int st[], int et[], int n)
{
    vector<pair<int, int>> time;

    for (int i = 0; i < n; i++)
    {
        time.push_back({st[i], 1});
        time.push_back({et[i], -1});
    }
    sort(time.begin(), time.end());

    int answer = 0, sum = 0;

    for (int i = 0; i < time.size(); i++)
    {
        sum += time[i].second;
        answer = max(answer, sum);
    }
    return answer;
}