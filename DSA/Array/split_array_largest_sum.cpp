/*
# Question Link: https://leetcode.com/problems/split-array-largest-sum/
# Problem Statement: To find the largest sum we can assign to a subarray to k people which is minimum

# How to think:
* Consider an array -> [1,2,3,4,5] and consider the elements as the money to be assigned to k people
* Suppose k = 2

1. Brute Force Approach
* Now, the possible cases in which we can distribute this money in 2 people can be:
    --> 1   |   2,3,4,5 --> Max = 14
    --> 1,2   |   3,4,5 --> Max = 12
    --> 1,2,3   |   4,5 --> (Max = 9)
    --> 1,2,3,4   |   5 --> Max = 10

* Here, we need to give money to 2 people in such a way that the maximum should be as lesser as possible,
    so that it is not unfair to the others

* Now, we will start checking from 1
    --> Whether 1 is the maximum amount of money we can give to a person so that the money gets distributed to 2 people? --> The answer is no
    --> Similarly start checking for other elements
    --> We come to checking for 5 which is the maximum element of the array
    --> Now, if we check, 5 being the maximum amount of money we can distribute, the total number of people required to distribute
        the money in the array will be 4; BUT we need to distribute it into 2 people; so 5 is not the maximum money that can be given to a person
    --> After checking for other elements, we get that 9 is the element which is the maximum money that can be given to a person
        in order to distribute all the money in the array to 2 people!

2. Optimal Approach:
* We know the range of the elements which can be the maximum money that can be assigned
* Range: Max_element(arr) --> Sum(arr)
* Apply BINARY SEARCH on this range!

# Time Complexity:
# Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int> &nums, long long sum)
{
    int n = nums.size();

    int count = 1;
    int sumCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (sumCount + nums[i] <= sum)
        {
            sumCount += nums[i];
        }
        else
        {
            count++;
            sumCount = nums[i];
        }
    }

    return count;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    int mid;
    int count;

    while (low <= high)
    {
        mid = (low + high) / 2;
        count = countSubarrays(nums, mid);
        if (count > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low;
}