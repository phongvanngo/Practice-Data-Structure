#include <iostream>

using namespace std;

//-------------------------------------------------------------
int BinarySearch_Loop(int a[], int start, int end, int index)
{
    int mid = (start + end) / 2;
    while (a[mid] != index && start != end)
    {
        if (index > a[mid])
            start = mid + 1;
        else
            end = mid;
        mid = (start + end) / 2;
    }

    if (a[mid] == index)
        return mid;
    else
        return -1;
}

//------------------------------------------------------------
int BinarySearch_Loop_bonus_1(int a[], int start, int end, int index, int num_of_element) //neu khong tim thay xuat ra vi tri de them vao de mang tang dan
{
    int mid = (start + end) / 2;
    while (a[mid] != index && start != end)
    {

        if (index > a[mid])
            start = mid + 1;
        else
            end = mid;
        mid = (start + end) / 2;
    }

    if (a[mid] == index)
        return mid;

    if (index > a[mid])
        return mid + 1;
    else
        return mid;
};
//-----------------------------------------------------------------------

int BinarySearch2(int a[], int start, int end, int index) // find element smallest >= a
{
    int last = end;
    int mid;
    while (start != end)
    {
        mid = (start + end) / 2;
        if (index >= a[mid] )
            start = mid + 1;
        else
            end = mid;
    };
    if (a[start]>index) return start;
    if (a[start]<index && start <last ) return start +1;
    return -1;
}

//-----------------------------------------------------------------------
int BinarySearch3(int a[], int start, int end, int index) // find element biggest <= a
{
    int last = end;
    int mid;
    while (start != end)
    {
        mid = (start + end) / 2;
        if (index <= a[mid])
            end = mid;
        else
            start = mid + 1;
    };
    if (a[start]<index) return start;
    if (a[start]>index && start > 0) return start - 1;
    return -1;
}

//-------------------------------------------------

int main()
{

    int n, k;
    scanf("%d%d", &n, &k);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cout << BinarySearch2(a, 0, n - 1, k);
}

// lech trai, lech phai
// de binh thuong lech trai, +1 lech phai;