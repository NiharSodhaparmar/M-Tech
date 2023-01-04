#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int knapSack(int W, int w[], int v[], int n);
void display(int w[], int v[], int n);

int main()
{
    int w[] = {5, 5, 5, 5, 5, 5, 5};
    int v[] = {90, 80, 10, 85, 15, 55, 95};
    // int w[] = {5, 5, 5};
    // int v[] = {15, 100, 20};
    int W = 10;
    int n = sizeof(v) / sizeof(v[0]);

    auto start = high_resolution_clock::now();
    int ans = knapSack(W, w, v, n);
    auto end = high_resolution_clock::now();

    cout << "Given data: " << endl;
    display(w, v, n);

    cout << "Max Profit : " << ans << endl;

    cout << "Time taken for " << n << " objects and " << W << " size knapsack :  " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

    return 0;
}

int knapSack(int W, int w[], int v[], int n)
{
    int numberOfItem = W / w[0];

    for (int i = 0; i < numberOfItem; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] < v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }

    int ans = 0;
    for (int i = 0; i < numberOfItem; i++)
    {
        ans += v[i];
    }

    return ans;
}

void display(int w[], int v[], int n)
{
    cout << "Weight\tValue" << endl;
    for (int i = 0; i < n; i++)
        cout << w[i] << "\t" << v[i] << endl;
    cout << endl;
}
