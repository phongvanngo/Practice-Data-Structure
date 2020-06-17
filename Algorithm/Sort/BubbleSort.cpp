#include <iostream>

using namespace std;

int *Arr;

void BubbleSort(int a[], int left, int right)
{
    for (int i = right; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[i])
            {
                //swap
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            };
        };
    }
}

int main()
{
    int n;
    cin >> n;
    Arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> Arr[i];
    BubbleSort(Arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << Arr[i] << '\n';
}