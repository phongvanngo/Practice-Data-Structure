#include <iostream>
#include <string>

using namespace std;
int num_of_digits[95];
string s, ss;

bool checkInversString()
{
    for (int i = 0; i < ss.length(); i++)
    {
        if (num_of_digits[(int)ss[i] - 32] == 0)
            return false;
        else
            num_of_digits[(int)ss[i] - 32]--;
    };

    for (int i = 0; i <= 94; i++)
        if (num_of_digits[i] > 0)
            return false;
    return true;
}

int main()
{
    for (int i = 0; i <= 94; i++)
        num_of_digits[i] = 0;
    getline(cin, s);
    getline(cin, ss);

    for (int i = 0; i < s.length(); i++)
    {
        num_of_digits[(int)s[i] - 32]++;
    }

    if (checkInversString())
        cout << "true";
    else
        cout << "false";
}