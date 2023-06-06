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

int ans = 1;

int burn(struct Node *root, int target, int &depth)
{
    if (root == NULL)
        return 0;
    if (root->data == target)
    {
        depth = 1;
        return 1;
    }

    int ld = -1, rd = -1;
    int lh = burn(root->left, target, ld);
    int rh = burn(root->right, target, rd);

    if (ld != -1)
    {
        ans = max(ans, ld + 1 + rh);
        depth = ld + 1;
    }
    else if (rd != -1)
    {
        ans = max(ans, rd + 1 + lh);
        depth = rd + 1;
    }

    return max(lh, rh) + 1;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    int depth = -1;
    burn(root, 3, depth);
    cout << ans << endl;

    return 0;
}