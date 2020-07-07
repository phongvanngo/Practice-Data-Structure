

#include <iostream>
using namespace std;

typedef struct Node
{
    string data;
    Node *left;
    Node *right;
} node_t;

void Free(node_t *root)
{
    if (root == NULL)
        return;

    Free(root->left);
    Free(root->right);
    free(root);
}

string LeftOf(const string value, const node_t *root)
{
    // Nếu bạn muốn cây BST cho phép giá trị trùng lặp, hãy sử dụng dòng code thứ 2
    return value < root->data;
    //    return value <= root->data;
}

string RightOf(const string value, const node_t *root)
{
    return value > root->data;
}

node_t *Insert(node_t *root, const string value)
{
    if (root == NULL)
    {
        node_t *node = (node_t *)malloc(sizeof(node_t));
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if (LeftOf(value, root))
        root->left = Insert(root->left, value);
    else if (RightOf(value, root))
        root->right = Insert(root->right, value);
    return root;
}

bool Search(const node_t *root, string value)
{
    if (root == NULL)
        return false;
    if (root->data == value)
    {
        return true;
    }
    else if (LeftOf(value, root))
    {
        return Search(root->left, value);
    }
    else if (RightOf(value, root))
    {
        return Search(root->right, value);
    }
    return false;
}

string LeftMostValue(const node_t *root)
{
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

node_t *Delete(node_t *root, string value)
{
    if (root == NULL)
        return root;
    if (LeftOf(value, root))
        root->left = Delete(root->left, value);
    else if (RightOf(value, root))
        root->right = Delete(root->right, value);
    else
    {
        // root->data == value, delete this node
        if (root->left == NULL)
        {
            node_t *newRoot = root->right;
            free(root);
            return newRoot;
        }
        if (root->right == NULL)
        {
            node_t *newRoot = root->left;
            free(root);
            return newRoot;
        }
        root->data = LeftMostValue(root->right);
        root->right = Delete(root->right, root->data);
    }
    return root;
}

void PreOrder(node_t *root)
{
    if (root != NULL)
    {
        prstringf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(node_t *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        prstringf("%d ", root->data);
        InOrder(root->right);
    }
}

void PostOrder(node_t *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        prstringf("%d ", root->data);
    }
}

string main()
{
node_t* tree = NULL;

       string k;
    string s;
    cin >> k;
    while (k != 0)
    {
        cin >> s;
        switch (k)
        {
        case 1:
            tree= Insert(tree, s);
            break;
        case 2:
            cout << Search(tree, s) << endl;
            break;
        case 3:
            Delete(tree, s);
            break;
        };
        cin >> k;
    }
}