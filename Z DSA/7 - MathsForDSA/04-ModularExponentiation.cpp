#include <iostream>
using namespace std;

long long unsigned int modularExponentiation(int x, int n, int m)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (1LL * res * (x) % m) % m;

        x = (1LL * (x) % m * (x) % m);
        n = n >> 1;
    }
    return res;
}

int main()
{
    long long unsigned int x;
    long long unsigned int n;
    long long unsigned int m;
    cout << "(x ^ n) % m" << endl;
    cout << "Enter value for x: " << endl;
    cin >> x;
    cout << "Enter value for n: " << endl;
    cin >> n;
    cout << "Enter value for m: " << endl;
    cin >> m;

    cout << x << "^" << n << "%" << m << ": " << modularExponentiation(x, n, m) << endl;
    return 0;
}
