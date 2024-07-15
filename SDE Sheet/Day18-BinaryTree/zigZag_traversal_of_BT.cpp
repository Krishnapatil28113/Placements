/*
# Problem Statement: To find the zig zag traversal of BT
---------------------------------------------------------------
# How to think: 
* Using flag to change decision
* Refer to Day 17 zig zag traversal
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
    void swap(int* val1, int* val2) {
        int temp = *val1;
        *val1 = *val2;
        *val2 = temp;
    }
    void reverse(vector<int>& vec) {
        int n = vec.size();
        for(int i=0;i<n/2;i++) {
            swap(&vec[i], &vec[n-i-1]);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) {
            return result;
        }
        else {
            queue<TreeNode*> q;
            q.push(root);
            TreeNode* curr = nullptr;
            bool flag = true;
            while(!q.empty()) {
                
                vector<int> vec;
                int size = q.size();
                for(int i=1;i<=size;i++) {
                    curr = q.front();
                    q.pop();

                    vec.push_back(curr->val);
                    if(curr->left) {
                        q.push(curr->left);
                    }
                    if(curr->right) {
                        q.push(curr->right);
                    }
                }

                if(flag) {
                    result.push_back(vec);
                    flag = false;
                }
                else {
                    reverse(vec);
                    result.push_back(vec);
                    flag = true;
                }
            }

            return result;
        }
    }
};