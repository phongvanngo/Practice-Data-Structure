#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node *next;
};

void Append(Node **head,Node**tail, int _info)
{
    Node *newNode = new Node;
    newNode->info = _info;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return;
    };
    (*tail)->next = newNode;
    *tail = newNode;

};

void PrintList(Node *head)
{
    while (head != NULL)
    {
        cout << head->info << " ";
        head = head->next;
    };
};
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    int n;
    int dem = 0;
    cin >> n;
    if (n == 0)
    {
        cout << "Danh sach rong.";
        exit(0);
    }
    while (n != 0)
    {
        dem++;
        Append(&head, &tail,n);
        cin>>n;
    };
    cout << "Danh sach vua nhap la: ";
    PrintList(head);
    cout <<"\nDanh sach co "<<dem<<" phan tu.";
}