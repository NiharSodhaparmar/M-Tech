#include <bits/stdc++.h>
#include <stack>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246

void deleteElement(stack<int> &inputStack, int N, int count)
{
    if (count == N / 2)
    {
        inputStack.pop();
        return;
    }

    int temp = inputStack.top();
    inputStack.pop();

    deleteElement(inputStack, N, count++);

    inputStack.push(temp);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    deleteElement(inputStack, N, count);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMiddle(s, s.size() - 1);
}