/*
# Problem Statement: To find the Right View
---------------------------------------------------------------
# How to think: 
* Similar to left view
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    vector<int> rightView(Node *root)
    {
        vector<int> result;
        if(root == nullptr) return result;
        
        Node* curr = root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i=1;i<=n;i++) {
                curr = q.front();
                
                if(i == 1) {
                    result.push_back(curr->data);
                }
                
                if(curr->right) {
                    q.push(curr->right);
                }
                
                if(curr->left) {
                    q.push(curr->left);
                }
                
                q.pop();
            }
        }
    }
};