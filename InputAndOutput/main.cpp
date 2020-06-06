#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void getline_after_cin_1()
{
    string s, ss;
    int k;
    cout << "nhap k: ";
    cin >> k;
    for (char c = getchar(); c != '\n'; c = getchar())
        ;
    cout << "Nhap s: ";
    getline(cin, s);
    for (char c = getchar(); c != '\n'; c = getchar())
        ;
    cout << "Nhap ss: ";
    getline(cin, ss);
    cout << k << " " << s << endl;
    cout << "Thanks";
}

void use_limit()
{
    string s, ss;
    int k;

    cout << "nhap k: ";
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap s: ";
    getline(cin, s);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ss: ";
    getline(cin, ss);

    cout << k << " " << s << endl;
    cout << "Thanks";
}
int main()
{
    use_limit();
}