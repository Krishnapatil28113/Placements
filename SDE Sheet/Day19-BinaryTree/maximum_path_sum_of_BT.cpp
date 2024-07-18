/*
# Problem Statement: To find the sum of the maximum path of a BT (Asked in Amazon)
---------------------------------------------------------------
# How to think:
* If for every node, we can find the maximum path sum, we can generate the max sum
* For every node, the max path sum will be the value of the node + the max of the left and right sum being generated

// Got Stuck here
* While doing this process, we need to keep track of the maximum sum being generated at each node, i.e max(maxi, node->val + left + right)
* Note: If we are getting the sum(node->val + max(lh, rh)) to be negative, we will not take it, therefore, return 0
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
    int calculateMaxi(TreeNode* node, int& maxi) {
        if(node == nullptr) return 0;
        int lh = calculateMaxi(node->left, maxi);
        int rh = calculateMaxi(node->right, maxi);

        maxi = max(node->val + lh + rh, maxi);
        if((node->val + max(lh, rh)) < 0) return 0;
        return (node->val + max(lh, rh));
    }

    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        int val = calculateMaxi(root, maxi);
        return maxi;
    }
};