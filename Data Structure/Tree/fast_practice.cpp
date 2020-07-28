#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int k)
    {
        key = k;
        left = NULL;
        right = NULL;
    }
};

typedef Node *TREE;

void insert(TREE &tree, int k)
{
    Node *newNode = new Node(k);
    if (tree == NULL)
        tree = newNode;
    else
    {
        TREE *currNode = &tree;
        while (*currNode != NULL)
        {
            if (k > (*currNode)->key)
                currNode = &(*currNode)->right;
            else
                currNode = &(*currNode)->left;
        };
        *currNode = newNode;
    }
}

void print(TREE tree)
{
    cout << tree->key << " ";
    if (tree->left)
        print(tree->left);
    if (tree->right)
        print(tree->right);
};

void Replace(TREE &node_delete, TREE &node_replace)
{
    if (node_replace->left == NULL)
    {
        node_delete->key = node_replace->key;
        node_delete = node_replace;
        node_replace = node_replace->right;
    }
    else
        Replace(node_delete, node_replace->left);
}

void Delete(TREE &tree, int k)
{
    if (tree == NULL)
        return;
    if (tree->key == k)
    {
        Node *p;
        if (tree->left == NULL)
        {
            p = tree;
            tree = tree->right;
        }
        else if (tree->right == NULL)
        {
            p = tree;
            tree = tree->left;
        }
        else
        {
            p = tree;
            Replace(p, p->right);
        }
        delete p;
        p = NULL;
    }
    else if (k > tree->key)
        Delete(tree->right, k);
    else
        Delete(tree->left, k);
}

int main()
{
    TREE tree = NULL;
    int a[10] = {5, 3, 2, 6, 4, 8, 9, 1, 7, 0};
    for (int i = 0; i < 10; i++)
        insert(tree, a[i]);
    print(tree);
    cout << endl;
    Delete(tree, 5);
    Delete(tree, 8);
    Delete(tree, 3);
    Delete(tree, 6);

    print(tree);
    cout << endl;
}