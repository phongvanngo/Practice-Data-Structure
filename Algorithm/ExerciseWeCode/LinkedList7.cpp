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

    SinglyLinkedList Add(SinglyLinkedList B);
    SinglyLinkedList Reverse();
};

SinglyLinkedList SinglyLinkedList::Reverse()
{
    SinglyLinkedList Res;
    Node *CurrNode = head;
    while (CurrNode != NULL)
    {
        Res.PushToFront(CurrNode->info);
        CurrNode = CurrNode->next;
    };
    return Res;
};

SinglyLinkedList SinglyLinkedList::Add(SinglyLinkedList B)
{
    SinglyLinkedList Res;
    Node *FristNode = head, *SecondNode = B.head;
    int temp = 0, sum = 0;
    while (FristNode != NULL && SecondNode != NULL)
    {
        sum = FristNode->info + SecondNode->info + temp;
        Res.Append(sum % 10);
        temp = sum / 10;
        FristNode = FristNode->next;
        SecondNode = SecondNode->next;
    };
    while (SecondNode != NULL)
    {
        Res.Append((SecondNode->info + temp) % 10);
        temp = (SecondNode->info + temp) / 10;
        SecondNode = SecondNode->next;
    };
    while (FristNode != NULL)
    {
        Res.Append((FristNode->info + temp) % 10);
        temp = (FristNode->info + temp) / 10;
        FristNode = FristNode->next;
    };
    if (temp != 0)
        Res.Append(temp);
    return Res;
}

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
    if (head == NULL)
        cout << "null";
    while (CurrentNode != NULL)
    {
        cout << CurrentNode->info << "";
        CurrentNode = CurrentNode->next;
    };
};

int main()
{
    SinglyLinkedList A, B;
    int n;
    cin >> n;
    while (n != -1)
    {
        A.Append(n);
        cin >> n;
    };
    cin >> n;
    while (n != -1)
    {
        B.Append(n);
        cin >> n;
    };
    A.Add(B).Reverse().PrlongList();
};