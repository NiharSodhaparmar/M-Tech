#include <bits/stdc++.h>
using namespace std;

void pushInStack(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int temp = myStack.top();
    myStack.pop();

    pushInStack(myStack, x);

    myStack.push(temp);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    pushInStack(myStack, x);
    return myStack;
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    pushAtBottom(s, 10);
}