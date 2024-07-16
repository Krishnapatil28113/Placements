/*
# Problem Statement: To find the boundary traversal of a BT
---------------------------------------------------------------
# How to think: 
* Boundary traversal can be obtained by:
    --> Fetching left nodes
    --> Fetching leaf nodes
    --> Fetching right nodes in reverse
* Can write seperate recursive functions for doing the same

* NOTE: Sometimes, iterative traversal is better when recursive might get complicated(2nd solution)**
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    Node* fetchLeft(Node* root, vector<int>& result) {
        if(root == nullptr) {
            return nullptr;
        }
        else if((root->left == nullptr && root->right == nullptr)) {
            return root;
        }
        result.push_back(root->data);
        Node* lh = fetchLeft(root->left, result);
        if(lh == nullptr) {
            Node* rh = fetchLeft(root->right, result);
            return rh;
        }
        return lh;
    }
    
    void fetchLeaf(Node* root, vector<int>& result) {
        if(root == nullptr) {
            return;
        }
        if(root->left == nullptr && root->right == nullptr) {
            result.push_back(root->data);
            return;
        }
        fetchLeaf(root->left, result);
        fetchLeaf(root->right, result);
    }
    
    Node* fetchRight(Node* root, vector<int>& result, stack<int>& st) {
        if(root == nullptr) {
            return nullptr;
        }
        else if((root->left == nullptr && root->right == nullptr)) {
            return root;
        }
        st.push(root->data);
        Node* right = fetchRight(root->right, result, st);
        if(right == nullptr) {
            Node* left = fetchRight(root->left, result, st);
            return left;
        }
        return right;
    }
    
    void fetchReverseRight(Node* root, vector<int>& result) {
        stack<int> st;
        fetchRight(root, result, st);
        
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> result;
        result.push_back(root->data);
        
        if(root->left == nullptr && root->right == nullptr) {
            return result;
        }
        // left nodes
        fetchLeft(root->left, result);
        
        // leaf nodes
        fetchLeaf(root, result);
        
        // // reverse right nodes
        fetchReverseRight(root->right, result);
        
        return result;
    }
};


class Solution {
public:
    bool isLeaf(Node* root) {
        return (root->left == nullptr && root->right == nullptr);
    }
    
    void fetchLeft(Node* root, vector<int>& result) {
        Node* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) {
                result.push_back(curr->data);
            }
            
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    void fetchLeaf(Node* root, vector<int>& result) {
        if(isLeaf(root)) {
            result.push_back(root->data);
            return;
        }
        if(root->left) fetchLeaf(root->left, result);
        if(root->right) fetchLeaf(root->right, result);
    }
    
    void fetchReverseRight(Node* root, vector<int>& result) {
        stack<int> st;
        Node* curr = root->right;
        while(curr) {
            if(!isLeaf(curr)) {
                st.push(curr->data);
            }
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> result;
        result.push_back(root->data);
        
        if(root->left == nullptr && root->right == nullptr) {
            return result;
        }
        // left nodes
        fetchLeft(root, result);
        
        // leaf nodes
        fetchLeaf(root, result);
        
        // // reverse right nodes
        fetchReverseRight(root, result);
        
        return result;
    }
};