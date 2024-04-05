/*
# Question Link: https://leetcode.com/problems/search-a-2d-matrix/
# Problem Statement: To search an element in a 2d matrix

# How to think:

1. Optimal Approach:
* Now, we have to perform this operation in O(log(n*m)) time
* So, one thing that comes in our mind is, to convert the 2D matrix into a single array and then perform the generic Binary Search on it
* But, to do that it will take a lot of time
* Therefore, we just figure out the index of the element to search; let's say mid=5
* Now, to search for index 5, it is at the position (1,1)
* Therefore, we will use the x and y coordinates as:
    --> x = mid / m; (1)
    --> y = mid % m; (1)
    where m is the size of the inner arrays

# Time Complexity: O(log(n*m)) --> Optimal Approach
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

// Better Approach
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

// Optimal Approach --> O(log(n*m))
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
                    return true;
            }
            return false;
        }

        int low = 0;
        int high = n * m - 1;
        int mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;
            int x = mid / m;
            int y = mid % m;

            if (arr[x][y] > key)
            {
                high = mid - 1;
            }
            else if (arr[x][y] < key)
            {
                low = mid + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};