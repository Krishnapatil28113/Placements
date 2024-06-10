/*
# Problem Statement: To find the indexes of elements that add up to the given target
---------------------------------------------------------------
# How to think: 

1) Brute: O(n^2)
2) Better:
* Optimization -> Time Complexity -> O(n^2) to O(n) or O(nlogn)
* Reduce time, utilize space
* Therefore, we will come up with a solution to use a map data structure
* For every element, we can check the value required to sum up to target in the map

2) Optimal: (Optimal only if we have to find the existence)
* Now, if we don't have to use extra space, so we will have to increase some more time but lesser than O(N^2), i.e, NlogN
* So, we will have to use something like two pointers approach
* So, in two pointers, we have to make a decision at every step, whether to increment the left pointer or decrement the right pointer
* We won't be able to make that decision if the array will be unordered or unsorted
* So, we sort them (nlogn) and then we apply two pointer approach (n)
* Time complexity: O(nlogn) --> Since O(nlogn) grows faster as n grows, than O(n)
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Better Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        unordered_map<int, int> umap;
        for(int i=0;i<n;i++) {
            umap[nums[i]] = i;
        }

        int el;
        for(int i=0;i<n;i++) {
            el = target - nums[i];
            if(umap.find(el) != umap.end()) {

                if(umap[el] == i) {
                    continue;
                }
                return {i, umap[el]};
            }
        }
        return {-1, -1};
    }
};