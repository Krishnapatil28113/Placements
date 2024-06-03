/*
# Problem Statement: To find duplicate element in the array
---------------------------------------------------------------
# How to think: 
1) Brute and better are easy approach of sorting and hashing respectively

2) Optimal Approach (Linked List Cycle Method) --> Tortoise and Hare approach
* Note: We can use this approach when there is a condition like, 'the elements in the array are from [1,n] where n is related to the size of the array
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        fast = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast =  nums[fast];
        }

        return slow;
    }
};