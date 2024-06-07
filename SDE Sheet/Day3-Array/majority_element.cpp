/*
# Problem Statement: To find the element which appears more than n/2 times
---------------------------------------------------------------
# How to think:
1) Optimal Approach --> Moore Voting Algorithm
* Video Link: https://www.youtube.com/watch?v=nP_ns3uSh80&ab_channel=takeUforward

# Algorithm Steps:
* Start by picking the first element of the array as the 'ele'
* Initialize the counter to 0
* While you don't reach the end of the array, do the following steps:
    --> If the count is 0, set the value of 'ele' to 'nums[i]'
    --> Else,
        --> Check if the current element is equal to 'ele' or not
            --> If equal, increment the count
            --> Else, decrement the count

# Intuition:
* for ex: [2,2,1,1,1,2,2]
* Now, here, we are reducing the search space by eliminating the first portion of the array, i.e, [2,2,1,1]
* As there is no greater element than n/2 in this considered array(we get to know this by the count's zero value)
* So, now the search space or the array gets reduced to [1,2,2]
* BECAUSE, if there is a greater element, it will be there in this new array, because we have already checked for the previous
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Better Approach 1
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int limit = (n / 2);
        int prev = 0;
        int curr = 1;
        int cnt = 1;
        while (curr < n)
        {
            if (nums[curr] == nums[prev])
            {
                cnt++;
                prev = curr;
                curr++;
            }
            else
            {
                if (cnt > limit)
                {
                    return nums[prev];
                }
                else
                {
                    cnt = 1;
                    prev = curr;
                    curr++;
                }
            }
        }

        if (cnt > limit)
        {
            return nums[prev];
        }
        return limit;
    }
};

// Optimal Approach --> Moore Voting Algorithm
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        int count = 0;
        int ele;

        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                ele = nums[i];
                count++;
            }
            else
            {
                if (nums[i] == ele)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }

        return ele;
    }
};