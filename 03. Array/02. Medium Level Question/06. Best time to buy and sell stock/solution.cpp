// LeetCode 121
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the 
future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;
/*
Solution 1:
Intuition: We can simply use 2 loops and track every transaction and maintain a variable ans to contain the max value 
among all transactions.

Approach:
- Use a for loop of ‘i’ from 0 to n.
- Use another for loop of j from ‘i+1’ to n.
- If arr[j] > arr[i] , take the difference and compare and store it in the ans variable.
- Return ans.

TC: O(N^2)
SC: O(1)
*/
int nestedLoopApproach(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                ans = max(nums[j] - nums[i], ans);
            }
        }
    }

    return ans;
}

/*
Solution 2:
Intuition: We will linearly travel the array. We can maintain a minimum from the starting of the array and
compare it with every element of the array, if it is greater than the minimum then take the difference and
maintain it in max, otherwise update the minimum.

Approach:
- Create a variable ans and store 0 initially.
- Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
- Run a for loop from 0 to n.
- Update the minPrice if it is greater than the current element of the array
- Take the difference of the minPrice with the current element of the array and compare and maintain it in ans.
- Return the ans.

TC: O(N)
SC: O(1)
*/
int maintainMinElementApproach(vector<int> &nums)
{
    int ans = 0;
    int n = nums.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        minPrice = min(minPrice, nums[i]);
        ans = max(ans, nums[i] - minPrice);
    }

    return ans;
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

    int ans1 = nestedLoopApproach(nums);
    cout << "Ans 1 : " << ans1 << endl;

    int ans2 = maintainMinElementApproach(nums);
    cout << "Ans 2 : " << ans2 << endl;


}