#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct SinglyLinkedList
{
    Node *head, *tail;
};

void MoveNode(Node **PreNode, SinglyLinkedList &FristList, SinglyLinkedList &SecondList)
{
    if (&FristList == &SecondList)
        return;
    if (PreNode == &FristList.head) //list co 1 Node
    {
        if (SecondList.head == NULL)
        {
            SecondList.head = *PreNode;
            SecondList.tail = *PreNode;
        }
        else
        {
            SecondList.tail->next = *PreNode;
            SecondList.tail = *PreNode;
        };
        (*PreNode) = (*PreNode)->next;
        SecondList.tail->next = NULL;

        if (*PreNode == NULL)
            FristList.tail = NULL;
        return;
    };

    if (SecondList.head == NULL)
    {
        SecondList.head = (*PreNode)->next;
        SecondList.tail = (*PreNode)->next;
    }
    else
    {
        SecondList.tail->next = (*PreNode)->next;
        SecondList.tail = (*PreNode)->next;
    };

    if ((*PreNode)->next->next == NULL) //cuoi danh sach, cap nhat lai tail
        FristList.tail = (*PreNode);

    (*PreNode)->next = (*PreNode)->next->next;
    SecondList.tail->next = NULL;
};

void InitLinkedList(SinglyLinkedList &List)
{
    List.head = NULL;
    List.tail = NULL;
}

void Append(SinglyLinkedList &List, int _data)
{
    Node *newNode = new Node;
    newNode->data = _data;
    newNode->next = NULL;

    if (List.head == NULL)
    {
        List.head = newNode;
        List.tail = newNode;
        return;
    };

    List.tail->next = newNode;
    List.tail = newNode;
}

void PrintList(Node *head)
{
    cout << "..";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
};

int getMax(SinglyLinkedList List)
{
    int max = 0;
    Node *head = List.head;
    while (head != NULL)
    {
        if (max < head->data)
            max = head->data;
        head = head->next;
    };
    return max;
}

SinglyLinkedList RadixSort(SinglyLinkedList List)
{
    SinglyLinkedList ClassifyList[10];
    for (int i = 0; i < 10; i++)
        InitLinkedList(ClassifyList[i]);
    ClassifyList[0] = List;

    int max = getMax(List);

    for (int exp = 1; (max / exp) > 0; exp = exp * 10)
    {
        for (int radix = 0; radix < 10; radix++)
        {
            if (ClassifyList[radix].head == NULL)
                continue;

            int digit = (ClassifyList[radix].head->data / exp) % 10;

            while (ClassifyList[radix].head != NULL && digit != radix)
            {
                MoveNode(&ClassifyList[radix].head, ClassifyList[radix], ClassifyList[digit]);
                if (ClassifyList[radix].head != NULL)
                    digit = (ClassifyList[radix].head->data / exp) % 10;
            };
            Node *PreNode = ClassifyList[radix].head;
            while (PreNode != NULL && PreNode->next != NULL)
            {
                digit = (PreNode->next->data / exp) % 10;
                if (digit == radix)
                    PreNode = PreNode->next;
                else
                    MoveNode(&PreNode, ClassifyList[radix], ClassifyList[digit]);
            };
        };
    };

    for (int i = 1; i <= 9; i++)
    {
        if (ClassifyList[i].head == NULL)
            continue;
        if (ClassifyList[0].head == NULL) // Neu Classify Rong;
        {
            ClassifyList[0].head = ClassifyList[i].head;
            ClassifyList[0].tail = ClassifyList[i].tail;
        };
        ClassifyList[0].tail->next = ClassifyList[i].head;
        ClassifyList[0].tail = ClassifyList[i].tail;
    }

    ClassifyList[0].tail = ClassifyList[9].tail;

    return ClassifyList[0];
}

int main()
{

    // SinglyLinkedList list1, list2;
    // InitLinkedList(list1);
    // InitLinkedList(list2);
    // for (int i = 0; i < 10; i++)
    //     Append(list1, i);
    // for (int i = 20; i < 30; i++)
    //     Append(list2, i);
    // PrintList(list1.head);
    // cout << endl;
    // PrintList(list2.head);
    // cout << endl;
    // Node *CurrNode = list1.head;
    // MoveNode(&CurrNode, list1, list2);
    // CurrNode = list1.head;
    // MoveNode(&CurrNode, list1, list2);
    // PrintList(list1.head);
    // cout << endl;
    // PrintList(list2.head);
    // cout << endl;
    // cout << list1.tail->data << " " << list2.tail->data;

    int n;
    SinglyLinkedList List;
    InitLinkedList(List);
    cin >> n;
    while (n != -1)
    {
        Append(List, n);
        cin >> n;
    }
    List = RadixSort(List);
    PrintList(List.head);
}
