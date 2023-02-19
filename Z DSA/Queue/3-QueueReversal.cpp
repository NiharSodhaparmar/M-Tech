#include <queue>
#include <stack>
using namespace std;

// https://practice.geeksforgeeks.org/problems/queue-reversal/1

queue<int> rev(queue<int> q)
{
    stack<int> s;
    queue<int> newQ;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        newQ.push(s.top());
        s.pop();
    }

    return newQ;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
}