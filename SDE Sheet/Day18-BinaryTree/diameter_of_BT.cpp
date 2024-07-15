/*
# Problem Statement: To find the longest distance between two nodes in a BT
---------------------------------------------------------------
# How to think:
* First thing we can think of is to find the maximum height on both the sides of the node
* Now, for every node, we can add the left and right maximum heights and update that height with a maximum variable

--> (GOT STUCK HERE)
* NOTE: Whenever we need to update any value, we can keep a variable while calling the recursive function and update it without making its instance everytime we make a function call
* For ex: lh = calculateDiam(root->left, maxi);
* Here, the original instance of maxi is begin passed and getting updated, so it will act as a global variable
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

    int calculateDiam(TreeNode* root, int& maxi) {
        if(root == nullptr) {
            return 0;
        }
        int lh = calculateDiam(root->left, maxi);
        int rh = calculateDiam(root->right, maxi);

        maxi = max(maxi, lh+rh);
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int height = calculateDiam(root, maxi);
        return maxi;
    }
};