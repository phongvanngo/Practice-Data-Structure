#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node *next;

public:
    friend class SinglyLinkedList;
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = NULL;
    };
    SinglyLinkedList(int _info)
    {
        Node *newNode = new Node;
        newNode->info = _info;
        newNode->next = NULL;
        head = newNode;
    };
    void pushToFront(int _info)
    {
        Node *newNode = new Node;
        newNode->info = _info;
        newNode->next = head;
        head = newNode;
    };
    void Append(int _info)
    {
        Node *newNode = new Node;
        newNode->info = _info;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        };

        Node *last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = newNode;
    };
    void PrintList()
    {
        Node *_next = head;
        while (_next != NULL)
        {
            cout << _next->info << " ";
            _next = _next->next;
        };
    };

    void DeleteAllNode(int key)
    {
        Node *nextNode, *preNode;

        while (head != NULL && head->info == key)
        {
            preNode = head;
            head = head->next;
            delete preNode;
        };

        preNode = head;
        nextNode = head->next;
        while (nextNode != NULL)
        {
            if (nextNode->info == key)
            {
                preNode->next = nextNode->next;
                delete nextNode;
                nextNode = preNode->next;
            }
            else
            {
                preNode = nextNode;
                nextNode = nextNode->next;
            };
        };
    };
    void DeleteAtPosition(int position)
    {
        Node *preNode = head, *nextNode = head;
        if (position == 0)
        {
            head = head->next;
            delete preNode;
            return;
        };

        for (int i = 0; (i < position - 1 && preNode != NULL); i++)
            preNode = preNode->next;

        if (preNode == NULL || preNode->next == NULL)
            return;

        nextNode = preNode->next->next;
        delete preNode->next;
        preNode->next = nextNode;
    };

    void InsertAtPosition(int _info, int position)
    {
        Node *preNode = head;
        Node *newNode = new Node;
        newNode->info = _info;

        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        };

        for (int i = 0; (i < position - 1 && preNode != NULL); i++)
            preNode = preNode->next;
        if (preNode == NULL)
            return;

        newNode->next = preNode->next;
        preNode->next = newNode;
    }
    void SelectionSort1()
    {
        Node *preNode = head, *nextNode;
        while (preNode != NULL)
        {
            nextNode = preNode->next;
            while (nextNode != NULL)
            {
                if (nextNode->info < preNode->info)
                {
                    int temp = nextNode->info;
                    nextNode->info = preNode->info;
                    preNode->info = temp;
                };
                nextNode = nextNode->next;
            };
            preNode = preNode->next;
        }
    };
    void SwapPosition(int x, int y)
    {
        if (x == y)
            return;

        Node *currX, *preX, *currY, *preY;
        preX = NULL;
        currX = head;
        preY = NULL;
        currY = head;

        for (int xi = 0; (xi < x && currX != NULL); xi++)
        {
            preX = currX;
            currX = preX->next;
        };
        for (int yi = 0; (yi < y && currY != NULL); yi++)
        {
            preY = currY;
            currY = preY->next;
        };

        if (preX == NULL)
            head = currY;
        else
            preX->next = currY;

        if (preY == NULL)
            head = currX;
        else
            preY->next = currX;

        Node *temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    };
    void SelectionSort2()
    {
        Node *CurrNode1,
            *PrevNode1,
            *CurrNode2,
            *PrevNode2;

        CurrNode1 = head;
        PrevNode2 = head;
        CurrNode2 = head->next;

        while (CurrNode2 != NULL)
        {
            CurrNode1 = head;

            if (CurrNode2->info < head->info)
            {
                //swap
                head = CurrNode2;
                PrevNode2->next = CurrNode1;
                Node *temp = CurrNode2->next;
                CurrNode2->next = CurrNode1->next;
                CurrNode1->next = temp;

                PrevNode2 = CurrNode1;
                CurrNode2 = CurrNode1->next;
            }
            else
            {
                PrevNode2 = CurrNode2;
                CurrNode2 = CurrNode2->next;
            }
        };

        PrevNode1 = head;
        CurrNode1 = head->next;

        while (CurrNode1 != NULL)
        {
            PrevNode2 = CurrNode1;
            CurrNode2 = CurrNode1->next;
            while (CurrNode2 != NULL)
            {
                if (CurrNode2->info < CurrNode1->info)
                {
                    //swap
                    PrevNode1->next = CurrNode2;
                    PrevNode2->next = CurrNode1;
                    Node *temp = CurrNode2->next;
                    CurrNode2->next = CurrNode1->next;
                    CurrNode1->next = temp;

                    PrevNode2 = CurrNode1;
                    temp = CurrNode2;
                    CurrNode2 = CurrNode1->next;
                    CurrNode1 = temp;
                }
                else
                {
                    PrevNode2 = CurrNode2;
                    CurrNode2 = CurrNode2->next;
                }
            };
            PrevNode1 = CurrNode1;
            CurrNode1 = CurrNode1->next;
        };
    };
};

int main()
{

    SinglyLinkedList List1;
    for (int i = 0; i < 10; i++)
        List1.pushToFront(i);

    List1.PrintList();
    cout << endl;
    List1.SelectionSort2();
    List1.PrintList();

    // List1.InsertAtPosition(4, 10);
    // List1.PrintList();
    // cout << endl;
    // List1.SelectionSort1();
    // List1.PrintList();
}