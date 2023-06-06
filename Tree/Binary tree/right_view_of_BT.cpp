#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *right, *left;

    Node(int val)
    {
        data = val;

        right = NULL;
        left = NULL;
    }
};

void rightViewUtil(struct Node *root, int level, int &max_level)
{
    if (root == NULL)
        return;
    if (max_level < level)
    {
        cout << root->data << " ";
        max_level = level;
    }

    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, max_level);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    rightView(root);

    return 0;
}