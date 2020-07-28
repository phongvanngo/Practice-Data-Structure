#include <iostream>
using namespace std;

typedef struct tagNode
{
    int key;
    struct tagNode *next;
} Node,
    *Nodeptr;

const int MAX_BUCKET = 10;
Nodeptr bucket[MAX_BUCKET];

int hashfunc(int key)
{
    return (key % MAX_BUCKET);
}

void insert(int k)
{
    Node *node = new Node;
    node->key = k;
    node->next = NULL;

    int i = hashfunc(k);
    if (bucket[i] == NULL)
        bucket[i] = node;
    else
    {
        Nodeptr current_node = bucket[i];
        while (current_node->next != NULL)
            current_node = current_node->next;
        current_node->next = node;
    }
}

Nodeptr Search(int k)
{
    int i = hashfunc(k);
    if (bucket[i] == NULL)
        return NULL;
    Nodeptr current_node = bucket[i];
    while (current_node->key != k && current_node->next != NULL)
        current_node = current_node->next;

    if (current_node->key == k)
        return current_node;
    else
        return NULL;
}



int main()
{
    int m;
    m = 10;
    const int a[7] = {2, 4, 6, 14, 12, 22, 32};
    for (int i = 0; i < 7; i++)
        insert(a[i]);

    Nodeptr res = Search(22);
    if (res)
        cout << res->key;
    else
        cout << res;
}