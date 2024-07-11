/*
# Problem Statement: To find the vertical order traversal of a BT
---------------------------------------------------------------
# How to think: 
* Similar to the bottom view of the BT
* The main difference here is the condition
    --> If there are 2 nodes having the same vertical and the same level, sort them according to their value
* So, in order to do that, we just needed to use a data structure multiset which stores values in a sorted order
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;

        if(root == nullptr) return result;

        TreeNode* curr = nullptr;
        int line = 0;
        int level = 0;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        map<int, map<int, multiset<int>>> mpp;
        while(!q.empty()) {
            curr = q.front().first;
            line = q.front().second.first;
            level = q.front().second.second;
            
            q.pop();

            mpp[line][level].insert(curr->val);

            if(curr->left) {
                q.push({curr->left, {line-1, level+1}});
            }
            if(curr->right) {
                q.push({curr->right, {line+1, level+1}});
            }
        }

        for(auto p : mpp) {
            vector<int> vec;
            for(auto q : p.second) {
                vec.insert(vec.end(), q.second.begin(), q.second.end());
            }

            result.push_back(vec);
        }

        return result;
    }
};