/*
# Problem Statement: Iterative Preorder of BT
---------------------------------------------------------------
# How to think: 
* Similar to inorder
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        } else {
            TreeNode* temp = root;
            stack<TreeNode*> st;

            while (temp != nullptr) {
                result.push_back(temp->val);
                st.push(temp);
                temp = temp->left;
            }

            while (temp != nullptr || st.empty() != true) {
                if (temp != nullptr) {
                    result.push_back(temp->val);
                    st.push(temp);
                    temp = temp->left;
                } else {
                    temp = st.top();
                    st.pop();
                    temp = temp->right;
                }
            }

            return result;
        }
    }
};