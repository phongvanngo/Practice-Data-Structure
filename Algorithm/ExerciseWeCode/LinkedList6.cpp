#include <iostream>

using namespace std;

class Node
{
private:
    long info;
    Node *next;
    friend class SinglyLinkedList;
};

class SinglyLinkedList
{
private:
    Node *head, *tail;

public:
    SinglyLinkedList();
    void Append(long info);
    void PrlongList();
    void InsertionSort();
    void DeleteAllNode(long key);
    void PushToFront(long _info);
};

void SinglyLinkedList::PushToFront(long _info)
{
    Node *newNode = new Node;
    newNode->info = _info;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        tail->next = NULL;
        return;
    };
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::DeleteAllNode(long key)
{
    Node *nextNode, *preNode;

    while (head != NULL && head->info == key)
    {
        preNode = head;
        head = head->next;
        delete preNode;
    };

    if (head == NULL)
    {
        tail = NULL;
        return;
    }

    preNode = head;
    nextNode = head->next;
    while (nextNode != NULL)
    {
        if (nextNode->info == key)
        {
            preNode->next = nextNode->next;
            delete nextNode;
            nextNode = preNode->next;
            if (nextNode == NULL)
                tail = preNode;
        }
        else
        {
            preNode = nextNode;
            nextNode = nextNode->next;
        };
    };
};

SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
    tail = NULL;
};

void SinglyLinkedList::Append(long info) //thêm phần tử vào cuối danh sách
{
    Node *newNode = new Node;
    newNode->info = info;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    };
    tail->next = newNode;
    tail = newNode;
};

void SinglyLinkedList::PrlongList()
{
    Node *CurrentNode = head;
    if (head == NULL) cout << "null";
    while (CurrentNode != NULL)
    {
        cout << CurrentNode->info << " ";
        CurrentNode = CurrentNode->next;
    };
};

int main()
{
    SinglyLinkedList List1, l1;
    //l1.PushToFront(4);
    //l1.PrlongList();
    long n;
    cin >> n;
    while (n != 0)
    {
        List1.Append(n);
        cin >> n;
    };

    cin >> n;
    long m;
    while (n != 0)
    {
        cin >> m;
        switch (n)
        {
        case 1:
        {
            List1.PushToFront(m);
            break;
        }
        case 2:
        {
            List1.Append(m);
            break;
        }
        case 3:
        {
            List1.DeleteAllNode(m);
            break;
        }
        };
        cin >> n;
    }
    List1.PrlongList();
};