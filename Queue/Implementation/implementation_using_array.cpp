#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *a;
    int capacity;
    int rear;

public:
    Queue(int n)
    {
        capacity = n;
        a = new int[n];
        rear = -1;
    }
    bool isEmpty();
    bool isFull();
    void Enqueue(int data);
    int Dequeue();
    void printQ();
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

void Queue::printQ()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    for (int i = 0; i <= rear; i++)
        cout << a[i] << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Queue q(20);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    cout << q.Dequeue() << endl;

    q.printQ();
    return 0;
}