#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a;
}

int main()
{
    int a, b;
    cout << "Enter two numbers a and b: " << endl;
    cin >> a >> b;
    cout << "GCD of a = " << a << " and b = " << b << " is " << gcd(a, b);
    return 0;
}