/* Example using #ifdef directive for inserting platform specific source code by TechOnTheNet.com */

#include <stdio.h>

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n; i > 1; i--)
        for (int j = 0; j < i - 1; j++)
            if (a[j + 1] < a[j])
                swap(a[j + 1], a[j]);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}