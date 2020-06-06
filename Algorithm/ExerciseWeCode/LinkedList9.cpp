#include <iostream>

using namespace std;

int main()
{
    int pre, n;
    cin >> pre;
    if (pre == 0)
        exit(0);
    cin >> n;

    while (n != 0)
    {
        if (pre != 0)
            cout << n << " " << pre << " ";
        else
            cout << n;
        cin >> pre;
        n = 0;
        if (pre == 0)
            continue;
        cin >> n;
    };

    if (pre != 0)
        cout << pre;
}