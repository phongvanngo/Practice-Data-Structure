#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    };

    void PushFront(int info)
    {
        Node *newNode = new Node;
        newNode->info = info;
        newNode->next = head;
        head = newNode;
    };
    void OutputLinkedList()
    {
        Node *next = head;
        while (next != NULL)
        {
            cout << next->info << " ";
            next = next->next;
        };
    };
    void Append(int info)
    {
        Node *next = head;

        Node *newNode = new Node;
        newNode->info = info;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            return;
        };
        while (next->next != NULL)
            next = next->next;
        next->next = newNode;
    };
    void deleteNode(bool Condition(Node *_node))
    {
        Node *next = head, *prev = head;
        while (next != NULL)
        {
            if (Condition(next))
            {
                prev->next = next->next;
                delete prev;
                prev = next;
            }
            next = next->next;
        };
    };
};

bool Condition(Node *_node)
{
    if (_node->info % 2 == 0)
        return true;
    else
        return false;
};
int main()
{
    LinkedList List1;

    for (int i = 0; i < 10; i++)
        List1.Append(i);
    List1.OutputLinkedList();
    List1.deleteNode(Condition);
    cout << endl;
    List1.OutputLinkedList();
    
    int n;
    LinkedList MyList;
    cin >> n;
    MyList.PushFront(n);
}