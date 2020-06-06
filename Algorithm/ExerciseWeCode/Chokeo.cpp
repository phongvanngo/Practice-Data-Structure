#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int preValue = 1,
        subSum = 1,
        Total = 0,
        d,
        i;

    if (n == 1)
    {
        cout << 1;
        exit(0);
    };

    for (i = 0; i < n; i++)
        cin >> a[i];

    i = 1;
    d = 1;

    while (i < n)
    {
        if (a[i] == a[i - 1])
        {
            Total += subSum;
            subSum = 1;
            d = 1;
            preValue = 1;
        };
        if (a[i] > a[i - 1])
        {
            preValue++;
            subSum += preValue;
            d++;
        };
        if (a[i] < a[i - 1])
        {
            preValue--;
            if (preValue == 0)
            {
                subSum = subSum + d + 1;
                preValue = 1;
                d++;
            }
            else
            {
                subSum += preValue;
                d++;
            }
        }
        i++;
    };
    Total += subSum;
    cout << Total;
}