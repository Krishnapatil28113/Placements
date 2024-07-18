/*
# Problem Statement: To find the path from one of the nodes to the other in a BT
---------------------------------------------------------------
# How to think: 
* The path will always pass through their lowest common ancestor
* So, find the lca and then start traversal from there, looking for both the nodes, simultaneously keeping track of the string
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
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if (root == nullptr)
            return nullptr;
        if (root->val == p || root->val == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }
        if (right)
            return right;
        else if (left)
            return left;
        return nullptr;
    }

    string lcaToStart = "", lcaToEnd = "";
    void fetchStrings(TreeNode* root, int p, int q, string& s) {
        if (root == nullptr)
            return;
        if (root->val == p)
            lcaToStart = s;
        else if (root->val == q)
            lcaToEnd = s;

        s.push_back('L');
        fetchStrings(root->left, p, q, s);
        s.pop_back();

        s.push_back('R');
        fetchStrings(root->right, p, q, s);
        s.pop_back();
    }

    string getDirections(TreeNode* root, int p, int q) {
        TreeNode* lca = lowestCommonAncestor(root, p, q);

        string s = "";
        fetchStrings(lca, p, q, s);

        for (int i = 0; i < lcaToStart.length(); i++) {
            lcaToStart[i] = 'U';
        }

        return lcaToStart + lcaToEnd;
    }
};