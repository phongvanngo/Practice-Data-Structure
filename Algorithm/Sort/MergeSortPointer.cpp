#include <iostream>

using namespace std;

int *mang, *res;

void MergeSort(int left, int right)
{
    if (right - left > 1)
    {
        MergeSort(left, (left + right) / 2);
        MergeSort((left + right) / 2 + 1, right);
    }
    int *i = new int(left), *j = new int((right + left) / 2 + 1);
    int *idres = new int(left);
    while (*i <= (left + right) / 2 && *j <= right)
        if (mang[*i] < mang[*j])
        {
            res[*idres] = mang[*i];
            *i += 1;
            *idres += 1;
        }
        else
        {
            res[*idres] = mang[*j];
            *j += 1;
            *idres += 1;
        }

    while (*i <= (left + right) / 2)
    {
        res[*idres] = mang[*i];
        *i += 1;
        *idres += 1;
    }
    while (*j <= right)
    {
        res[*idres] = mang[*j];
        *j += 1;
        *idres += 1;
    }

    for (int k = left; k <= right; k++)
    {
        mang[k] = res[k];
    }

    i = NULL;
    j = NULL;
    delete i;
    delete j;
}

int main()
{
    int n;
    cin >> n;
    mang = new int[n];
    res = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> mang[i];
    }
    MergeSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << '\n';
    }
}