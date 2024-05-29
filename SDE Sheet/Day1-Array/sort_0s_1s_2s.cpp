/*
# Problem Statement: To sort an array in such a way that all 0's come first, then all 1's and then all 2's
---------------------------------------------------------------
# How to think:
1) Better Approach --> O(2N), O(1)
* Keep 3 count variables for 0,1 and 2 respectively

2) Optimal Approach --> O(N),O(1)
* Watch the Optimal Approach(V.IMP)
https://www.youtube.com/watch?v=tp8JIuCXBaU&list=PLgUwDviBIf0oF6QL8m22w1hIDC1vJ_BHz&index=21
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Dutch National Flag Algorithm --> V.IMP
class Solution {
public:
    void swap(int* val1, int* val2) {
        int temp = *val1;
        *val1 = *val2;
        *val2 = temp;
    }

    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0, mid = 0, high = n-1;
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(&nums[low], &nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(&nums[mid], &nums[high]);
                high--;
            }
        }
    }
};