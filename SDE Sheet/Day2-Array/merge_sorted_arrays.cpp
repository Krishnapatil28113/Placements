/*
# Problem Statement: To merge 2 sorted arrays into a single array
---------------------------------------------------------------
# How to think:
* Firstly, the array is having n zeroes at the end to accomodate n elements from nums2
* So, we should think of starting the iteration from the back
* Secondly, we need to think about the element which should be placed at the end of nums1
    --> This element should be the greatest among the 2 arrays
    --> So, we will compare the last elements of the both the arrays, as we know that both the arrays are sorted, there greatest elements would be at the end

**NOTE: 
* When we are comparing elements and we find that the element in nums1 is greater than nums2, then we need to find the perfect position of the element of nums2 in nums1
* So, we keep updating the elements at the kth index with the ith index value and keep on decrementing i to compare it with j to find the perfect position of the element in nums2

---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0) {
                if (nums1[i] <= nums2[j]) {
                    nums1[k] = nums2[j];
                    k--;
                    j--;
                } else {
                    nums1[k] = nums1[i];
                    k--;
                    i--;
                }
            }
            else {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
    }
};