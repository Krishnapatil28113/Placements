/*
# Problem Statement: To find the max depth of BT
---------------------------------------------------------------
# How to think: 
* Basic logic -> At each node, we will consider the contribution of that node to be 1
* Now, we will add the count coming from the left, then before moving to the right, we will have to store it in some variable
* Because, if the cnt from the right is greater than the left count, we will need to have something to compare it with
* After storing the left count, set the counter to 1 again(missed it while writing the code), and then proceed towards right
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};