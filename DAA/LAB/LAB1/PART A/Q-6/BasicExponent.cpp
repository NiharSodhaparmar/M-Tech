#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long unsigned int exponent(long long unsigned int a, long long unsigned int n)
{
    long long unsigned int ans = a;
    for (long long unsigned int i = 1; i < n; i++)
    {
        ans = ans * a;
    }
    return ans;
}

int main()
{
    long long unsigned int a;
    long long unsigned int n;
    cout << "a ^ n" << endl;
    cout << "Enter value for a: " << endl;
    cin >> a;
    cout << "Enter value for n: " << endl;
    cin >> n;

    auto start = high_resolution_clock::now();

    cout << a << "^" << n << ": " << exponent(a, n) << endl;

    auto end = high_resolution_clock::now();

    cout << endl;
    cout << "Time taken" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
}