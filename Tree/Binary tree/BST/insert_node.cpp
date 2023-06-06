#include <bits/stdc++.h>
using namespace std;

class BST
{
    int data;
    BST *left, *right;

public:
    BST();
    BST(int);
    BST *insertRecusive(BST *, int);
    BST *insertItrative(BST *, int);
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

// Complexity T - O(h) S - O(h) h = height of tree
BST *BST::insertRecusive(BST *root, int value)
{
    if (!root)
    {
        return new BST(value);
    }
    if (value > root->data)
    {
        root->right = insertRecusive(root->right, value);
    }
    else
    {
        root->left = insertRecusive(root->left, value);
    }

    return root;
}

// Complexity T - O(h) S - O(1) h = height of tree
BST *BST::insertItrative(BST *root, int value)
{
    BST *newNode = new BST(value);
    BST *cur = root;
    BST *parent = NULL;

    while (cur)
    {
        parent = cur;
        if (value < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if (parent == NULL)
        parent = newNode;
    else if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

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
    root = b.insertRecusive(root, 50);
    b.insertRecusive(root, 30);
    b.insertRecusive(root, 20);
    b.insertRecusive(root, 40);
    b.insertRecusive(root, 70);
    b.insertRecusive(root, 60);
    b.insertRecusive(root, 80);

    b.inOrder(root);
    return 0;
}