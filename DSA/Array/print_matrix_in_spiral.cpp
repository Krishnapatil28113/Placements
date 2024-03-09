/*
Explanation:

1. How to think:
* Firstly we will have to figure out how we want to print the elements
* After figuring this out, we know that we need to print the elements from the left to right, then top to bottom
  then, right to left, and then bottom to top; then again from left to right
* And, we have to constantly increment and decrement the pointers accordingly --> As the spiral gets smaller and smaller as we get inside the matrix
* Keep on doing this until the pointers cross each other

1. Time Complexity: O(m*n) --> The number of elements in the matrix
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0;
    int top = 0;
    int right = m - 1;
    int bottom = n - 1;

    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i <= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i <= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    return 0;
}