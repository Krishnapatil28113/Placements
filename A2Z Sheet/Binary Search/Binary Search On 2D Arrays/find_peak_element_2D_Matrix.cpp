/*
# Question Link: https://leetcode.com/problems/find-a-peak-element-ii/
# Problem Statement: To find the peak element in a matrix

# How to think:
1. Optimal Approach: (Binary Search)
* If we try to search in a 1D array using binary search, we just have to compare the elements to the left and right for a particular element
* But, here, as we are dealing with 2D matrix, we will also have to compare with the elements above and below
* So, to eliminate that, we can think of finding the maximum element in a particular column to which mid is pointing to
* And according to that comparison, we can eliminate the left and right halfs

# Time Complexity: O(nlogm)
# Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force --> Find the maximum element in the matrix and return it's indexes
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int maxEle = INT_MIN;
        int x;
        int y;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (maxEle < mat[i][j])
                {
                    maxEle = mat[i][j];
                    x = i;
                    y = j;
                }
            }
        }

        return {x, y};
    }
};

// Optimal Approach --> Binary Search
class Solution
{
public:
    int maxElement(vector<vector<int>> &mat, int n, int mid)
    {
        int row;
        int maxEle = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (maxEle < mat[i][mid])
            {
                maxEle = mat[i][mid];
                row = i;
            }
        }
        return row;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m;
        int mid;

        int row;
        int left;
        int right;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            row = maxElement(mat, n, mid);

            left = (mid - 1) >= 0 ? mat[row][mid - 1] : -1;
            right = (mid + 1) < m ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right)
            {
                return {row, mid};
            }
            else if (mat[row][mid] < left)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return {0, 0};
    }
};