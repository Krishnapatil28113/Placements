/*
# Question Link: https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159
# Problem Statement: To find the kth element of 2 sorted arrays
# How to think: Refer youtube video --> https://www.youtube.com/watch?v=D1oDwWCq50g
# Time Complexity: O(log(min(n1, n2)))
# Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force --> Partially accepted
int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    // Write your code here
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> arr;

    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr.push_back(arr1[i]);
            i++;
        }
        else
        {
            arr.push_back(arr2[j]);
            j++;
        }
    }

    for (; i < n1; i++)
    {
        arr.push_back(arr1[i]);
    }
    for (; j < n2; j++)
    {
        arr.push_back(arr2[j]);
    }

    return arr[k - 1];
}

// Better Approach --> Traverse the arrays and find the kth element by constantly comparing the count of found elements with k
int kthElement(vector<int> &a, vector<int> &b, int n, int m, int k)
{
    // Write your code here
    int i = 0;
    int j = 0;
    int count = 0;
    int ans = -1;

    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            count++;
            if (count == k)
            {
                return a[i];
            }
            else
            {
                ans = a[i];
                i++;
            }
        }
        else
        {
            count++;
            if (count == k)
            {
                return b[j];
            }
            else
            {
                ans = b[j];
                j++;
            }
        }
    }
    for (; i < n; i++)
    {
        if (count == k)
        {
            return a[i];
        }
        else
        {
            ans = a[i];
        }
    }

    for (; j < m; j++)
    {
        if (count == k)
        {
            return b[j];
        }
        else
        {
            ans = b[j];
        }
    }
    return ans;
}

// Optimal Approach --> Binary Search (Refer median of 2 sorted arrays optimal approach video) --> V.V.V.Imp
int kthElement(vector<int> &a, vector<int> &b, int n1, int n2, int k)
{
    // Write your code here
    if (n1 > n2)
        return kthElement(b, a, n2, n1, k);
    int low = max(0, k - n2);
    int high = min(k, n1);
    int mid1;
    int mid2;

    int l1 = INT_MIN;
    int l2 = INT_MIN;
    int r1 = INT_MAX;
    int r2 = INT_MAX;

    int left = k;

    while (low <= high)
    {
        mid1 = (low + high) >> 1;
        mid2 = left - mid1;

        l1 = INT_MIN;
        l2 = INT_MIN;
        r1 = INT_MAX;
        r2 = INT_MAX;

        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
            low = mid1 + 1;
    }
    return 0;
}