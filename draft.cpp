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
    cout <<"hello";
}