/*
# Problem Statement: Find bottom view of BT
---------------------------------------------------------------
# How to think: 
* Need to know vertical order traversal --> V.V.IMP**
* link - https://www.youtube.com/watch?v=0FtVY6I4pB8
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

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> result;
        if(root == nullptr) return result;
        
        map<int, int> mpp;
        Node* curr = nullptr;
        int line = 0;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));
        
        while(!q.empty()) {
            curr = q.front().first;
            line = q.front().second;
            q.pop();
            
            mpp[line] = curr->data;
            
            if(curr->left) {
                q.push(make_pair(curr->left, line-1));
            }
            if(curr->right) {
                q.push(make_pair(curr->right, line+1));
            }
        }
        
        for(auto it : mpp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};