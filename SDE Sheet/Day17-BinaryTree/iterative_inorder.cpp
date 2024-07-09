/*
# Problem Statement: To find the iterative inorder of BT
---------------------------------------------------------------
# How to think: 
* Write down the inorder of the BT
* Now, the left most node of the binary tree is the first occuring element in the inorder traversal
* So, we will have to reach it first in order to print it
* While we go to the left of the BT, we encounter the temp pointer is pointing to null
* So, now we will have to go back to the previous node in order to search for the right node
* That we can do using a stack
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
        vector<int> result;

        if (root == nullptr) {
            return result;
        } else {
            stack<TreeNode*> st;
            TreeNode* temp = root;
            while (temp != nullptr) {
                st.push(temp);
                temp = temp->left;
            }

            while (temp != nullptr || st.empty() != true) {

                if (temp == nullptr) {
                    temp = st.top();
                    st.pop();
                    result.push_back(temp->val);
                    temp = temp->right;
                }
                else {
                    st.push(temp);
                    temp = temp->left;
                }
            }

            return result;
        }
    }
};