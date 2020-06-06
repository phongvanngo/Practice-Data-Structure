#include <iostream>
#include <stdlib.h>

using namespace std;

double sqrt_newton(double n)
{
    const double eps = 1E-15;
    double x = 1;
    for (;;)
    {
        double nx = (x + n / x) / 2;
        if (abs(x - nx) < eps)
            break;
        x = nx;
    }
    return x;
}

int main()
{
    cout << sqrt_newton(3);
}