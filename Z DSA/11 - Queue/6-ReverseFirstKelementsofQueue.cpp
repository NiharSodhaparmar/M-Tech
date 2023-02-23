#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

queue<int> modifyQueue(queue<int> q, int k)
{
    int n = q.size();
    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
}

void printQueue(queue<int> q)
{
    // printing content of queue
    while (!q.empty())
    {
        cout << " " << q.front();
        q.pop();
    }
    cout << endl;
}

int main()
{
    int k = 3;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Queue Before: ";
    printQueue(q);

    q = modifyQueue(q, 3);

    cout << "Queue After: ";
    printQueue(q);

    cout << endl;
}