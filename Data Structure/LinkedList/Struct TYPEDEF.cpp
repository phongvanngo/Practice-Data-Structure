#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head = NULL;
    Node *tail = NULL;
};

void Append(LinkedList &_linkedList, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (_linkedList.head == NULL)
    {
        _linkedList.head = newNode;
        _linkedList.tail = newNode;
    }
    else
    {
        _linkedList.tail->next = newNode;
        _linkedList.tail = newNode;
    }
};

void Print(LinkedList _linkedList)
{
    while (_linkedList.head != NULL)
    {
        cout << _linkedList.head->data << " ";
        _linkedList.head = _linkedList.head->next;
    }
};

void Insert(LinkedList &list, int pos, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (pos == 0)
    {
        newNode->next = list.head;
        list.head = newNode;
        return;
    };

    Node *nextNode = list.head;
    for (int i = 1; i <= pos - 1; i++)
    {
        nextNode = nextNode->next;
        if (nextNode == NULL) //pos > number of Node;
            return;
    }
    if (nextNode->next == NULL)
        list.tail = newNode;
    newNode->next = nextNode->next;
    nextNode->next = newNode;
}

int main()
{
    int n, k;
    LinkedList list1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        Append(list1, k);
    };

    cin >> n >> k;
    Insert(list1, n, k);
    Print(list1);
}