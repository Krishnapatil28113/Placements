/*
Question Link: https://leetcode.com/problems/subarray-sum-equals-k/

# Explanation:

1. Process/Concept:
* What we have to do is store the occurences of the prefixSum in the map, for ex (3,1); it means 3 has occured once before
* So in each iteration we can increment the count by prefixSum[sum-k]
* mpp[0] = 1 --> This line is of the utmost importance because if the first element equals to k, there should be something in the map which corresponds to prefixSum[rem]
* return the count in the end
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        map<int, int> mpp;

        mpp[0] = 1;

        int i = 0;
        int sum = 0;
        int count = 0;

        while (i < n)
        {

            sum += nums[i];

            int rem = sum - k;
            count += mpp[rem];
            mpp[sum] += 1;

            i++;
        }
        return count;
    }
};

int main()
{
    return 0;
}