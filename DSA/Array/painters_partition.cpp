/*
# Question Link: https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557
# Problem Statement: To find the minimum amount of maximum time taken to paint all the boards
# How to think: Refer 'book_allocation', 'split_array_largest_sum' and 'next-permutation'
# Time Complexity: O(nlogn)
# Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int countMaxPainters(vector<int>& arr, int units) {
    int n = arr.size();

    int count = 1;
    long long sumUnits = 0;

    for(int i=0;i<n;i++) {
        if(sumUnits + arr[i] <= units) {
            sumUnits += arr[i];
        }
        else {
            count++;
            sumUnits = arr[i];
        }
    }

    return count;
}

int findLargestMinDistance(vector<int> &arr, int k)
{
    //    Write your code here.
    int n = arr.size();

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    int mid;
    int count;

    while(low <= high) {
        mid = (low + high)/2;

        count = countMaxPainters(arr, mid);

        if(count > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return low;
}