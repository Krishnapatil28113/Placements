/*
# Problem Statement: To remove duplicates and return the count of unique elements
* Note: The problem also requires all the unique elements to be placed in the front of the array
---------------------------------------------------------------
# How to think:
* As we know the array is sorted, we can think of comparing consecutive elements deleting the duplicates
* But deleting the duplicates will utilize a lot of time
* So, we won't be thinking of deleting the elements, rather will focus on replacing the elements
* So, we will think of finding the first different element and then replace the duplicate with this element and so on
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Optimal Approach
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();

        if(n == 1) {
            return n;
        }
        else {
            int i=0;
            int j=1;

            while(j < n) {
                if(arr[j] != arr[i]) {
                    arr[i+1] = arr[j];
                    j++;
                    i++;
                }
                else {
                    j++;
                }
            }

            return (i+1);
        }
    }
};