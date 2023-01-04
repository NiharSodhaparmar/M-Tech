#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<pair<int, int>> makePair(vector<int> &st, vector<int> &et, int n);
void generate_job(vector<int> &start, vector<int> &end, int n);
void display(vector<pair<int, int>> vect, int n);
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b);
vector<pair<int, int>> maxActivitiesByFirst(vector<pair<int, int>> vect, int n);
vector<pair<int, int>> maxActivitiesByLast(vector<pair<int, int>> vect, int n);

int main()
{
    vector<int> m = {10, 100, 1000, 10000};
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

        // cout << endl
        //      << "Given Job Mix : " << endl;
        // display(vect, n);

        auto start = high_resolution_clock::now();
        vector<pair<int, int>> ans = maxActivitiesByFirst(vect, n);
        auto end = high_resolution_clock::now();

        // cout << endl
        //      << "Selected Jobs By First : " << endl;
        // display(ans, ans.size());

        cout << "Total Activity : " << n << endl;
        cout << "\tWhen selecting first activity first No of activities selected: " << ans.size() << endl;
        cout << "\twhen selecting first activity first : " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        start = high_resolution_clock::now();
        ans = maxActivitiesByLast(vect, n);
        end = high_resolution_clock::now();
        cout << "\tWhen selecting last activity first No of activities selected: " << ans.size() << endl;
        cout << "\twhen selecting last activity first : " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

        // cout << endl
        //      << "Selected Jobs By Last : " << endl;
        // display(ans, ans.size());
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

void display(vector<pair<int, int>> vect, int n)
{
    cout << "Start Time\tEnd Time" << endl;
    for (int i = 0; i < n; i++)
        cout << vect[i].first << "\t\t" << vect[i].second << endl;
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

vector<pair<int, int>> maxActivitiesByFirst(vector<pair<int, int>> vect, int n)
{
    vector<pair<int, int>> ans;
    sort(vect.begin(), vect.end(), sortbysec);

    int i = 0;
    ans.push_back(make_pair(vect[i].first, vect[i].second));

    for (int j = 1; j < n; j++)
    {
        if (vect[j].first >= vect[i].second)
        {
            ans.push_back(make_pair(vect[j].first, vect[j].second));
            i = j;
        }
    }
    return ans;
}

vector<pair<int, int>> maxActivitiesByLast(vector<pair<int, int>> vect, int n)
{
    vector<pair<int, int>> ans;
    sort(vect.rbegin(), vect.rend(), sortbysec);

    int i = 0;
    ans.push_back(make_pair(vect[i].first, vect[i].second));

    for (int j = 1; j < n; j++)
    {
        if (vect[i].first >= vect[j].second)
        {
            ans.push_back(make_pair(vect[j].first, vect[j].second));
            i = j;
        }
    }
    return ans;
}