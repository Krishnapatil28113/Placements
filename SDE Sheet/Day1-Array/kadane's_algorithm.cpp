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

# Time Complexity: O(N) --> As we are traversing the array only once
# Space Complexity: O(1)

# Note: Follow-Up Question below --> V.V.Imp
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];

            if (sum > maxSum)
            {
                maxSum = sum;
            }

            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxSum;
    }
};

// Kadane's Algorithm

/* Follow-Up question (V.V.Imp)*
 * Printing the subarray with the largest sum
 * If we want to print the subarray, we will need the start and endpoint of the subarray
 * Now, we don't know, which exactly is the subarray that will be giving the largest sum
 * So, we will have to observe something in order to keep track of the subarray giving the largest sum
 * After observing, we get that, whenever the sum is 0, we are starting to compute the sum of a subarray which might lead to the subarray with the largest sum
 * So, we store that particular index in 'start' variable
 * Now, we will take in consideration the subarray only and only if it is increasing the maximum Sum
 * Therefore, if the maximum Sum is increasing, we will assign the 'arrStart' variable to 'start', i.e, the starting point of the subarray and 'arrEnd' to 'i', where the subarray might end
 * Hence, we will get the desired subarray with the maximum sum in between 'arrStart' and 'arrEnd'
 */

int lengthOfMaxSubArray(vector<int> &nums)
{
    int n = nums.size();

    int sum = 0;
    int maxSum = INT_MIN;

    int start;
    int arrStart, arrEnd;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i;
        sum += nums[i];

        if (sum > maxSum)
        {
            maxSum = sum;
            arrStart = start;
            arrEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxSum;
}