// LeetCode 229
/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

Example 4:
Input: nums = [1,1,2,2,3,3]
Output: []


Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109

Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include <bits/stdc++.h>
using namespace std;

/*
Solution 1: keepCount nested loop approach

Approach: Simply count the no. of appearance for each element using nested loops and whenever you find the count of 
an element greater than N/3 times, that element will be your answer.

TC: O(N^2)
SC: O(1)
*/
vector<int> keepCount(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }

        if (count > (n / 3))
            ans.push_back(nums[i]);
    }
    return ans;
}

/*
Solution 2: HashMap Approach

Approach: Traverse the whole array and store the count of every element in a map. After that traverse through 
the map and whenever you find the count of an element greater than N/3 times, store that element in your answer.

TC: O(N)
SC: O(N)
*/
vector<int> hashMap(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    vector<int> ans;
    for (auto x : mp)
    {
        if (x.second > n / 3)
        {
            ans.push_back(x.first);
        }
    }
    return ans;
}

/*
Solution 3: Boyer Moore’s Voting Algorithm

num1 and num2 will store our currently most frequent and second most frequent element.
count1 and count2 will store their frequency relatively to other numbers.
We are sure that there will be a max of 2 elements which occurs > N/3 times because there cannot be if you do a simple math addition.
Let, ele be the element present in the array at any index.

Since it’s guaranteed that a number can be a majority element, hence it will always be present at the last block, 
hence, in turn, will be on nums1 and nums2. For a more detailed explanation, please watch the video below.4

TC : O(N) + O(N) = O(N)
SC : O(1)
*/
vector<int> BoyerMooreVotingAlgorithm(vector<int> &nums)
{
    int n = nums.size();

    int num1 = -1, num2 = -2;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];

        if (ele == num1)
            count1++;
        else if (ele == num2)
            count2++;

        else if (count1 == 0)
        {
            num1 = ele;
            count1++;
        }
        else if (count2 == 0)
        {
            num2 = ele;
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    vector<int> ans;
    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == num1)
            count1++;
        if (nums[i] == num2)
            count2++;
    }

    if (count1 > (n / 3))
        ans.push_back(num1);
    if (count2 > (n / 3))
        ans.push_back(num2);

    return ans;
}

void print(vector<int> toPrint)
{
    int n = toPrint.size();
    for (int i = 0; i < n; i++)
    {
        cout << toPrint[i] << " ";
    }
    cout << endl;
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

    vector<int> ans1 = keepCount(nums);
    print(ans1);

    vector<int> ans2 = hashMap(nums);
    print(ans2);

    vector<int> ans3 = BoyerMooreVotingAlgorithm(nums);
    print(ans3);

}