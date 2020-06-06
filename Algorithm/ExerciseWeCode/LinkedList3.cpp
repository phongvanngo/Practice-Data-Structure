#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int m)
{
    if (m < 2)
        return false;
    for (int i = 2; i <= sqrt(m); i++)
        if (m % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    int dem = 0;
    int i = 0;
    cin >> n;
    if (n == 0)
    {
        cout << "Danh sach rong.";
        exit(0);
    }
    cout << "Danh sach vua nhap la: ";
    while (n != 0)
    {
        i++;
        if (i % 2 != 0)
        {
            if (isPrime(n))
                dem++;
        };
        cout << n << " ";
        cin >> n;
    };
    cout << "\nDanh sach co " << dem << " so nguyen to o vi tri le.";
}
