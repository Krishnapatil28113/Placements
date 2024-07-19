/*
# Problem Statement: To construct a BT from given inorder and postorder
---------------------------------------------------------------
# How to think: 
* Similar to (construct BT using given inorder and preorder)
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
    TreeNode* genTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, auto& hashMap) {
        if(inStart > inEnd || postStart < postEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postStart]);
        int index = hashMap[root->val];
        int numsRight = inEnd - index;
        root->right = genTree(inorder, index + 1, inEnd, postorder, postStart - 1, postStart - numsRight, hashMap);
        root->left = genTree(inorder, inStart, index-1, postorder, postStart - numsRight - 1, postEnd, hashMap);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hashMap;
        for(int i=0;i<inorder.size();i++) {
            hashMap[inorder[i]] = i;
        }

        return genTree(inorder, 0, inorder.size()-1, postorder, postorder.size()-1, 0, hashMap);
    }
};