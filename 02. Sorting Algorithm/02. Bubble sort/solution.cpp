// Bubble Sort
/*
What is Bubble Sort?
Bubble Sort, which is also known as Sinking Sort is a simple sorting algorithm that operates by comparing every pair of 
adjacent elements. First, it compares the first and the second element, then the second and the third element, and so on. 
Should the former element is larger than the latter, these two elements will be interchanged.
The algorithm gets its name as the bigger elements will “bubble” towards the rightmost position. 
After each cycle, the largest element will be the last element in the unsorted part of the array.

How Does it Work?
The operations that are done in Bubble Sort:
- Compare the first two elements.
- If the former element is larger, interchange the two elements.
- Repeat steps 1 and 2 until you reach the end of the array.
- Repeat steps 1, 2, and 3 until all of the elements are sorted.

The caveat is in the first run, you will need to make n-1 comparisons, suppose the number of elements in the array is n. 
In the second run, you will only need to make n-2 comparisons, not doing the last comparison since the last element at 
this point is the largest. That means, in each run, the number of comparisons reduces by 1.

Time Complexity of Bubble Sort:
Bubble Sort operations are basic, however, it’s time complexity is not the best. 
The time complexity for best case/worst case/average case is O(n²) as in any array the total number of comparisons is:
(n-1) + (n-2) + … + 3 + 2 + 1 = n(n-1)/2
For any array, the algorithms will do exactly n(n-1)/2 comparisons although the array has already been sorted. 
Because of the O(N²) time complexity of Bubble Sort, it is rarely used in real-world implementations. 
The growth of running time will be very large as n becomes larger.
*/
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array ";
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}