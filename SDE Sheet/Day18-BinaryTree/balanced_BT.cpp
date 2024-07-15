/*
# Problem Statement: To check whether a BT is balanced or not
---------------------------------------------------------------
# How to think:
* First thing we will think of is to calculate the left and right of every node and then compare them to check condition
* Now, the main concern here is, the function wants us to return bool and we need count of left and right to check the condition
* So, we can make a seperate function and call it recursively
* Now comes the question, 'if the condition fails, how will we return false?'
* So, in case the condition fails, we can simply return a unique number(-1) in this case
    --> and if we encounter that number even once in left or in right, we will simply return that number until the end
* Finally, we will check whether the count we got was that number(-1) or not
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
    int checkBalanced(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = checkBalanced(root->left);
        if(lh == -1) return -1;
        int rh = checkBalanced(root->right);
        if(rh == -1) return -1;

        if(abs(rh-lh) > 1) return -1;
        return 1+max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        int height = checkBalanced(root);

        if(height == -1) return false;
        return true;
    }
};