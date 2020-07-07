#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int _data)
    {
        data = _data;
        left = NULL;
        right = NULL;
    }
};

typedef Node *TREE;

void InsertNode(TREE &root, int _data)
{
    if (root == NULL)
    {
        root = new Node(_data);
        return;
    };
    if (_data > root->data)
        InsertNode(root->right, _data);
    else if (_data < root->data)
        InsertNode(root->left, _data);
};

void InsertNode2(TREE &Root, int _data)
{
    if (Root == NULL)
    {
        Root = new Node(_data);
        return;
    };

    TREE p = Root;

    while (p)
    {
        if (_data > p->data)
            if (p->right == NULL)
            {
                p->right = new Node(_data);
                return;
            }
            else
                p = p->right;

        if (_data < p->data)
            if (p->left == NULL)
            {
                p->left = new Node(_data);
                return;
            }
            else
                p = p->left;
    }
}

//-----------------------------------------------

void InsertSubTree(TREE &root, TREE SubTree)
{
    if (root == NULL)
    {
        root = SubTree;
        return;
    };
    if (SubTree->data > root->data)
        InsertSubTree(root->right, SubTree);
    if (SubTree->data < root->data)
        InsertSubTree(root->left, SubTree);
};

int DeleteNode(TREE &root, int _data)
{
    if (root->data == _data)
    {
        TREE SubTree = root->left;
        TREE temp = root;
        root = root->right;
        delete temp;
        InsertSubTree(root, SubTree);
        return 1;
    };

    if (_data > root->data && root->right != NULL)
        return DeleteNode(root->right, _data);
    if (_data < root->data && root->left != NULL)
        return DeleteNode(root->left, _data);
    return -1;
};

//-----------------------------------------------

int DataReplace(TREE &root)
{
    if (root->right == NULL && root->left == NULL)
    {
        int res = root->data;
        delete root;
        root = NULL;
        return res;
    };
    if (root->right != NULL)
        return DataReplace(root->right);
    if (root->left != NULL)
        return DataReplace(root->left);

    return -1;
};

int DeleteNodeInTree(TREE &root, int _data)
{
    if (_data == root->data)
    {
        TREE temp = root;
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            return 1;
        };
        if (root->left != NULL && root->right == NULL)
        {
            root = root->left;
            delete temp;
            temp = NULL;
            return 1;
        };
        if (root->right != NULL && root->left == NULL)
        {
            root = root->right;
            delete temp;
            temp = NULL;
            return 1;
        };
        root->data = DataReplace(root->left);
        return 1;
    };

    if (_data > root->data)
        return DeleteNodeInTree(root->right, _data);
    if (_data < root->data)
        return DeleteNodeInTree(root->left, _data);

    return -1;
}

//-----------------------------------------------

void PrintInOrder(TREE root) // left root right
{
    if (root->left != NULL)
        PrintInOrder(root->left);
    cout << root->data << " ";
    if (root->right != NULL)
        PrintInOrder(root->right);
};

void PrintPreOrder(TREE root)
{ //root left right
    cout << root->data << " ";
    if (root->left != NULL)
        PrintPreOrder(root->left);
    if (root->right != NULL)
        PrintPreOrder(root->right);
};

void PrintPostOrder(TREE root)
{ //left right root
    if (root->left != NULL)
        PrintPostOrder(root->left);
    if (root->right != NULL)
        PrintPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    TREE BinaryTree = NULL;
    const int a[10] = {7, 8, 5, 12, 6, 15, 14, 16, 11, 4};
    for (int i = 0; i < 10; i++)
        InsertNode2(BinaryTree, a[i]);

    PrintInOrder(BinaryTree);
    cout << endl;
    // PrintPreOrder(BinaryTree);
    // cout << endl;
    // PrintPostOrder(BinaryTree);
    // cout << endl;
    // cout << endl;

    // DeleteNodeInTree(BinaryTree, 7);

    // PrintInOrder(BinaryTree);
    // cout << endl;
    // PrintPreOrder(BinaryTree);
    // cout << endl;
    // PrintPostOrder(BinaryTree);
}