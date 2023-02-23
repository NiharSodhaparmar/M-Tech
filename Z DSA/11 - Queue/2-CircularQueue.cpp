#include <iostream>
using namespace std;

class MyCircularQueue
{
private:
    int rear, front;
    int *arr;
    int size;

public:
    MyCircularQueue(int k)
    {
        this->rear = -1;
        this->front = -1;
        this->size = k;
        this->arr = new int[k];
    }

    bool enQueue(int value)
    {
        if ((front == 0 && rear == size) || (front == ((rear + 1) % (size))))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = value;
            return true;
        }
        else
        {
            rear = (rear + 1) % (size);
            arr[rear] = value;
            return true;
        }

        return false;
    }

    bool deQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return false;
        }

        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % (size);
        }

        return true;
    }

    int Front()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[front];
    }

    int Rear()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }

        return false;
    }

    bool isFull()
    {
        if (((rear + 1) % (size)) == front)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    MyCircularQueue q = MyCircularQueue(3);

    cout << q.enQueue(1) << endl;
    cout << q.enQueue(2) << endl;
    cout << q.enQueue(3) << endl;
    cout << q.enQueue(4) << endl;

    cout << q.Rear() << endl;
    cout << q.isFull() << endl;

    return 0;
}