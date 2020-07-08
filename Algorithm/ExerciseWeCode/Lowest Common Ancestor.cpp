#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *right, *left;
    Node(int _key)
    {
        key = _key;
        right = NULL;
        left = NULL;
    }
};

typedef Node *TREE;

void Insert(TREE &tree, int key)
{
    TREE *CurrNode = &tree;
    while (*CurrNode != NULL)
    {
        if (key > (*CurrNode)->key)
            CurrNode = &(*CurrNode)->right;
        else if (key < (*CurrNode)->key)
            CurrNode = &(*CurrNode)->left;
        else
            return;
    };
    *CurrNode = new Node(key);
}

void Print(TREE tree)
{
    cout << tree->key << " ";
    if (tree->left != NULL)
        Print(tree->left);
    if (tree->right != NULL)
        Print(tree->right);
}

int LCA(TREE tree, int u, int v)
{
    if (tree == NULL)
        return 0;
    if (u > tree->key && v > tree->key)
        return LCA(tree->right, u, v);
    if (u < tree->key && v < tree->key)
        return LCA(tree->left, u, v);
    return tree->key;
}

int main()
{

    TREE tree = NULL;


    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        Insert(tree, k);
    };

    int m;
    cin >> n >> m;
    cout << LCA(tree, n, m);

}