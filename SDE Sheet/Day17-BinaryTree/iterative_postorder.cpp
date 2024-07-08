/*
# Problem Statement: To find the iterative postorder of a tree
---------------------------------------------------------------
# How to think: 
* Firstly, we need to observe the flow of the postorder
* It is left right root
* And if we want to use a stack to retrieve these elements, we will have to store them in a reverse order, i.e, root-right-left 
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) {
            return result;
        }
        else {
            TreeNode* temp = root;
            stack<TreeNode*> st1;
            stack<TreeNode*> st2;

            st1.push(temp);
            while(!st1.empty()) {
                
                temp = st1.top();
                st1.pop();

                st2.push(temp);

                if(temp->left) {
                    st1.push(temp->left);
                }

                if(temp->right) {
                    st1.push(temp->right);
                }
            }


            while(!st2.empty()) {
                result.push_back(st2.top()->val);
                st2.pop();
            }

            return result;
        }
    }
};