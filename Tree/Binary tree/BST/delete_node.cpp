#include <bits/stdc++.h>
using namespace std;

class BST
{

public:
    int data;
    BST *left, *right;
    BST();
    BST(int);
    BST *insert(BST *, int);
    void inOrder(BST *);
    BST *search(BST *, int);
    BST *deleteNode(BST *, int);
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

int minValue(BST *root)
{
    int minV = root->data;
    while (root->left != NULL)
    {
        minV = root->left->data;
        root = root->left;
    }

    return minV;
}

BST *BST::deleteNode(BST *root, int key)
{
    if (!root)
        return root;
    if (root->data > key)
        root->left = deleteNode(root->left, key);
    else if (root->data < key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        root->data = minValue(root->right);
        root->right = deleteNode(root->right, root->data);
    }

    return root;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    BST b, *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 90);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    b.deleteNode(root, 60);
    b.inOrder(root);
    cout << endl;

    return 0;
}