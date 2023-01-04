#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

vector<pair<int, int>> makePair(vector<int> &w, vector<int> &v, int n);
void generate_job(vector<int> &w, vector<int> &v, int n);
bool sortbyratio(const pair<int, int> &a, const pair<int, int> &b);
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b);
double F_1(vector<pair<int, int>> vect, int n, int W);
double F_2(vector<pair<int, int>> vect, int n, int W);

void display(vector<pair<int, int>> vect, int n);

int main()
{
    vector<int> m = {10, 100, 1000, 10000, 100000};
    vector<int> weight;
    vector<int> value;
    int capicity = 2000;

    srand(time(0));
    for (int k = 0; k < m.size(); k++)
    {
        weight.clear();
        value.clear();
        int n = m[k];

        generate_job(weight, value, n);
        vector<pair<int, int>> vect = makePair(weight, value, n);

        auto start = high_resolution_clock::now();
        double F1 = F_1(vect, n, capicity);
        auto end = high_resolution_clock::now();
        auto duration_1 = duration_cast<nanoseconds>(end - start).count();

        start = high_resolution_clock::now();
        double F2 = F_2(vect, n, capicity);
        end = high_resolution_clock::now();
        auto duration_2 = duration_cast<nanoseconds>(end - start).count();

        double ratio = F1 / F2;

        cout << "=============================================================" << endl;
        cout << "Data set size : " << n << endl;
        cout << "Total Profit using optimal Solution : " << F1 << endl;
        cout << "Total Profit using given   Solution : " << F2 << endl;
        cout << "Time Taken using optimal Solution : " << duration_1 << " nanoseconds" << endl;
        cout << "Time Taken using given   Solution : " << duration_2 << " nanoseconds" << endl;
        cout << "Ratio = F*(I)/F(I)                  : " << ratio << endl;
        cout << "=============================================================" << endl;
    }

    return 0;
}

void display(vector<pair<int, int>> vect, int n)
{
    cout << "Weight\t\tValue" << endl;
    for (int i = 0; i < n; i++)
        cout << vect[i].first << "\t\t" << vect[i].second << endl;
    cout << endl;
}

vector<pair<int, int>> makePair(vector<int> &w, vector<int> &v, int n)
{
    vector<pair<int, int>> vect;
    for (int i = 0; i < n; i++)
        vect.push_back(make_pair(w[i], v[i]));
    return vect;
}

void generate_job(vector<int> &w, vector<int> &v, int n)
{
    for (int i = 1; i <= n; i++)
    {
        w.push_back(rand() % 1000);
        v.push_back(rand());
    }
}

bool sortbyratio(const pair<int, int> &a, const pair<int, int> &b)
{
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;
    return r1 > r2;
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

double F_1(vector<pair<int, int>> vect, int n, int W)
{
    sort(vect.begin(), vect.end(), sortbyratio);

    double ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vect[i].first <= W)
        {
            W -= vect[i].first;
            ans += vect[i].second;
        }
        else
        {
            ans += vect[i].second * ((double)W / (double)vect[i].first);
            break;
        }
    }

    return ans;
}

double F_2(vector<pair<int, int>> vect, int n, int W)
{
    sort(vect.begin(), vect.end(), sortbysec);

    double ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (vect[i].first <= W)
        {
            W -= vect[i].first;
            ans += vect[i].second;
        }
        else
        {
            ans += vect[i].second * ((double)W / (double)vect[i].first);
            break;
        }
    }

    return ans;
}
