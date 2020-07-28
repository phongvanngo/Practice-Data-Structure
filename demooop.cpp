#include <iostream>
using namespace std;

class demo
{
private:
    int num;

public:
    demo operator++()
    {
        num++;
        
    };
    friend istream &operator>>(istream &in, demo &a);
    void operator++();
    
};

int main()
{
    int i = 0;
    int a = i++;
    cout << a << " " << i;
}