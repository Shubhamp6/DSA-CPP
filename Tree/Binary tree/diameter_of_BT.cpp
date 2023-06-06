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

// Complexity T - O(n^2) S - O(1)
/*int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(struct Node *root)
{
    if (root == NULL)
        return 0;
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int curr = 1 + height(root->left) + height(root->right);
    return max(curr, max(ld, rd));
}*/

// Complexity T - O(n) S - O(1)
int ans = 0;
int height(struct Node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    ans = max(ans, 1 + lh + rh);
    return 1 + max(lh, rh);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    height(root);
    cout << ans << endl;

    return 0;
}