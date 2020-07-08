#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

struct LList
{
    Node *head = NULL, *tail = NULL;
};

typedef Node *TREE;

void Append(LList &list, int key)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->right = NULL;
    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
    }
    else
    {
        list.tail->right = newNode;
        list.tail = newNode;
    }
};

void PushToFront(LList &list, int key)
{
    Node *newNode = new Node;
    newNode->key = key;
    if (list.head == NULL)
    {
        list.head = newNode;
        list.tail = newNode;
        list.head->right = NULL;
    }
    else
    {
        newNode->right = list.head;
        list.head = newNode;
    }
};

Node *Find(LList list, int key)
{
    Node *CurrNode = list.head;
    while (CurrNode != NULL && CurrNode->key != key)
        CurrNode = CurrNode->right;

    return CurrNode;
};

void InsertAfter(LList &list, int a, int b)
{

    Node *newNode = new Node;
    newNode->key = b;

    Node *pivot = Find(list, a);

    if (pivot == NULL)
        PushToFront(list, b);
    else
    {
        newNode->right = pivot->right;
        pivot->right = newNode;
        if (newNode->right == NULL)
            list.tail = newNode;
    };
}

void Print(LList list)
{
    while (list.head != NULL)
    {
        cout << list.head->key << " ";
        list.head = list.head->right;
    }
}

void Move(LList &list, TREE &tree)
{
    if (tree == NULL)
    {
        tree = list.head;
        list.head = list.head->right;
        tree->right = NULL;
        tree->left = NULL;
        return;
    };
    if (tree->key == list.head->key)
    {
        list.head = list.head->right;
        return;
    }
    if (list.head->key > tree->key)
        Move(list, tree->right);
    else
        Move(list, tree->left);
}

void LListToTree(LList &list, TREE &tree)
{
    tree = list.head;
    list.head = list.head->right;

    tree->right = NULL;
    tree->left = NULL;

    while (list.head != NULL)
    {
        Move(list, tree);
    }
};

bool isNotExist(LList list, int key)
{
    if (list.head == NULL)
        return true;
    while (list.head != NULL)
    {
        if (list.head->key == key)
            return false;
        list.head = list.head->right;
    };
    return true;
}

void Printt(TREE tree)
{
    cout << tree->key << " ";
    if (tree->left)
        Printt(tree->left);
    if (tree->right)
        Printt(tree->right);
}

int height = 0;

void HeightOfTree(TREE tree, int h)
{

    if (h > height)
        height = h;
    if (tree->right)
        HeightOfTree(tree->right, h + 1);
    if (tree->left)
        HeightOfTree(tree->left, h + 1);
}

int main()
{
    LList list;
    // int a[10] = {10, 5, 4, 7, 8, 9, 45, 12, 34, 21};
    // for (int i = 0; i < 10; i++)
    //     PushToFront(list, a[i]);
    // Print(list);
    // cout << endl;

    TREE tree = NULL;
    // LListToTree(list, tree);
    // Printt(tree);
    // cout << endl;
    // HeightOfTree(tree, 1);
    // cout << height;

    int k, a, b;
    cin >> k;
    while (k != 3)
    {
        switch (k)
        {
        case 0:
            cin >> a;
            if (isNotExist(list, a))
                PushToFront(list, a);
            break;

        case 1:
            cin >> a;
            if (isNotExist(list, a))
                Append(list, a);
            break;
        case 2:
            cin >> a >> b;
            if (isNotExist(list, b))
                InsertAfter(list, a, b);
            break;
        };
        cin >> k;
    };

    //Print(list);
    LListToTree(list, tree);
    HeightOfTree(tree, 0);
    cout << height;
}
