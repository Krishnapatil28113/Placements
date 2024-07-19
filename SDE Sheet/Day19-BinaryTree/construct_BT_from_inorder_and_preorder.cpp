/*
# Problem Statement: To construct an unique BT using given inorder and preorder
---------------------------------------------------------------
# How to think: 
* The start value of the preorder vector will always be the root of the tree
* After that, we need to assign the left and right nodes for the root
* So, we need the left node to be assigned to the root, and it will always be the next node in the preorder
* But, we have written the logic to always take the first node of preorder vector in order to make it a root
* So, we will change the index of the preorder according to the given condition
* So, for every step or every node, the preorder and inorder will be defined(based on the index) 
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
    TreeNode* generateTree(vector<int>& preorder, vector<int>& inorder, int startI, int endI, int startP, int endP, auto& hashMap) {
        // Base condition
        if(startP > endP || startI > endI) {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(preorder[startP]);
        int index = hashMap[preorder[startP]];
        int numsLeft = index - startI;
        node->left = generateTree(preorder, inorder, startI, index-1, startP + 1, startP + numsLeft, hashMap);
        node->right = generateTree(preorder, inorder, index+1, endI, startP + numsLeft + 1, endP, hashMap);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        map<int, int> hashMap;
        for (int i = 0; i < inorder.size(); i++) {
            hashMap[inorder[i]] = i;
        }

        int n = inorder.size();
        int m = preorder.size();
        return generateTree(preorder, inorder, 0, n - 1, 0, m - 1, hashMap);
    }
};