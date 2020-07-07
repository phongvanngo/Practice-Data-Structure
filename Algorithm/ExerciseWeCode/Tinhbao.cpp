#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;
};

typedef Node *TREE;

bool isExist(TREE Root, string key)
{
    if (Root == NULL)
        return false;
    if (Root->data == key)
        return true;
    if (key > Root->data)
        return isExist(Root->right, key);
    else
        return isExist(Root->left, key);
}

void Insert(TREE &Root, string key)
{
    Node *newNode = new Node;
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;

    TREE *CurrNode = &Root;

    while (*CurrNode != NULL)
    {
        if (key > (*CurrNode)->data)
            CurrNode = &(*CurrNode)->right;
        else
            CurrNode = &(*CurrNode)->left;
    };
    *CurrNode = newNode;
}

void Print(TREE Root)
{
    if (Root == NULL)
        return;
    cout << Root->data << " ";
    Print(Root->left);
    Print(Root->right);
}

void Replace(TREE &NodeDelete, TREE &NodeReplace)
{
    if (NodeReplace->left != NULL)
        Replace(NodeDelete, NodeReplace->left);
    else
    {
        NodeDelete->data = NodeReplace->data;
        NodeDelete = NodeReplace;
        NodeReplace = NodeReplace->right;
    }
};

void Delete(TREE &Root, string key)
{

    if (Root == NULL)
        return;
    if (key > Root->data)
        Delete(Root->right, key);
    else if (key < Root->data)
        Delete(Root->left, key);

    if (Root->data == key)
    {
        TREE dummy = Root;
        if (Root->left == NULL)
            Root = Root->right;
        else if (Root->right == NULL)
            Root = Root->left;
        else
        {
            Replace(dummy, Root->right);
        };

        delete dummy;
        dummy = NULL;
    }
}

void Delete()
{
}

int main()
{
    TREE tree = NULL;
    int k;
    string s;
    cin >> k;
    while (k != 0)
    {
        cin >> s;
        switch (k)
        {
        case 1:
            Insert(tree, s);
            break;
        case 2:
            cout << isExist(tree, s) << endl;
            break;
        case 3:
            Delete(tree, s);
            break;
        };
        cin >> k;
    }
}