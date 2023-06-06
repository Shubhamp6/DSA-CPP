#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class Stack
{
    int top;

public:
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

int32_t
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    class Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.pop() << endl;

    cout << s.peek() << endl;
    return 0;
}