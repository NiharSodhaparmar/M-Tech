#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void code1(long long int n)
{
    long long int x = 0;
    for (long long int i = 1; i < n; i++)
    {
        for (long long int j = 1; j < i; j++)
        {
            x = x + 1;
        }
    }
    cout << "x for code 1: " << x << endl;
}

void code2(long long int n)
{
    long long int j = n;
    long long int x = 0;
    while (j >= 1)
    {
        for (long long int i = 1; i < j; i++)
        {
            x = x + 1;
        }
        j = n / 2;
    }
    cout << "x for code 2: " << x << endl;
}

void code3(long long int n)
{
    long long int x = 0;
    for (long long int i = 1; i < n; i++)
    {
        for (long long int j = 1; j < i; j++)
        {
            for (long long int k = 1; k < i; k++)
            {
                x = x + 1;
            }
        }
    }
    cout << "x for code 3: " << x << endl;
}

void code4(long long int n)
{
    int i = n;
    long long int x;
    while (i >= 1)
    {
        for (int j = 1; j < n; j++)
        {
            x = x + 1;
            i = i / 2;
        }
    }
    cout << "x for code 4: " << x << endl;
}

int main()
{
    int N;
    cout << "Enter value of N: " << endl;
    cin >> N;
    auto start = high_resolution_clock::now();
    code1(N);
    auto end = high_resolution_clock::now();
    cout << "Time taken for code 1" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
    cout << endl;

    // Commented due runs in infinite loop because of j = n/2
    // start = high_resolution_clock::now();
    // code2(N);
    // end = high_resolution_clock::now();
    // cout << "Time taken for code 2" << endl;
    // cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    // cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
    // cout << endl;

    start = high_resolution_clock::now();
    code3(N);
    end = high_resolution_clock::now();
    cout << "Time taken for code 3" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
    cout << endl;

    start = high_resolution_clock::now();
    code4(N);
    end = high_resolution_clock::now();
    cout << "Time taken for code 4" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
    cout << endl;

    return 0;
}