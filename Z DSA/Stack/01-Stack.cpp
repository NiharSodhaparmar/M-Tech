#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element)
    {
        top++;
        if (top >= size)
        {
            cout << "Stack overflow" << endl;
            top--;
            return;
        }

        arr[top] = element;
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Stack s(5);

    s.push(22);
    s.push(43);
    s.push(44);
    s.push(45);
    s.push(55);
    // s.push(10);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top element: " << s.peek() << endl;
    cout << "Top: " << s.top << endl;

    s.pop();
    s.pop();
    s.pop();
    cout << "Stack is empty?: " << (s.isEmpty() ? "True" : "False") << endl;
}