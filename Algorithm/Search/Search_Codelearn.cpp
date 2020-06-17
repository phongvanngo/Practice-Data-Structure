#include <iostream>

using namespace std;

int BinarySearch1(int a[], int _left, int _right, int key) // frist element having valye == key in array;
{
    int left = _left, right = _right;
    int middle;

    while (left != right)
    {
        middle = (left + right) / 2;
        if (key <= a[middle])
            right = middle;
        else
            left = middle + 1;
    };
    if (a[right] == key)
        return right;
    else
        return -1;
}

int BinarySearch2(int a[], int left, int right, int key)
{
    if (left == right)
        if (a[left] == key)
            return left;
        else
            return -1;
    int mid = (left + right) / 2;
    if (key <= a[mid])
        return BinarySearch2(a, left, mid, key);
    else
        return BinarySearch2(a, mid + 1, right, key);
}

int main()
{
    int n, k;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    cout << BinarySearch2(a, 0, n - 1, k);
    // for (int i = 0; i < n; i++)
    //     if (a[i] % 2 == 1 && i % 2 == 0)
    //     {
    //         cout << a[i] << " ";
    //         res++;
    //     };
    // if (res == 0)
    // cout << "NULL";
}