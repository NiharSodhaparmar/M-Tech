#include <bits/stdc++.h>
using namespace std;

int N = 0;
vector<char> vertices;

int main()
{
    char v;
    char vIn[3];

    cout << "Please input your vertices:" << endl;
    while (true)
    {
        cin.getline(vIn, 3);

        if (!strcmp(vIn, "end"))
        {
            break;
        }
        else
        {
            cout << "Not fine";
            vertices[N] = vIn[0];
            N++;
        }
    }

    cout << "Ok fine";

    for (int i = 0; i < N; i++)
    {
        cout << vertices[i] << endl;
    }
}