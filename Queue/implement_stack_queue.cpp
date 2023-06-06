#include <bits/stdc++.h>
using namespace std;
#define n 20

class Queue
{

    int *a;
    int capacity;
    int rear;

public:
    Queue()
    {
        capacity = n;
        a = new int[n];
        rear = -1;
    }
    bool isEmpty();
    bool isFull();
    void Enqueue(int data);
    int Dequeue();
};

bool Queue::isEmpty()
{
    if (rear == -1)
        return 1;
    return 0;
}

bool Queue::isFull()
{
    if (rear == capacity - 1)
        return 1;
    return 0;
}

void Queue::Enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue overflow" << endl;
        return;
    }
    a[++rear] = data;
    cout << data << " is Enqueued in queue" << endl;
}

int Queue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int data = a[0];
    for (int i = 0; i < rear; i++)
        a[i] = a[i + 1];
    rear--;
    return data;
}

class Stack
{

    Queue q1;
    Queue q2;

public:
    void push(int data)
    {
        if (q1.isFull())
        {
            cout << "Stack overflow" << endl;
        }

        while (!q1.isEmpty())
        {
            q2.Enqueue(q1.Dequeue());
        }
        q1.Enqueue(data);
        while (!q2.isEmpty())
        {
            q1.Enqueue(q2.Dequeue());
        }
    }

    int pop()
    {
        return q1.Dequeue();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.pop() << endl;
    return 0;
}