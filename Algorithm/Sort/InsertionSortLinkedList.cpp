#include <iostream>

using namespace std;

class Node
{
private:
    int info;
    Node *next;
    friend class SinglyLinkedList;
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList();
    void Append(int info);
    void PrintList();
    void InsertionSort();
};

SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
};

void SinglyLinkedList::Append(int info) //thêm phần tử vào cuối danh sách
{
    Node *newNode = new Node;
    newNode->info = info;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    };
    Node *CurrentNode = head;
    while (CurrentNode->next != NULL)
        CurrentNode = CurrentNode->next;
    CurrentNode->next = newNode;
};

void SinglyLinkedList::PrintList()
{
    Node *CurrentNode = head;
    while (CurrentNode != NULL)
    {
        cout << CurrentNode->info << " ";
        CurrentNode = CurrentNode->next;
    };
};

void SinglyLinkedList::InsertionSort()
{
    if (head == NULL)
        return;

    Node *CurrentNode = head->next,
         *PrevCurrentNode = head;

    //duyệt danh sách, tìm CurrentNode không đúng vị trí
    while (CurrentNode != NULL)
    {
        if (CurrentNode->info < PrevCurrentNode->info) // nếu Node sau nhỏ hơn Node trước
        {
            // duyệt tìm vị trí để chèn
            Node *SecondNode = head,
                 *PrevSecondNode = NULL;
            while (SecondNode->info < CurrentNode->info)
            {
                PrevSecondNode = SecondNode;
                SecondNode = SecondNode->next;
            };

            //chèn CurrentNode vào vị trí thích hợp
            if (PrevSecondNode == NULL)
                head = CurrentNode;
            else
                PrevSecondNode->next = CurrentNode;

            PrevCurrentNode->next = CurrentNode->next;
            CurrentNode->next = SecondNode;

            CurrentNode = PrevCurrentNode;
        };
        PrevCurrentNode = CurrentNode;
        CurrentNode = CurrentNode->next;
    };
};

int main()
{
    SinglyLinkedList List1;
    int n, k;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        List1.Append(k);
    }
    List1.InsertionSort();
    List1.PrintList();
};