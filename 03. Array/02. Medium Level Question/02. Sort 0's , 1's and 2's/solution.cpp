// LeetCode 75
/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2] 

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
*/

#include<bits/stdc++.h>
using namespace std;
/*
Solution 1: Using Sort Library Function
---- Don't Use this in LeetCode ----
Time Complexity: O(N log N)
Space Complexity: O(1)
*/
void simpleSorting(vector<int> &arr1, int  n)
{
    sort(arr1.begin(), arr1.end());
}
/*
Solution 2: Keep Count of 0's , 1's and 2's
Intuition:
Keep Counts of 0s 1s and 2s and put them in separate vector in order.
Time Complexity: O(N^N)
Space Complexity: O(N)
*/
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

/*
DUTCH NATIONAL FLAG
Dutch National Flag (DNF) - It is a programming problem proposed by Edsger Dijkstra.
The flag of the Netherlands consists of three colors: white, red, and blue.
The task is to randomly arrange balls of white, red, and blue in such a way that balls of the same color are placed together.
For DNF (Dutch National Flag), we sort an array of 0, 1, and 2's in linear time that does not consume any extra space.
We have to keep in mind that this algorithm can be implemented only on an array that has three unique elements.

ALGORITHM -
Take three-pointers, namely - low, mid, high.
We use low and mid pointers at the start, and the high pointer will point at the end of the given array.

CASES -
If array [mid] =0, then swap array [mid] with array [low] and increment both pointers once.
If array [mid] = 1, then no swapping is required. Increment mid pointer once.
If array [mid] = 2, then we swap array [mid] with array [high] and decrement the high pointer once.

Intuition behind DNF?
We need to arrange or segregate three different staffs in a order.

Application
The Dutch National Flag Algorithm can be used in implementing Quicksort efficiently for inputs with majorly
repeated elements. Quicksort exhibits its worst-case performance in such inputs taking O(n^2) time.
The Dutch National Flag Algorithm with its 3-Way Partitioning method can help resolve the partition routine
separating the values into three groups:

- The values less than the pivot,
- The values equal to the pivot,
- And, the values are greater than the pivot.

This linear-time partition routine is similar to 3–way partitioning
for the Dutch national flag problem. This will make Quicksort work efficiently in O(n) time for inputs
having identical values.

Time Complexity: O(N)
Space Complexity: O(1)
*/
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