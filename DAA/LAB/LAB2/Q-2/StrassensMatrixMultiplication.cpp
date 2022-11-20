#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std ::chrono;

#define vi vector<int>
#define vii vector<vi>

int nextPowerOf2(int k);
void addMatrix(vii &A, vii &B, vii &C, int size);
void subMatrix(vii &A, vii &B, vii &C, int size);
void display(vii C, int m, int n);
void ConvertToSquareMatrix(vii &A, vii &B, vii &C, int r1, int c1, int r2, int c2);
void StrassenMatrixMultiplication(vii &A, vii &B, vii &C, int size);

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

    cout << "Starseen Multiplication: " << endl;

    for (int k = 10; k <= 1000; k = k * 10)
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
        ConvertToSquareMatrix(a, b, c, r1, c1, r2, c2);
        auto end = high_resolution_clock::now();

        // display(c, r1, c2);
        cout << r1 << " * " << r2 << " matrix" << endl;
        cout << "\tTime taken to multipy matrix : " << duration_cast<microseconds>(end - start).count() << " microsecond" << endl;
        cout << endl;
    }

    return 0;
}

int nextPowerOf2(int k)
{
    return pow(2, int(ceil(log2(k))));
}

void addMatrix(vii &A, vii &B, vii &C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subMatrix(vii &A, vii &B, vii &C, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
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

void StrassenMatrixMultiplication(vii &A, vii &B, vii &C, int size)
{
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int newSize = size / 2;
        vi z(newSize);
        vii a(newSize, z), b(newSize, z), c(newSize, z), d(newSize, z), e(newSize, z), f(newSize, z), g(newSize, z), h(newSize, z), c11(newSize, z), c12(newSize, z), c21(newSize, z), c22(newSize, z), p1(newSize, z), p2(newSize, z), p3(newSize, z), p4(newSize, z), p5(newSize, z), p6(newSize, z), p7(newSize, z), fResult(newSize, z), sResult(newSize, z);
        int i, j;

        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                a[i][j] = A[i][j];
                b[i][j] = A[i][j + newSize];
                c[i][j] = A[i + newSize][j];
                d[i][j] = A[i + newSize][j + newSize];

                e[i][j] = B[i][j];
                f[i][j] = B[i][j + newSize];
                g[i][j] = B[i + newSize][j];
                h[i][j] = B[i + newSize][j + newSize];
            }
        }

        // p1=a*(f-h)
        subMatrix(f, h, sResult, newSize);
        StrassenMatrixMultiplication(a, sResult, p1, newSize);

        // p2=h*(a+b)
        addMatrix(a, b, fResult, newSize);
        StrassenMatrixMultiplication(fResult, h, p2, newSize);

        // p3=e*(c+d)
        addMatrix(c, d, fResult, newSize);
        StrassenMatrixMultiplication(fResult, e, p3, newSize);

        // p4=d*(g-e)
        subMatrix(g, e, sResult, newSize);
        StrassenMatrixMultiplication(d, sResult, p4, newSize);

        // p5=(a+d)*(e+h)
        addMatrix(a, d, fResult, newSize);
        addMatrix(e, h, sResult, newSize);
        StrassenMatrixMultiplication(fResult, sResult, p5, newSize);

        // p6=(b-d)*(g+h)
        subMatrix(b, d, fResult, newSize);
        addMatrix(g, h, sResult, newSize);
        StrassenMatrixMultiplication(fResult, sResult, p6, newSize);

        // p7=(a-c)*(e+f)
        subMatrix(a, c, fResult, newSize);
        addMatrix(e, f, sResult, newSize);
        StrassenMatrixMultiplication(fResult, sResult, p7, newSize);

        /* calculating all elements of C by p1,p2,p3
        c11=p4+p5+p6-p2
        c12=p1+p2
        c21=p3+p4
        c22=p1-p3+p5-p7
        */

        addMatrix(p1, p2, c12, newSize);
        addMatrix(p3, p4, c21, newSize);

        addMatrix(p4, p5, fResult, newSize);
        addMatrix(fResult, p6, sResult, newSize);
        subMatrix(sResult, p2, c11, newSize);

        subMatrix(p1, p3, fResult, newSize);
        addMatrix(fResult, p5, sResult, newSize);
        subMatrix(sResult, p7, c22, newSize);

        for (i = 0; i < newSize; i++)
        {
            for (j = 0; j < newSize; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + newSize] = c12[i][j];
                C[i + newSize][j] = c21[i][j];
                C[i + newSize][j + newSize] = c22[i][j];
            }
        }
    }
}

void ConvertToSquareMatrix(vii &A, vii &B, vii &C, int r1, int c1, int r2, int c2)
{
    int maxSize = max(max(r1, c1), max(r2, c2));
    int size = nextPowerOf2(maxSize);

    vi z(size);
    vii Aa(size, z), Bb(size, z), Cc(size, z);

    for (unsigned int i = 0; i < r1; i++)
    {
        for (unsigned int j = 0; j < c1; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < r2; i++)
    {
        for (unsigned int j = 0; j < c2; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }

    StrassenMatrixMultiplication(Aa, Bb, Cc, size);

    for (unsigned int i = 0; i < r1; i++)
    {
        for (unsigned int j = 0; j < c2; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }
}