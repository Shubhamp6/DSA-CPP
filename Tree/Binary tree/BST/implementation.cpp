#include <bits/stdc++.h>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:
    BST();
    BST(int);
    BST *insert(BST *, int);
    void inOrder(BST *);
};

BST ::BST() : data(0), left(NULL), right(NULL)
{
}

BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST *BST::insert(BST *root, int value)
{
    if (!root)
    {
        return new BST(value);
    }
    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        root->left = insert(root->left, value);
    }

    return root;
}

void BST::inOrder(BST *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    b.inOrder(root);
    return 0;
}