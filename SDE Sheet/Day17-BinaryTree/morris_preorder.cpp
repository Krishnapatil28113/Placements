/*
# Problem Statement: Iterative Preorder without using extra space(Morris Preorder Traversal)
---------------------------------------------------------------
# How to think: 
* Refer Morris Inorder Traversal
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preorder;
    if(root == nullptr) {
        return preorder;
    }
    else {
        TreeNode* curr = root;
        while(curr != nullptr) {
            if(curr->left == nullptr) {
                preorder.push_back(curr->data);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while(prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                if(prev->right == nullptr) {
                    prev->right = curr;
                    preorder.push_back(curr->data);
                    curr = curr->left;
                }
                else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
    }

    return preorder;
}