#include <iostream>
#include <cstdlib>
#include <climits>
#include <fstream>

// ofstream outData;

using namespace std;

int main()
{
    ofstream outData("ArrayTest.inp");
    int n;
    //cin >> n;
    n = 20000;
    int start = 0,
        end = INT_MAX;
    int limit = end / RAND_MAX;
    outData << n << endl;
    for (int i = 0; i < n; i++)
    {
        int k = rand() * limit;
        while (k < start)
        {
            k = rand() * limit;
        }
        outData << k << endl;
    };
    //outData << -1;
    outData.close();
}