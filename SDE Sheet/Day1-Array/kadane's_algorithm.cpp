/*
# Problem Statement: To find the largest subarray sum
---------------------------------------------------------------
# How to think:

1) Brute Force:
* First thing we can think of is to generate all the subarrays, calculate its sum, compare it at every stage, and return the maximum sum

2) Better Approach:
* Improvement in brute force solution as brute force is having time complexity reaching nearly O(n^3)
* Improvement is to to just add the next element, i.e, nums[j] to the sum, rather than calculating the entire sum of the subarray which we were doing in the brute force

3) Optimal Approach(KADANE'S ALGORITHM):

# Algorithm:
* Assign a variable maxSum to store the maximum sum
* Start iterating the array and keep a track of the sum in the variable sum
* At each step compare the value of the sum with the maxSum
    --> If sum is greater than maxSum; update maxSum to sum
* In the same iteration, check for the value of sum variable
    --> If the value of the sum variable is less than 0; set the value of sum to be 0
    --> as there is no point in carrying that value of sum forward because it will be reducing the further sum
* At the end of the iteration, maxSum will contain the maximum sum of the subarray
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int maxSum = INT_MIN;
        for(int i=0;i<n;i++) {
            sum += nums[i];

            if(sum > maxSum) {
                maxSum = sum;
            }

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};