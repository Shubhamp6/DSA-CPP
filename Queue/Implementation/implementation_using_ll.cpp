#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *front, *rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty();
    void Enqueue(int data);
    int Dequeue();
    void printQ();
};

bool Queue::isEmpty()
{
    if (front == NULL || front > rear)
        return 1;
    return 0;
}

void Queue::Enqueue(int data)
{
    Node *newNode = new Node(data);
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        cout << rear->data << " is Enqueued is queue." << endl;
        return;
    }
    rear->next = newNode;
    rear = rear->next;
    cout << rear->data << " is Enqueued in queue." << endl;
}

int Queue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    Node *temp;
    temp = front;
    front = front->next;
    int data = temp->data;
    free(temp);
    cout << "Dequeue successful" << endl;
    return data;
}

void Queue::printQ()
{
    if (isEmpty())
    {
        cout << "Queue underflow" << endl;
        return;
    }
    Node *temp = front;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL);
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    q.Dequeue();

    q.printQ();
    return 0;
}