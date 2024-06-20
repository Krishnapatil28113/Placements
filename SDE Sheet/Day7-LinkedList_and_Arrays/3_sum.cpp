/*
# Problem Statement: To find the triplets whose sum is equal to 0 (No Duplicates)
---------------------------------------------------------------
# How to think:
* Think of the brute force solution and analyze its time complexity
* Based on the time complexity of the brute force solution, i.e, O(n^3 * log(no_of_unique_triplets)); try to reduce this complexity
* Proceed further for the most optimal solution and try to reduce the time or the space comlexity or both
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Better Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        set<vector<int>> s;
        int n = nums.size();

        int third = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            set<int> hashSet;
            for (int j = i + 1; j < n; j++) {
                third = -(nums[i] + nums[j]);
                if(hashSet.find(third) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> result(s.begin(), s.end());

        return result;
    }
};

// Optimal Solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            else {
                int j = i+1;
                int k = n-1;
                while(j < k) {
                    long long sum = (nums[i] + nums[j] + nums[k]);
                    if(sum < 0) {
                        j++;
                    }
                    else if(sum > 0) {
                        k--;
                    }
                    else {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        result.push_back(temp);
                        j++;
                        k--;
                        while(j < k && nums[j] == nums[j-1]) j++;
                        while(j < k && nums[k] == nums[k+1]) k--;
                    }
                }
            }
        }

        return result;
    }
};