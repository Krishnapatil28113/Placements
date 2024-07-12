/*
# Problem Statement: To fetch the top view of BT
---------------------------------------------------------------
# How to think: 
* Vertical Order Traversal -> LORD
* While finding the top view, if we encounter 1 element for any vertical, we wont be considering all the other nodes in the same vertical
* Because, we already got the first element from the top, why check for others
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
    vector<int> topView(Node *root)
    {
        vector<int> result;
        if(root == nullptr) return result;
        
        queue<pair<Node*, int>> q;
        map<int, int> mpp;
        Node* curr = nullptr;
        int line = 0;
        q.push({root, 0});
        
        while(!q.empty()) {
            curr = q.front().first;
            line = q.front().second;
            q.pop();
            
            if(mpp.find(line) == mpp.end()) {
                mpp[line] = curr->data;
            }
            
            if(curr->left) {
                q.push({curr->left, line-1});
            }
            if(curr->right) {
                q.push({curr->right, line+1});
            }
        }
        
        for(auto it : mpp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};