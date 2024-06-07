/*
# Problem Statement: To find the elements which appear more than (n/3) times
---------------------------------------------------------------
# How to think: 

1) Optimal Approach:
* Firstly, we need to know the Moore Voting Algorithm
* If we know that for finding the element which appears more than (n/2) times, we can easily solve this problem
* Now, in (n/2) problem, there was one and only one element that would be greater than (n/2)
* But, here we will have to observe about the count of elements greater than (n/3)
* So, we can observe that, there will only be 2 elements which will be greater than (n/3)
* So, we will consider 2 variables el1 and el2 and keep 2 counters cnt1 and cnt2 for these 2 variables and apply the same algorithm here

* Note: Edge case differences pointed out below(***)
    --> el1 and el2 should not be same, because if they are, there counters will clash
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Optimal Approach --> O(2n), O(1)
// Note: The space required is for storing 2 elements, so it is equivalent to O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        int limit = (n/3);
        int cnt1=0,cnt2=0;
        int el1, el2;
        for(int i=0;i<n;i++) {
            if(cnt1 == 0 && nums[i] != el2) { // ***
                el1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && nums[i] != el1) {// ***
                el2 = nums[i];
                cnt2++;
            }
            else if(nums[i] == el1) {
                cnt1++;
            }
            else if(nums[i] == el2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] == el1) {
                cnt1++;
            }
            else if(nums[i] == el2) {
                cnt2++;
            }
        }

        if(cnt1 > limit && cnt2 > limit) {
            return {el1, el2};
        }
        else if(cnt1 > limit) {
            result.push_back(el1);
            return result;
        }
        else if(cnt2 > limit){
            result.push_back(el2);
            return result;
        }
        else {
            return result;
        }
    }
};