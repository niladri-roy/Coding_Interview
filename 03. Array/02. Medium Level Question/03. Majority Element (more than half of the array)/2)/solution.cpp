#include <bits/stdc++.h>
using namespace std;

/*
Solution 1:
Check the count of occurrences of all elements of the array one by one. Start from the first element of the array and 
count the number of times it occurs in the array. If the count is greater than the floor of N/2 then return that element 
as the answer. If not, proceed with the next element in the array and repeat the process.

Time Complexity: O(N^2)
Space Complexity: O(1)
*/
int countEveryElements(vector<int> nums, int n)
{
    int count;
    for (int i = 0; i < n; i++)
    {

        count = 0;
        for (int j = 0; j < n; j++)
            if (nums[j] == nums[i])
                count++;

        if (count > n / 2)
            return nums[i];
    }

    return -1;
}

/*
Solution 2 (Better):

Intuition: Use a better data structure to reduce the number of look-up operations and hence the time complexity. 
Moreover, we have been calculating the count of the same element again and again – so we have to reduce that also.

Approach:
- Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums)
- Here the key will be the element of the array and the value will be the number of times it occurs.
- Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2.
- If yes, return the key
- Else iterate forward.

Time Complexity: O(N)-> Frequency array or O(N log N) -> HashMap
Space Complexity: O(N)
*/
int usingHashMap(vector<int> nums, int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    int ans = -1;
    for (auto x : mp)
    {
        if (x.second > n / 2)
            ans = x.first;
    }
    return ans;
}

/*
Solution 3 (Optimal):

Moore’s Voting Algorithm:

In its most basic form, the algorithm seeks out a majority element if one exists. A majority element is one that appears
more than half of the time in the input elements. However, if there is no majority, the algorithm will not recognize this
and will continue to output one of the items.
The algorithm is divided into two parts. A first pass identifies an element as a majority, and a second pass
confirms that the element identified in the first pass is indeed a majority.
The method will not identify the majority element if it does not exist, and will thus return an arbitrary element.

Intuition: The question clearly states that the nums array has a majority element. Since it has a majority
element we can say definitely assume the count is more than N/2.

Majority element count = N/2 + x;
Minority elements count = N/2 – x;

Where x is the number of times it occurs after reaching the minimum value N/2.
Now, we can say that count of minority elements and majority elements are equal up to a certain point of time in the array.
So when we traverse through the array we try to keep track of the count of elements and which element we are tracking.
Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element.

Approach:
1.Initialize 2 variables:
    - Count –  for tracking the count of element
    - Element – for which element we are counting
2.Traverse through nums array.
    - If Count is 0 then initialize the current traversing integer of array as Element
    - If the traversing integer of array and Element are same increase Count by 1
    - If they are different decrease Count by 1
3.The integer present in Element is the result we are expecting

Dry Run:
Input: { 1,7,2,7,8,7,7}
Index 0: num = 1, count =1
Index 1: num = 1, count =0 ( 7 not equal to 1)
Index 2: num = 2 (as the count is 0 we initialise num to current), count =1
Index 3: num = 2, count =0 ( 7 not equal to 2)
Index 4: num = 8 (as the count is 0 we initialise num to current), count =1
Index 5: num = 8, count =0 ( 7 not equal to 8)
Index 6: num = 7 (as the count is 0 we initialise num to current), count =1

Now we can check for the frequency of 7, i.e, 4 which is > 7/2.
*/
int BoyerMooreVotingAlgorithm(vector<int> nums, int n)
{
    int count = 0;
    int candidate = 0;

    for(int num : nums)
    {
        if(count == 0) candidate = num;
        if(candidate == num) count++;
        else count--;
    }
    return candidate;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans1 = countEveryElements(nums, n);
    cout << "ans1 : "<< ans1 << endl;

    int ans2 = usingHashMap(nums, n);
    cout << "ans2 : "<< ans2 << endl;

    int ans3 = BoyerMooreVotingAlgorithm(nums, n);
    cout << "ans3 : "<< ans3 << endl;

}