#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "nihar";
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string reverseStr = "";

    while (!s.empty())
    {
        reverseStr.push_back(s.top());
        s.pop();
    }

    for (int i = 0; i < reverseStr.length(); i++)
    {
        cout << reverseStr[i];
    }
    cout << endl;
}