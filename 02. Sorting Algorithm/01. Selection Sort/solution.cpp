// Selection Sort
/*
What is Selection Sort?
Selection Sort intuitive idea is selecting the smallest element in the list and put it in the first position of the array.
The next step is to choose the second smallest element and put it in the second position.

Selection Sort gets its name since in this technique selection for the smallest element is done over and over.
After each cycle, the smallest element will be in the first position of the unsorted part of the array.

How Does it Work?
The steps to do Selection Sort are:
1. Find the smallest element by iterating/running through the array.
2. Put it in the first position of the array.
3. Repeat steps 1 and 2 for the remaining unsorted part of the array until all of the elements are sorted.

You should notice that in the first cycle, you will need to iterate through n elements. In the second run,
you will only need to go through n-1 elements. In the third run, as you guessed it, you need to iterate through n-2 elements.
In every cycle, you will be iterating through 1 fewer element in the array.

Time Complexity of Selection Sort
The Selection Sort operation is very intuitive. For me, the operations are more intuitive than the bubble sort. 
The time complexity for best case/worst case/average case is O(n²) as in the first pass n-1 comparisons are done. 
The second pass requires n-2 comparisons and so on. Thus the total number of comparisons is:

(n-1) + (n-2) + … + 3 + 2 + 1 = n(n-1)/2

For any array, the algorithms will do exactly n(n-1)/2 comparisons although the array has already been sorted. 
Because of the O(N²) time complexity of Selection Sort, it is rarely used in real-world implementations. 
The growth of running time will be very large as n becomes larger.
*/
#include<bits/stdc++.h>
using namespace std;

void selectionSort (vector<int> &nums,int n)
{
    for(int i=0; i<n; i++)
    {
        int mini = i;
        for(int j=i+1; j<n; j++)
        {
            if(nums[mini] > nums[j])
            {
                mini = j;
            }
        }
        swap(nums[mini], nums[i]);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array " ;
    cin >> n;

    vector<int> nums(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    selectionSort(nums, n);
    for(int i=0; i<n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

}