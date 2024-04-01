/*
# Question Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
# Problem Statement: To find the median of 2 sorted arrays
# How to think:
# Time Complexity:
# Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int j = 0;

        vector<int> arr;

        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                arr.push_back(nums1[i]);
                i++;
            }
            else
            {
                arr.push_back(nums2[j]);
                j++;
            }
        }

        for (; i < m; i++)
        {
            arr.push_back(nums1[i]);
        }
        for (; j < n; j++)
        {
            arr.push_back(nums2[j]);
        }

        int N = arr.size();

        if (N % 2 == 0)
        {
            return (double)(arr[(N / 2) - 1] + arr[N / 2]) / 2.0;
        }
        else
        {
            return (double)arr[N / 2];
        }
    }
};