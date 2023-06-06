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

struct Node *lowestCommonAncestor(struct Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    struct Node *left = lowestCommonAncestor(root->left, n1, n2);
    struct Node *right = lowestCommonAncestor(root->right, n1, n2);

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    return root;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    cout << lowestCommonAncestor(root, 4, 2)->data << endl;

    return 0;
}