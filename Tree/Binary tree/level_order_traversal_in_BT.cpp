#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int val)
    {
        data = val;

        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(struct Node *root)
{
    queue<struct Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        struct Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            if (q.empty())
                return;
            q.push(NULL);
            cout << endl;
            continue;
        }

        cout << curr->data << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    levelOrderTraversal(root);
    return 0;
}