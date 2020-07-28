#include <iostream>
using namespace std;
#define NULLKEY -1;
const int MAX_BUCKET = 10;

typedef struct tagNode
{
    int key;
    int next;
} Node;

int available = MAX_BUCKET - 1;

Node bucket[MAX_BUCKET];

int hashfunction(int key){return (key % MAX_BUCKET)};

void InitBucket()
{
    for (int i = 0; i < MAX_BUCKET; i++)
        ;
}

int getEmty()
{
    while ((bucket[available].key == NULLKEY) && available >= 0)
        available--;
    if (available >= 0)
}

void insert(int k)
{
    int i = hashfunction(k);
}

int Search(int k)
{
    return 0;
}

int main()
{

    int m;
    m = 10;
    const int a[7] = {2, 4, 6, 14, 12, 22, 32};
    for (int i = 0; i < 7; i++)
        insert(a[i]);
}