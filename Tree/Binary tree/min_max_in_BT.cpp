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

int maximum(struct Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(struct Node *root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    cout << maximum(root) << " " << minimum(root) << endl;

    return 0;
}