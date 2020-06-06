#include <iostream>
using namespace std;

void MergeArr(int Arr[], int start, int end)
{
    int mid = (start + end) / 2;
    int *Res = new int [end - start +1];
    int iFrist = start,
        iSecond = mid + 1,
        iRes = -1;

    while (iFrist <= mid && iSecond <= end){
        iRes++;
        if (Arr[iFrist] < Arr[iSecond]) 
        {
            Res[iRes] = Arr[iFrist];
            iFrist++;
        } else {
            Res[iRes] = Arr[iSecond];
            iSecond++;
        };
    };
    while (iFrist<=mid) {
        iRes++;
        Res[iRes] = Arr[iFrist];
        iFrist++;
    };
    while (iSecond<=end) {
        iRes++;
        Res[iRes] = Arr[iSecond];
        iSecond++;
    };
    iRes=0;

    for (int iArr = start;iArr<=end;iArr++) {
        Arr[iArr] = Res[iRes];
        iRes++; 
    };
    delete[] Res;
};

void SplitArr(int Arr[], int start, int end)
{
    int mid;
    if (start < end - 1)
    {
        mid = (start + end) / 2;
        SplitArr(Arr, start, mid);
        SplitArr(Arr, mid + 1,end);
    };
    MergeArr(Arr, start, end);
}

void MergeSort(int Arr[], int start, int end)
{
    
    SplitArr(Arr, start, end);
};

int main()
{
    int n;
    cin >> n;
    int *Arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> Arr[i];
    }
    MergeSort(Arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << "\n";
    }
    return 0;
};
