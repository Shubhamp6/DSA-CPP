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
    bool isBST(BST *);
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

/*
bool BST::isBST(BST *root, int max, int min)
{
    if (!root)
        return true;
    if (root->data < min || root->data > max)
        return false;
    return (isBST(root->left, root->data - 1, min) &&
            isBST(root->right, max, root->data - 1));
}
*/

bool BST::isBST(BST *root)
{
    static BST *prev = NULL;
    if (root)
    {
        if (!isBST(root->left))
            return false;

        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBST(root->right);
    }
    return true;
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
    cout << endl << b.isBST(root) << endl;
    return 0;
}