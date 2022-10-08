// LeetCode 118
/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/

#include<bits/stdc++.h>
using namespace std;

/*
When you see the image above, you get a pretty good idea of what you are supposed to do here. 
Think about the image as a matrix now where each line is basically a row in the matrix. 
So, first things first, if you are at the edge of the matrix, the value is 1, that’s for sure. 
Now, what about the inner elements? Well, any inner element is obtained by doing the sum of the 2 values 
present in the row just above it, i.e., if the element is at index (i, j), then matrix[i][j] can be obtained 
by doing matrix[i – 1][j – 1] + matrix[i – 1][j].
*/

int main()
{
    int n;
    cout << "Enter row numbers: " << endl;
    cin >> n;

    vector<vector<int>> r(n);

    for (int i = 0; i < n; i++)
    {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++)
        {    
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<r[i].size(); j++)
        {
            cout << r[i][j] << " " ;
        }
        cout << endl;
    }
}