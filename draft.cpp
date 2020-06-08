/* Example using #ifdef directive for inserting platform specific source code by TechOnTheNet.com */

#include <stdio.h>

#ifndef IOS
#define IOS
#include <iostream>
#endif

int main()
{
#ifdef UNIX
    printf("UNIX specific function calls go here.\n");
#endif

    printf("TechOnTheNet is over 10 years old.\n");
    cout << "jeloo";
    return 0;
}