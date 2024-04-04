/*
# Question Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
# Problem Statement: To find the median of 2 sorted arrays
# How to think: Refer yt video --> https://www.youtube.com/watch?v=C2rRzz-JDk8
# Time Complexity: O(log(min(n1, n2)))
# Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force (Merging two arrays and accessing the middle element)
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

// Better Approach (Traversing both the arrays once and finding the middle element based on the median indexes calculated prior to traversal)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();

        int n = n1 + n2;

        if (n % 2 != 0)
        {
            int ele;
            int index = (n - 1) / 2;

            int count = 0;
            int i = 0;
            int j = 0;

            while (i < n1 && j < n2)
            {
                if (arr1[i] <= arr2[j])
                {
                    if (count == index)
                    {
                        return (double)arr1[i];
                    }
                    else
                    {
                        count++;
                        i++;
                    }
                }
                else
                {
                    if (count == index)
                    {
                        return (double)arr2[j];
                    }
                    else
                    {
                        count++;
                        j++;
                    }
                }
            }

            for (; j < n2; j++)
            {
                if (count == index)
                {
                    return (double)arr2[j];
                }
                count++;
            }
            for (; i < n1; i++)
            {
                if (count == index)
                {
                    return (double)arr1[i];
                }
                count++;
            }
        }
        else
        {
            int ele1 = -1;
            int ele2 = -1;

            int index1 = (n / 2) - 1;
            int index2 = n / 2;

            int count = 0;
            int i = 0;
            int j = 0;

            while (i < n1 && j < n2)
            {
                if (arr1[i] <= arr2[j])
                {
                    if (count == index1)
                    {
                        ele1 = arr1[i];
                    }

                    if (count == index2)
                    {
                        ele2 = arr1[i];
                    }
                    count++;
                    i++;
                }
                else
                {
                    if (count == index1)
                    {
                        ele1 = arr2[j];
                    }

                    if (count == index2)
                    {
                        ele2 = arr2[j];
                    }
                    count++;
                    j++;
                }
            }

            for (; j < n2; j++)
            {
                if (count == index1)
                {
                    ele1 = arr2[j];
                }
                if (count == index2)
                {
                    ele2 = arr2[j];
                }
                count++;
            }
            for (; i < n1; i++)
            {
                if (count == index1)
                {
                    ele1 = arr1[i];
                }
                if (count == index2)
                {
                    ele2 = arr1[i];
                }
                count++;
            }
            return (double)(ele1 + ele2) / 2.0;
        }
        return 0.0;
    }
};

// Optimal Approach (Binary Search) --> Refer yt video(link provided above!)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        int low = 0;
        int high = n1;
        int mid1;
        int mid2;

        int left = (n1 + n2 + 1) / 2;

        while (low <= high)
        {
            mid1 = (low + high) >> 1;
            mid2 = left - mid1;

            l1 = INT_MIN;
            l2 = INT_MIN;
            r1 = INT_MAX;
            r2 = INT_MAX;

            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1)
            {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};