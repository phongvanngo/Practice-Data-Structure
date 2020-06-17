#include <iostream>

using namespace std;

void BurbbleSort(int a[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            };
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    BurbbleSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}