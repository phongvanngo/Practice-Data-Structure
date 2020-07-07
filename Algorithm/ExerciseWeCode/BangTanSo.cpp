#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
                swap(a[i], a[j]);
        }
    }
}

int main()
{
    int k;
    int a[100000];
    int n = 0;
    cin >> k;

    if (k == 0)
        return 0;

    while (k != 0)
    {
        a[n] = k;
        n++;
        cin >> k;
    };

    sort(a, n);
    int i = 1;
    int dem = 1;

    while (i < n)
    {
        if (a[i] == a[i - 1])
            dem++;
        else
        {
            cout << a[i - 1] << " " << dem << '\n';
            dem = 1;
        }
        i++;
    }
    cout << a[i - 1] << " " << dem << '\n';
    system("pause");
}