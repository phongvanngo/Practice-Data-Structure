#include <iostream>

using namespace std;

struct Node
{
public:
    int data;
    Node *next;
};

struct LinkedList
{

    Node *head, *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    };
    void Append(int _info)
    {
        Node *CurrNode = head;
        while (CurrNode != NULL)
        {
            if (CurrNode->data == _info)
                return;
            CurrNode = CurrNode->next;
        }
        Node *newNode = new Node;
        newNode->data = _info;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    };
    void Print()
    {
        Node *CurrNode = head;
        while (CurrNode != NULL)
        {
            cout << CurrNode->data << " ";
            CurrNode = CurrNode->next;
        }
    }
};

int main()
{

    LinkedList List1, List2;
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "Danh sach rong.";
        exit(0);
    }
    cout << "Danh sach vua nhap la: ";
    while (n != 0)
    {
        cout << n << " ";
        //List1.Append(n);
        if (n % 2 == 0)
            List1.Append(n);
        if (n % 2 == 1)
            List2.Append(n);
        cin >> n;
    }
    cout << "\nCac so chan trong danh sach la: ";
    List1.Print();
    cout << "\nCac so le trong danh sach la: ";
    List2.Print();
}
