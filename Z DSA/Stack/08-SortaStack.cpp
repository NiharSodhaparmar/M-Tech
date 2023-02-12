#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275

void insertInSortedOrder(stack<int> &stack, int element)
{
    if (stack.empty())
    {
        stack.push(element);
        return;
    }

    int temp = stack.top();
    if (temp < element)
    {
        stack.push(element);
        return;
    }
    stack.pop();

    insertInSortedOrder(stack, element);

    stack.push(temp);
}

void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }

    int temp = stack.top();
    stack.pop();

    sortStack(stack);

    insertInSortedOrder(stack, temp);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    sortStack(s);
}