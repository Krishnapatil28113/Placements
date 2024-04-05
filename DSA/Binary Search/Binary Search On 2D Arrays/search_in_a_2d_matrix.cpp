/*
# Question Link: https://leetcode.com/problems/search-a-2d-matrix/
# Problem Statement: To search an element in a 2d matrix

# How to think: (Similar to the previous question)

# Time Complexity: O(n*logm) --> Optimal Approach
# Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &arr, int key)
    {
        int n = arr.size();
        int m = arr[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == key)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Optimal Approach
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &arr, int key)
    {
        int n = arr.size();
        int m = arr[0].size();

        if (m == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i][0] == key)
                {
                    return true;
                }
            }
            return false;
        }
        for (int i = 0; i < n; i++)
        {

            int low = 0;
            int high = m - 1;
            int mid;

            while (low <= high)
            {
                mid = (low + high) >> 1;

                if (arr[i][mid] < key)
                {
                    low = mid + 1;
                }
                else if (arr[i][mid] > key)
                {
                    high = mid - 1;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};