#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class Stack
{

public:
    int top;
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack overflow" << endl;
        return false;
    }
    else
    {
        a[++top] = x;
        cout << x << " is pushed in stack" << endl;
        return true;
    }
}

int Stack::pop()
{
    if (top == -1)
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    else
    {
        int x = a[top];
        top--;
        cout << "Number popped successfuly" << endl;
        return x;
    }
}

int Stack::peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        return a[top];
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

class Queue
{
    Stack s1, s2;

public:
    void push(int data)
    {
        s1.push(data);
    }

    int pop()
    {

        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        int data = s2.pop();
        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
        return data;
    }
    int peek()
    {

        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        int data = s2.peek();
        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
        return data;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.pop() << " " << q.peek() << endl;

    return 0;
}