#include<bits/stdc++.h>
using namespace std;

void simpleSorting(vector<int> &arr1, int  n)
{
    sort(arr1.begin(), arr1.end());
}

vector<int> countOfNumbers(vector<int> &arr2, int n)
{
    int count1 = 0;
    int count2 = 0;
    int count0 = 0;

    for(int i=0; i<n; i++)
    {
        if (arr2[i] == 0) count0++;
        if (arr2[i] == 1) count1++;
        if (arr2[i] == 2) count2++;
    }

    vector<int> ans;
    while(count0 != 0)
    {
        ans.push_back(0);
        count0--;
    }
    while (count1 != 0)
    {
        ans.push_back(1);
        count1--;
    }
    while (count2 != 0)
    {
        ans.push_back(2);
        count2--;
    }
    return ans;
}

void DutchNationalFlag (vector<int> &arr3, int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high)
    {
        switch (arr3[mid])
        {
            case 0:
            {
                swap(arr3[low++], arr3[mid++]);
                break;
            }
            case 1:
            {
                mid++;
                break;
            }
            case 2:
            {
                swap(arr3[mid], arr3[high]);
                high--;
                break;
            }           

        }
    }
}

void print(vector<int> arrayToPrint, int n)
{

    for(int i=0; i<n; i++)
    {
        cout << arrayToPrint[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the size of the array : " << endl;
    cin >> n;

    vector<int> arr1(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> arr1[i];
    }

    vector<int> arr2;
    arr2.assign(arr1.begin(), arr1.end());

    vector<int> arr3;
    arr3.assign(arr1.begin(), arr1.end());

    simpleSorting(arr1, n);
    print(arr1, n);

    vector<int> ans = countOfNumbers(arr2, n);
    print(ans, n);

    DutchNationalFlag(arr3, n);
    print(arr3, n);
}