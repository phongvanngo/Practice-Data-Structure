#include <iostream>

using namespace std;

struct Node
{
    string key;
    Node *left, *right;
};

struct LList
{
    Node *head = NULL, *tail = NULL;
};

typedef Node *TREE;

void Append(LList &list, string key)
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

void PushToFront(LList &list, string key)
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

void Delete(LList &list, string key)
{
    Node *dummy;
    if (list.head == NULL)
        return;
    if (list.head->key == key)
    {
        dummy = list.head;
        list.head = list.head->right;
        if (list.head == NULL)
            list.tail = NULL;
        delete dummy;
        dummy = NULL;
    };

    Node *CurrNode = list.head;

    while (CurrNode->right != NULL)
    {
        if (CurrNode->right->key == key)
        {
            dummy = CurrNode->right;
            CurrNode->right = CurrNode->right->right;
            if (CurrNode->right == NULL)
                list.tail = CurrNode;
            delete dummy;
            dummy = NULL;
            return;
        }
        else
            CurrNode = CurrNode->right;
    }
}

void Print(LList list)
{
    while (list.head != NULL)
    {
        cout << list.head->key << " ";
        list.head = list.head->right;
    }
}

bool isNotExist(LList list, string key)
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

int main()
{
    LList list;

    int k, a, b;
    string s;
    cin >> k;
    while (k != 0)
    {
        cin >> s;
        switch (k)
        {
        case 2:
            cout << !isNotExist(list, s) << endl;
            break;
        case 1:
            if (isNotExist(list, s))
                Append(list, s);
            break;
        case 3:
            Delete(list, s);
        };
        cin >> k;
    };
}
