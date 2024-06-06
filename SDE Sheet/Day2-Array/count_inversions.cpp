/*
# Problem Statement: To count the number of times some element to the left is greater than the element to its right in the array
---------------------------------------------------------------
# How to think: 
1) Brute Force:
* 2 loops

2) Optimal Approach: (V.V.Imp)**
* Video Link: https://www.youtube.com/watch?v=AseUmwVNaoY&ab_channel=takeUforward
* Let us take an array, for ex. [1,4,5,2,3]
* Now, in this array, if we carefully ovserve, we can see that there are 2 sorted portions
    --> [1,4,5]
    --> [2,3]
* Now, if we carefully observe, we can see
    --> If 4 is greater than 2, it can form a pair, therefore we can increase the count by 1
    --> BUT, as the 1st array is sorted, we know that the elements ahead of 4 will also be greater than 2 and will also form a pair
    --> So, we will increment the count by the number of elements ahead of 4, i.e, 2

* Now, every array won't be sorted in this order, so we will have to convert the array into 2 sorted arrays
* And the method to break the array and then sort it is 'MERGE SORT'
* While backtracking, we can count the inversions, as the arrays while backtracking will be sorted
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

int merge(long long *arr, int low, int mid, int high) {

  int left = low;
  int right = mid + 1;
  vector<int> temp;

  int cnt = 0;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      cnt += (mid - left + 1);
      temp.push_back(arr[right]);
      right++;
    }
  }

  while(left <= mid) {
      temp.push_back(arr[left]);
      left++;
  }
  while(right <= high) {
      temp.push_back(arr[right]);
      right++;
  }

  for(int i=low;i<=high;i++) {
      arr[i] = temp[i-low];
  }
  return cnt;
}

int mergeSort(long long *arr, int low, int high) {
  int cnt = 0;
  if (low >= high)
    return cnt;
    
  int mid = (low + high) / 2;
  cnt += mergeSort(arr, low, mid);
  cnt += mergeSort(arr, mid + 1, high);
  cnt += merge(arr, low, mid, high);
  return cnt;
}

long long getInversions(long long *arr, int n) {

  return mergeSort(arr, 0, n - 1);
  // merge(arr, mid+1, high, n);
}