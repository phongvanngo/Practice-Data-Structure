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

void Delete(LinkedList &list, int pos)
{
    if (pos == 0)
    {
        Node *dummy = list.head;
        list.head = list.head->next;
        delete dummy;
        return;
    };

    Node *nextNode = list.head;
    for (int i = 1; i <= pos - 1; i++)
    {
        nextNode = nextNode->next;
        if (nextNode == NULL)
            return;
    };
    Node *dummy = nextNode->next;
    nextNode->next = nextNode->next->next;
    delete dummy;
    if (nextNode->next == NULL)
        list.tail = nextNode;
}

int getValueElement(LinkedList list, int pos)
{
    for (int i = 0; i < pos; i++)
        list.head = list.head->next;
    return list.head->data;
}

void Delete2(LinkedList &list, int pos) // delte Node having value bigger than Node having value at position pos
{
    int k = getValueElement(list, pos);

    Node *dummy;
    while (list.head != NULL)
    {
        if (list.head->data > k)
        {
            dummy = list.head;
            list.head = list.head->next;
            delete dummy;
        }
        else
            break;
    };

    Node *CurrNode = list.head;

    while (CurrNode->next != NULL)
    {
        if (CurrNode->next->data > k)
        {
            dummy = CurrNode->next;
            CurrNode->next = CurrNode->next->next;
            delete dummy;
        }
        else
            CurrNode = CurrNode->next;
    };
    list.tail = CurrNode;
};

void Replace(LinkedList list, int data1, int data2)
{
    Node *currNode = list.head;
    while (currNode != NULL)
    {
        if (currNode->data == data1)
            currNode->data = data2;
        currNode = currNode->next;
    }
}

void ReplaceHeadAndTail(LinkedList &list, int newHead)
{
    if (newHead == 0)
        return;

    Node *CurrNode = list.head;
    for (int i = 1; i < newHead; i++)
        CurrNode = CurrNode->next;
    list.tail->next = list.head;
    list.tail = CurrNode;
    list.head = CurrNode->next;
    list.tail->next = NULL;
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

    cin >> n;
    ReplaceHeadAndTail(list1,n);

    Print(list1);
}