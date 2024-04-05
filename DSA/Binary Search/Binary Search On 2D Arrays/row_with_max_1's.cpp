/*
# Question Link: https://www.naukri.com/code360/problems/row-of-a-matrix-with-maximum-ones_982768
# Problem Statement: To find a row's index containing maximum number of 1's

# How to think:

1. Brute Force:
* Extreme naive solution that comes up to our mind is to traverse all the arrays and keep a count of maximum number of 1's
* Time Complexity: O(n*m)
* Space Complexity: O(1)

2. Optimal Approach: (Binary Search)
* We know, that the time complexity of the brute force solution is O(n*m);
    so, we can optimize it either to:
        --> O(n) - Which is not possible
        --> O(n*logm) - Possible
* So, we can reduce the time complexity to O(n*logm) by using Binary Search(logm)
* Also, we have been given that all the rows are sorted --> Another hint to apply binary search
* Time Complexity: O(n*logm)
* Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force --> Traverse every array and find the array which has maximum number of 1's
int rowWithMax1s(vector<vector<int>> &arr, int n, int m)
{
    // Write your code here.
    int index = -1;
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }

    return index;
}

// Optimal Approach --> Binary Search (All the rows, i.e, all the arrays are sorted; therefore, we can apply binary search)
int rowWithMax1s(vector<vector<int>> &arr, int n, int m)
{
    //    Write your code here.
    int index = -1;
    int count = 0;
    int maxCount = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = m;
        int mid;
        while (low <= high)
        {
            mid = (low + high) >> 1;
            if (arr[i][mid] == 0)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        count = m - low;
        if (count > maxCount)
        {
            maxCount = count;
            count = 0;
            index = i;
        }
    }

    return index;
}