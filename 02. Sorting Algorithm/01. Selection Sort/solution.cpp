// Selection Sort
/*
As it is a sorting algorithm, somehow or somewhere we will need comparison, between 2 elements, 
and if condition satisfy we will swap.
So, Basically 
*/
#include<bits/stdc++.h>
using namespace std;

void selectionSort (vector<int> &arr,int n)
{
    for(int i=0; i<n; i++)
    {
        
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array " ;
    cin >> n;

    vector<int> arr(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}