/*
# Problem Statement: To find the lowest common ancestor of a BT
---------------------------------------------------------------
# How to think:
* If nothing comes to the mind, try to think for the current situation
* Which node I am on; is it the node I want?
* If it isn't, then I should move to the left and look for the node I want
* If I found null on both the sides for the current node, that means there is no node in this branch
* So, we can return nullptr
* Otherwise, if we encounter the desired node, return the node
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) {
            return nullptr;
        }
        else {
            if(root == p || root == q) {
                return root;
            }
            TreeNode* ln = lowestCommonAncestor(root->left, p, q);
            TreeNode* rn = lowestCommonAncestor(root->right, p, q);

            if(ln == nullptr && rn != nullptr) {
                return rn;
            }
            else if(ln != nullptr && rn == nullptr) {
                return ln;
            }
            else if(ln != nullptr && rn != nullptr) {
                return root;
            }
            return nullptr;
        }
    }
};