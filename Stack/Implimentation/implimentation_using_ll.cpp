#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
};

StackNode *newNode(int data)
{
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode *head)
{
    return !head;
}

StackNode *push(StackNode *head, int data)
{
    StackNode *stackNode = newNode(data);
    stackNode->next = head;
    head = stackNode;
    cout << data << " is pushed in stack" << endl;
    return stackNode;
}

int pop(StackNode **head)
{
    if (isEmpty(*head))
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    StackNode *temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    cout << "Element popped successfuly" << endl;
    return data;
}

int peek(StackNode *head)
{
    if (isEmpty(head))
    {
        cout << "Stack underflow" << endl;
        return -1;
    }
    return head->data;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    StackNode* head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    cout << pop(&head) << endl;

    return 0;
}