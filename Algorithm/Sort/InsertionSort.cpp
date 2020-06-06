#include <iostream>

using namespace std;

int BinarySearch(int Array[], int start, int end, int index)
{
    int mid;
    while (start != end)
    {
        mid = (start + end) / 2;
        if (index >= Array[mid])
            start = mid + 1;
        else
            end = mid;
    };
    if (Array[start] < index)
        return start + 1;
    else
        return start;
}

void InsertionSort(int Array[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {        
        if (Array[i] < Array[i - 1])
        {
            int current = Array[i];
            int j = i;
            while (Array[j - 1] > current && j > start)
            {
                Array[j] = Array[j - 1];
                j--;
            }
            Array[j] = current;
        };
    };
};

void InsertionSort_BinarySearch(int Array[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        if (Array[i] < Array[i - 1])
        {
            int current = Array[i];
            int id = BinarySearch(Array, start, i - 1, current);
            for (int j = i; j > id; j--)
                Array[j] = Array[j - 1];

            Array[id] = current;
        };
    };
};

int main()
{
    int n, k;
    scanf("%d", &n);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    InsertionSort_BinarySearch(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d\n", a[i]);  
}