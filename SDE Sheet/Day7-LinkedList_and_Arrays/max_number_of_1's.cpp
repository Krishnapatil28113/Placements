/*
# Problem Statement: To find the maximum number of 1's
---------------------------------------------------------------
# How to think:
* Pretty straight forward

# Note:
* 1 thing we are doing here is, we are incrementing the count and simulatneously updating the maxCount as well
* It is better than the other way round, i.e, updating the maxCount, whenever we encounter any element other than 1
* We update the maxCount as soon as we encounter any 1; this has 2 benefits:
    --> First of all, if we update maxCount everytime we encounter element other than 1, there is a high possibility, that we will have to do it many times as the number of 1's will be lesser compared to the size of the array
    --> Secondly, we don't have to add the statement 'maxCount = max(count, maxCount);' , after the for loop ends, hence reducing the chances of errors
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int maxCount = INT_MIN;
        for(int i=0;i<n;i++) {
            if(nums[i] == 1) {
                count++;
                maxCount = max(count, maxCount);
            }
            else {
                count = 0;
            }
        }

        return maxCount;
    }
};