#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

int knapSack(int W, vector<int> w, vector<int> v, int n);
void display(vector<int> w, vector<int> v, int n);

int main()
{
    int W = 330;
    vector<int> n = {10, 100, 1000, 10000};

    vector<int> w;
    vector<int> v;

    int temp = 1;

    for (int k = 0; k < n.size(); k++)
    {
        for (int i = 0; i < n[k]; i++)
        {
            w.push_back(temp);
            v.push_back(temp * 10);
        }

        // cout << "Given data: " << endl;
        // display(w, v, n[k]);

        auto start = high_resolution_clock::now();
        int ans = knapSack(W, w, v, n[k]);
        auto end = high_resolution_clock::now();

        cout << "For n = " << n[k] << endl;
        cout << "\tMax Profit for W = " << W << " : " << ans << endl;
        cout << "\tTime taken: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
        cout << endl;
    }

    return 0;
}

int knapSack(int W, vector<int> w, vector<int> v, int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (W - w[i] >= 0)
        {
            ans += v[i];
            W -= w[i];
        }
        else
        {
            break;
        }
    }

    return ans;
}

void display(vector<int> w, vector<int> v, int n)
{
    cout << "Weight\tValue" << endl;
    for (int i = 0; i < n; i++)
        cout << w[i] << "\t" << v[i] << endl;
    cout << endl;
}
