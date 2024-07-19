/*
# Problem Statement: To check whether the given BT is symmetric or not
---------------------------------------------------------------
# How to think: 
* Can think of traversing the left and right portion of the tree simultaneously checking each node
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
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if(left == nullptr || right == nullptr) return left == right;
        else if(left->val != right->val) return false;
        return checkSymmetric(left->right, right->left) && checkSymmetric(left->left, right->right);
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        return checkSymmetric(left, right);
    }
};