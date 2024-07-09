/*
# Problem Statement: Inorder Traversal without using extra space (Morris Inorder Traversal)
---------------------------------------------------------------
# How to think: 
* Now, if we do not have to use space, we will have to have some mechanism to go back to previous nodes
* Previously, we were using recursion or a stack to go back to previous nodes
* Now, we dont have either of them
* So, if I can connect the links of the nodes somehow in an inorder fashion, my job will be done
* So, I will use the concept of Threaded BT
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(root == nullptr) {
            return inorder;
        }
        else {
            TreeNode* curr = root;
            while(curr != nullptr) {
                if(curr->left != nullptr) {
                    TreeNode* prev = curr->left;

                    while(prev->right != nullptr && prev->right != curr) {
                        prev = prev->right;
                    }

                    if(prev->right == nullptr) {
                        prev->right = curr;
                        curr = curr->left;
                    }
                    else {
                        prev->right = nullptr;
                        inorder.push_back(curr->val);
                        curr = curr->right;
                    }
                }
                else {
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};