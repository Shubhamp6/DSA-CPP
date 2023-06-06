#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class linkedList
{

public:
    Node *head;
    linkedList() { head = NULL; }

    void insertNode(int);
    void printList();
    void deleteNode(int);
    Node *reverse(Node *);
    bool isPalindromeLL(Node *);
};

void linkedList::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = NULL;
    int Listlen = 0;

    if (head == NULL)
    {
        cout << "Linked list is empty!" << endl;
        return;
    }

    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        Listlen++;
    }

    if (Listlen < nodeOffset)
    {
        cout << "Index out of range" << endl;
        return;
    }

    temp1 = head;

    if (nodeOffset == 1)
    {
        head = head->next;
        delete temp1;
        return;
    }
    while (nodeOffset-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;
}

void linkedList::insertNode(int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void linkedList::printList()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Linked list is empty." << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *linkedList::reverse(Node *head)
{
    if (head->next == NULL || head == NULL)
        return head;
    Node *newHead = reverse(head->next);
    Node *headNext = head->next;
    headNext->next = head;
    head->next = NULL;
    return newHead;
}

Node *middle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool linkedList::isPalindromeLL(Node *head)
{
    if (head == NULL)
        return true;

    Node *mid = middle(head);
    Node *last = reverse(mid->next);
    Node *cur = head;

    while (last != NULL)
    {
        if (last->data != cur->data)
            return false;

        last = last->next;
        cur = cur->next;
    }
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    linkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(5);
    list.insertNode(3);
    list.insertNode(2);
    list.insertNode(1);

    cout << list.isPalindromeLL(list.head) << endl;
    return 0;
}