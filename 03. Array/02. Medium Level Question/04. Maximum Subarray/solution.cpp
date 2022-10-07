// LeetCode 53
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and 
return its sum.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:
Input: nums = [1]
Output: 1

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, 
which is more subtle.
*/

/*
Using three for loops, we will get all possible subarray in two loops and their sum in another loop, and then return the 
maximum of them.
*/
#include <bits/stdc++.h>
using namespace std;

int threeNestedLoop(vector<int> nums)
{
    int max_sum = INT_MIN;
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    int i, j;
    for (i = 0; i <= n - 1; i++)
    {
        for (j = i; j <= n - 1; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {   
                sum = sum + nums[k];
            }
            if (sum > max_sum) max_sum = sum;
    
        }
    }
    return max_sum;
}

/*
We can also do this problem using only two for loops, we will avoid 3rd loop which was used in above approach, 
instead of that we will create new variable curr_sum, which stores the array sum from ith index to jth index.
*/
int twoNestedLoop(vector<int> nums)
{
    int max_sum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr_sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            curr_sum += nums[j];
            if (curr_sum > max_sum) max_sum = curr_sum;
        }
    }
    return max_sum;
}
/*
Using Divide and Conquer approach, we can find the maximum subarray sum in O(nLogn) time. Following is the Divide and Conquer algorithm.

- Divide the given array in two halves
- Return the maximum of following three
- Maximum subarray sum in left half (Make a recursive call)
- Maximum subarray sum in right half (Make a recursive call)
- Maximum subarray sum such that the subarray crosses the midpoint
The lines 3 and 4 are simple recursive calls. How to find maximum subarray sum such that the subarray crosses the midpoint? 
We can easily find the crossing sum in linear time. The idea is simple, find the maximum sum starting from mid point and 
ending at some point on left of mid, then find the maximum sum starting from mid + 1 and ending with some point on right of mid + 1. 
Finally, combine the two and return the maximum among left, right and combination of both.

Time Complexity: maxSubArraySum() is a recursive method and time complexity can be expressed as following recurrence relation.
T(n) = 2T(n/2) + Θ(n)

Time Complexity : O(n log n)
Auxiliary Space: O(1).
*/
int maxCrossingSum(vector<int> &nums, int l, int m, int h)
{
    // Include elements on left of mid.
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + nums[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++)
    {
        sum = sum + nums[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return sum of elements on left and right of mid
    // returning only left_sum + right_sum will fail for
    // [-2, 1]
    return max(left_sum + right_sum - nums[m],(max (left_sum, right_sum)));
}

// Returns sum of maximum sum subarray in aa[l..h]
int divideAndConquer(vector<int> &nums, int l, int h)
{
    // Invalid Range: low is greater than high
    if (l > h)
        return INT_MIN;
    // Base Case: Only one element
    if (l == h)
        return nums[l];

    // Find middle point
    int m = (l + h) / 2;

    /* Return maximum of following three possible cases
            a) Maximum subarray sum in left half
            b) Maximum subarray sum in right half
            c) Maximum subarray sum such that the subarray
       crosses the midpoint */
    return max(divideAndConquer(nums, l, m - 1), (max(divideAndConquer(nums, m + 1, h), maxCrossingSum(nums, l, m, h))));
}
//-------//
/*
What is Kadane's Algorithm ?
Now after seeing the brute-force solution, you must be thinking about how to optimize this approach. 
So, to optimize the solution, we will be using the concept of dynamic programming here. 
Kadane's Algorithm is an example of dynamic programming algorithm, which uses the solutions of previous sub-problems 
to find the overall optimum solution.

Now let's dive into the working of Kadane's algorithm.

Note: The above algorithm will fail for the case, when there are only negative elements in the array, 
because our global_max is already set to 0. So, to handle that case we have to modify our algorithm. 
We will add current element to the previous subarray only if it results in a greater sum, else we will start the new subarray 
from that element.

Approach:
Initialize: local_max = 0 global_max = INT_MIN

For each element we will follow these steps:
- if (a[i] <= local_max + a[i]) local_max = local_max + a[i]
- else local_max = a[i]
- global_max = max(global_max, local_max)
- global_max is the maximum sum required.

Analyzing the above approach, we can write a recursive formulation for Kadane's algorithm.
local_max[i] = max( A[ i ], A[ i ] + local_max[ i-1 ] )
resulting answer will be the maximum of all the values of local_max[i]

Thus we can see that Kadane's algorithm has optimal substructure property, which means that for calculating a 
maximum subarray ending at a particular position, we have to use the solution of a smaller subproblem 
(the maximum subarray sum ending at the previous position). Thus we can say that Kadane's Algorithm is a 
dynamic programming algorithm.


Time Complexity
Time Complexity of Kadane's Algorithm is O(n)

The way this algorithm uses optimal substructures, this algorithm can be seen as simple dynamic programming. 
This algorithm traverses the whole array only once, so the time complexity depends on the length of the array linearly.
*/
int KadaneAlgorithm(vector<int> &nums)
{
    int max_sum = INT_MIN, temp_sum = 0;
    int s = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        temp_sum += nums[i];
        max_sum = max(max_sum, temp_sum);
        if (temp_sum < 0) temp_sum = 0;
    }

    return max_sum;
}
int main()
{
    int n;
    cout << "Enter the size of the array ";
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans1 = threeNestedLoop(nums);
    cout << "Ans1 : " << ans1 << endl;    

    int ans2 = twoNestedLoop(nums);
    cout << "Ans2 : " << ans2 << endl;

    int ans3 = divideAndConquer(nums, 0, n-1);
    cout << "Ans3 : " << ans3 << endl;

    int ans4 = KadaneAlgorithm(nums);
    cout << "Ans4 : " << ans4 << endl;


}


