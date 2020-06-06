#include <iostream>

using namespace std;

struct Node {
public:
    int data;
    Node* next;

};

struct LinkedList {

    Node* head, * tail;
    LinkedList() {
        head = NULL;
        tail = NULL;
    };
    void Append(int _info) {
        Node* newNode = new Node;
        newNode->data = _info;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    };
    void DeleteNode(int _info) {
        if (head == NULL) return;
        while (head != NULL && head->data == _info) {
            Node* temp = head;
            head = head->next;
            delete temp;
        };
        if (head == NULL) return;
        Node* CurrNode = head;
        while (CurrNode->next != NULL) {
            if (CurrNode->next->data == _info) {
                Node* temp = CurrNode->next;
                CurrNode->next = CurrNode->next->next;
                if (CurrNode->next == NULL) tail = CurrNode;
                delete temp;
            }
            else CurrNode = CurrNode->next;
        }
    };
    void Print() {
        Node* CurrNode = head;
        while (CurrNode != NULL) {
            cout << CurrNode->data << " ";
            CurrNode = CurrNode->next;
        }
    }
    int AmountDuplicate(int _info) {
        Node* CurrNode = head;
        int amount = 0;
        while (CurrNode != NULL) {
            if (CurrNode->data == _info) amount++;
            CurrNode = CurrNode->next;
        }
        return amount;
    }
    void StatisticDuplicateElement() {
        while (head != NULL) {
            cout << head->data << ": " << AmountDuplicate(head->data) << endl;
            DeleteNode(head->data);
        }
    }

};


int main()
{

    LinkedList List1;
    int n;
    cin >> n;
    if (n == 0) {
        cout << "Danh sach rong.";
        exit(0);
    }
    while (n != 0) {
        List1.Append(n);
        cin >> n;
    }
    cout << "Danh sach vua nhap la: ";
    List1.Print();
    cout << "\nSo lan xuat hien cua tung phan tu trong danh sach la:\n";
    List1.StatisticDuplicateElement();

}

