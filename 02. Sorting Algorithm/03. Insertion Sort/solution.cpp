// Insertion Sort
/*
What is Insertion Sort?
Insertion Sort, also known as card player sort, is derived from the idea of inserting a new element into the array.
This algorithm is known as an on-line algorithm due to its flexibility to start even if not all elements exist in the beginning.
So, when the algorithms are running, you can just add other elements and it still runs fine.

How Does it Work?
Operations for Insertion Sort:
- The first element is trivially sorted.
- Choose the first element of the unsorted part of the array.
- Compare this element with the elements in the sorted part of the array until you find the fitting location for this element.
- Repeat steps 2 and 3 until the array is well sorted.
Notice that after the first array, the sorted part of the array has 2 elements. Then, after the second run,
3 elements will be seen in the sorted part of the array. This goes on until the n-1 cycle.

Time Complexity of Insertion Sort
At this point, most of you might agree that the operations of for Insertion Sort are not as intuitive compared to the 
ones for Bubble Sort and Selection Sort. Despite this condition, Insertion Sort performs better Bubble Sort and Selection Sort 
in almost every case. The best case for Insertion Sort happens when the array is already sorted. So, the only 
required comparisons are the ones between the new element that is inserted into the array. That’s why we only need to do 1 pass 
which leaves us with O(n) time complexity.

For the worst case, it happens when the array is in reverse order. In this case, we need to compare all the elements and 
go through each iteration once. The total number of comparisons is:

1 + 2 + … + (n-3) + (n-2) + (n-1) = n(n-1)/2

This might seems familiar and this brings us to O(n²) time complexity for the worst case. In the average case, 
half of the elements of the sorted array are smaller and the remaining half are greater than the inserted element. 
This leads us to compare only half of the array in every pass. Then the total number of comparisons is half of the worst case.

1/2 + 2/2 + … + (n-3)/2 + (n-2)/2 + (n-1)/2 = n(n-1)/4

This still gives us O(n²) time complexity for the average case. However, the number of comparisons is approximately half of the Bubble Sort for the average case.
*/

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int curr = arr[i];
        int j = i-1;
        while(arr[j] > curr && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
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

    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}