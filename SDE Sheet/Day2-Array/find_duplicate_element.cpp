/*
# Problem Statement: To find duplicate element in the array
---------------------------------------------------------------
# How to think:
1) Brute and better are easy approaches of sorting and hashing respectively

2) Optimal Approach (Linked List Cycle Method) --> Tortoise and Hare approach
* Link: https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2
* Note: We can use this approach when there is a condition like, 'You are given an array of n integers from 1 to n.'
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int slow = nums[0];
        int fast = nums[0];

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};