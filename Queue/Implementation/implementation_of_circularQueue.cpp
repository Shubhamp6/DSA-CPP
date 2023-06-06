#include <bits/stdc++.h>
using namespace std;

class circularArrayQueue
{
    int *a;
    int n;
    int front = -1, rear = -1;

public:
    circularArrayQueue(int size)
    {
        this->n = size;
        a = new int[n];
    }
    bool isEmpty();
    bool isFull();
    void Enqueue(int data);
    int Dequeue();
    void printQ();
};

bool circularArrayQueue::isEmpty()
{
    if (rear == -1)
        return 1;
    return 0;
}

bool circularArrayQueue::isFull()
{
    if (front == (rear + 1) % n)
        return 1;
    return 0;
}

void circularArrayQueue::Enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue overflow" << endl;
        return;
    }
    if (front == -1)
        front = (front + 1) % n;
    rear = (rear + 1) % n;
    a[rear] = data;
    cout << a[rear] << " is Enqueued successfully" << endl;
}

int circularArrayQueue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int data = a[front];
    front = (front + 1) % n;
    return data;
}

void circularArrayQueue::printQ()
{
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        return;
    }
    int i = front;
    while (i <= rear)
    {
        cout << a[i] << " ";
        i = (i + 1) % n;
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    circularArrayQueue q(20);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    cout << q.Dequeue() << endl;

    q.printQ();
    return 0;
}