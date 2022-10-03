// LeetCode 70
/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct 
ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 4
*/


/*
So, here in this problem you will get number of stairs n.

You are asked to climb the stairs. The condition is you can only 
take 1 or 2 steps each time.

Return the total number of ways.

So, ae we need to return the number of ways, so this could be
Recursive or Dynamic Programming Approach

*/
#include<bits/stdc++.h>
using namespace std;

int recursive(int n)
{
    /*
    The steps for recursion:
    1. Indexing
    2. Do all the staffs mentioned in the question
    3. Return the staffs

    Here, the understanding of the scenario is important,
    We have been asked to climb the steps.
    
    Here, is an example of the such kind of scenario:
    Imagine we want to reach step no. 5
    So, as per the question we could climb 1 or 2 steps.
    So, either we have to stand on step no. 4 and climb 1 step, i.e (5-1)step
    or, we have to stand on step no. 3 and climb 2 steps, i.e (5-2)step

    So, If we want to reach n no. step
    either we need to start from (n-1)step or (n-2)step.
    So, every step the value of n will be reduced by 1 or 2
    Till we reach 0.

    So, here is the base case, if we reach 0 or 1, we will return 1.
    */

    if (n == 0)
        return 1;
    if (n == -1)
        return 0;

    return recursive(n - 1) + recursive(n - 2);
}

int memoization(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n == -1)
        return 0;
    if(dp[n] != -1) return dp[n];
    return dp[n] = recursive(n - 1) + recursive(n - 2);
}
void climbStairs(int n)
{
    int ans1 = recursive(n);
    cout << "Recursive ans = " << ans1 << endl;

    vector<int> dp(n+1, -1);
    int ans2 = memoization(n, dp);
    cout<< "Memoization ans = " << ans2 << endl;

    
}


int main()
{
    int n;
    cout << "Enter the number of steps" << endl;
    cin >> n;

    climbStairs(n);
}