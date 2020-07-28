#include <iostream>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <time.h>  

// ofstream outData;

using namespace std;

int main()
{
    ofstream outData("ArrayTest.inp");
    int n;
    cin >> n;
    srand (time(NULL));
    // n = 20000;
    int start = 0,
        end = 10;
    int limit = end / RAND_MAX;
    outData << n << endl;
    for (int i = 0; i < n; i++)
    {
        int k = rand();
        while (k < start || k > end)
        {
            k = rand();
        }
        cout << k << " ";
    };
    //outData << -1;
    outData.close();
}