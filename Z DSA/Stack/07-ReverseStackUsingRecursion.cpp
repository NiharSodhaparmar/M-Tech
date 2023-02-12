#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875

void pushAtBottom(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int temp = myStack.top();
    myStack.pop();

    pushAtBottom(myStack, x);

    myStack.push(temp);
}

void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int temp = stack.top();
    stack.pop();

    reverseStack(stack);

    pushAtBottom(stack, temp);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);
}