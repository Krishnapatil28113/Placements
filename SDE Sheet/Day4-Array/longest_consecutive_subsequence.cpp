/*
# Problem Statement: To find the longest consecutive subsequence of any array in O(n)
---------------------------------------------------------------
# How to think: 

1) Optimal Approach
* To solve this question in O(n), we will have to use some space
* Now, when we think of using space to store the elements, we come across vector, HashMap, HashArray, etc
* But, here we can use only HashArray
    --> But, HashArray was using unnecessary space as most of its elements will be 0
* Now, another data set that can be used will be a set
    --> Intuition 1: Now, set also removes duplicate elements, hence, it will help get rid of the duplicate numbers
    --> Intuition 2: The search, delete and update operation in an unordered set takes O(1) time
* Therefore, we go with set data structure to search for elements which are smaller than the current element to find the starting position
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Brute Force
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();

        if(n == 0 || n == 1) {
            return n;
        }
        int cnt = 1;
        int temp = 0;
        int j=0;
        int maxCount = INT_MIN;
        for(int i=0;i<n;i++) {
            temp = i;
            j = 0;
            while(j < n) {
                if(j == temp) {
                    j++;
                }
                else {
                    if(arr[j] == (arr[temp] + 1)) {
                        cnt++;
                        temp = j;
                        j = 0;
                    }
                    else {
                        j++;
                    }
                }
            }

            maxCount = max(cnt, maxCount);
            cnt = 1;
        }

        return maxCount;
    }
};

// Optimal Solution --> Using Set
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();

        if(n == 0 || n == 1) {
            return n;
        }
        else {
            unordered_set<int> s;
            for(int i = 0 ; i < n ; i++) {
                s.insert(arr[i]);
            }

            int cnt = 1;
            int maxCount = 1;
            for(auto it = s.begin(); it != s.end(); it++) {
                if(s.find((*it)-1) != s.end()) {
                    continue;
                }
                else {
                    int temp = *it;
                    while(s.find(temp+1) != s.end()) {
                        cnt++;
                        temp = temp+1;
                    }

                    maxCount = max(cnt, maxCount);
                    cnt = 1;
                }
            }

            return maxCount;
        }
        return 1;
    }
};