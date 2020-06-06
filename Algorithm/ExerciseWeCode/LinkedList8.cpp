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

int ElementPosition(int key,Node *head) {
    for (int i = 0;i<key;i++) {
        head = head->next;
    };
    return (head->info);
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    int n,dem=0;
    cin >>n ;
    while (n!=0) {
        Append(&head,&tail,n);
        dem ++;
        cin>>n;
    };

    cout <<ElementPosition(dem/2,head);
}