#include <vector>
#include <iostream>

using namespace std;

void duyetvecto()
{
    vector<int> mang;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        mang.push_back(k);
    }
    for (auto i = mang.rbegin(); i != mang.rend(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    cout << mang.at(3);
}

void Vector_2d()

{
    int row, column;
    cin >> row >> column;
    vector<vector<int>> matrix(row);
    for (int i = 0; i < row; i++)
    {
    }
}

void VectorPair()
{
    //declaring vector of pairs 
    vector< pair <int,int> > vect; 
  
    // initialising 1st and 2nd element of 
    // pairs with array values 
    int arr[] = {10, 20, 5, 40,60,90,100 }; 
    int arr1[] = {30, 60, 20, 50}; 
    int n = sizeof(arr)/sizeof(int); 
    cout <<n<<endl;
  
    // Entering values in vector of pairs 
    for (int i=0; i<n; i++) 
        vect.push_back( make_pair(arr[i],arr1[i]) ); 
  
    // Printing the vector 
    for (int i=0; i<n; i++) 
    { 
        // "first" and "second" are used to access 
        // 1st and 2nd element of pair respectively 
        cout << vect[i].first << " "
             << vect[i].second << endl; 
    };
};

int main()
{
    VectorPair();
}