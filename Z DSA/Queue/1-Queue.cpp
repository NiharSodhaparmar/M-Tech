#include <iostream>
using namespace std;

class Queue
{
public:
    int qfront;
    int rear;
    int size;
    int *arr;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    void enqueue(int element)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
            return;
        }

        arr[rear] = element;
        rear++;
    }

    int dequeue()
    {
        if (qfront == rear)
        {
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return qfront;
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }

        return arr[qfront];
    }

    bool isEmpty()
    {
        if (qfront == rear)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Queue q = Queue(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Queue front: " << q.front() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }

    cout << "Queue deque: " << q.dequeue() << endl;
    cout << "Queue deque: " << q.dequeue() << endl;
}
