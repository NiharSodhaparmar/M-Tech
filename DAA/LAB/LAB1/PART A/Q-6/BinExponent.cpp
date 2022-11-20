#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long long unsigned int binExponent(long long unsigned int a, long long unsigned int n)
{
    if (n == 0)
        return 1;

    long long unsigned int ans = binExponent(a, n / 2);

    if (n % 2)
        return ans * ans * a;
    else
        return ans * ans;
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

    cout << a << "^" << n << ": " << binExponent(a, n) << endl;

    auto end = high_resolution_clock::now();

    cout << "Time taken" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
}