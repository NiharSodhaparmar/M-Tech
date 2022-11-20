#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    vector<int> l = {0, 10, 1, 10, 10};
    vector<int> h = {0, 5, 50, 70, 1};
    int n = l.size();
    vector<int> F(n);

    F[0] = 0;
    F[1] = max(l[1], h[1]);

    for (int i = 2; i < n; i++)
    {
        F[i] = max(l[i] + F[i - 1], h[i] + F[i - 2]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << F[i] << "\t";
    }

    return 0;
}