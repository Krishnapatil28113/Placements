/*
# Question Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
# Problem Statement: To Search in a 2D matrix where the rows and columns, both are sorted in ascending order

# How to think:

1. Optimal Approach: (To traverse the arrays in such a way that, )

# Time Complexity:
# Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

// Better Approach --> Binary Search for 1 of the 2 parameters, i.e, either for the row or the column
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

// Optimal Approach --> Elimination (Using the "CONCEPT" of Binary Search; NOT the generic binary search)
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
        int row = 0;
        int col = m - 1;

        while (row <= n - 1 && col >= 0)
        {
            if (key > arr[row][col])
            {
                row++;
            }
            else if (key < arr[row][col])
            {
                col--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};