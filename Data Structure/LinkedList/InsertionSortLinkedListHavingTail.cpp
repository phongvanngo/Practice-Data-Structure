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
    Node *head, *tail;

public:
    SinglyLinkedList();
    void Append(int info);
    void PrintList();
    void InsertionSort();
};

SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
    tail = NULL;
};

void SinglyLinkedList::Append(int info) //thêm phần tử vào cuối danh sách
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

            if (tail == CurrentNode)
                tail = PrevCurrentNode;
            CurrentNode = PrevCurrentNode;
        };
        PrevCurrentNode = CurrentNode;
        CurrentNode = CurrentNode->next;
    };
};

int main()
{
    SinglyLinkedList List1;
    int n;
    cin >> n;
    while (n != 0)
    {
        List1.Append(n);
        cin >> n;
    };
    List1.InsertionSort();
};