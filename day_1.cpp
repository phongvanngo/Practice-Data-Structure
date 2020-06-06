#include <limits>

#include <iostream>
using namespace std;

void I0byScanfPrintf()
{
    int a = 6;
    char c = 'd';
    double k = 2.4444;
    printf("%d          \n      %c\n%lf", a, c, k);
}

void CinIgnore()
{
    int a;
    cin >> a;
    cin.ignore(numeric_limits<streamsize>::max(), 'd');
    int b;
    cin >> b;
    printf("%d %d", a, b);
}

int main()
{
    CinIgnore();
}