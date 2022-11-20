#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std ::chrono;

#define vi vector<int>
#define vii vector<vi>

void display(vii C, int m, int n);
void basicMatrixMultiplication(vii &A, vii &B, vii &C, int r1, int c1, int r2, int c2);

int main()
{
    // vii a = {
    //     {1, 2, 3},
    //     {1, 2, 3},
    //     {0, 0, 2}};
    // vii b = {
    //     {1, 0, 0},
    //     {0, 1, 0},
    //     {0, 0, 1}};

    cout << "Basic Multiplication: " << endl;

    for (int k = 10; k <= 100; k = k * 10)
    {
        int r1 = k;
        int c1 = k;
        int r2 = k;
        int c2 = k;

        vii a;

        for (int i = 0; i < r1; i++)
        {
            vi temp;
            for (int j = 0; j < c1; j++)
            {
                temp.push_back(i + j);
            }
            a.push_back(temp);
        }

        vii b;

        for (int i = 0; i < r1; i++)
        {
            vi temp;
            for (int j = 0; j < c1; j++)
            {
                temp.push_back(i + j);
            }
            b.push_back(temp);
        }

        vi z(c2);
        vii c(r1, z);

        auto start = high_resolution_clock::now();
        basicMatrixMultiplication(a, b, c, r1, c1, r2, c2);
        auto end = high_resolution_clock::now();

        // cout << "Output Matrix: " << endl;
        // display(c, r1, c2);
        cout << r1 << " * " << r2 << " matrix" << endl;
        cout << "\tTime taken to multipy matrix : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;
        cout << endl;
    }

    return 0;
}

void display(vii C, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        cout << "|"
             << " ";
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

void basicMatrixMultiplication(vii &A, vii &B, vii &C, int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < r2; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}