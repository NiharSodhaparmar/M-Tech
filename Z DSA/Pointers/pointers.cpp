#include <iostream>
using namespace std;

int *danglingFun()
{
    int x = 10;
    return &x;
}

int main()
{
    // int *p = NULL;
    // cout << "p " << p << endl;

    // int *k = 0;
    // cout << "k " << k << endl;

    // void *vp = NULL;
    // int i = 10;
    // vp = &i;

    // cout << "VOID " << vp << endl;
    // cout << "* VOID " << *(int *)vp << endl;

    // int *dp = danglingFun();
    // cout << "DP " << dp << endl;

    // float f = 10.5;
    // float p = 2.5;
    // float *ptr = &f;
    // (*ptr)++;
    // cout << *ptr << " " << f << " " << p << endl;
    // *ptr = p;
    // cout << *ptr << " " << f << " " << p << endl;

    cout << sizeof(float) << endl;
}