/*
# Problem Statement: To fetch the nodes appearing in the left view of the binary tree
---------------------------------------------------------------
# How to think: 
--> Iterative Version
    * Our aim is to find the left view of the BT and we gotta ignore the nodes getting blocked
    * Now, there can be many situations in which there will be another node in the right side of the tree which will be visible in the left view
    * So, we cannot just traverse the left portion of the BT
    * Therefore, after observing, we can figure out that, we need to look for the nodes which are the first in each level while looking from the left
    * So, we can perform a level order traversal, while simultaneously keeping track of the first node in each level

--> Note: Revise the iterative code too (Was not able to come up with the idea of figuring out the first node in each level)
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

// Recursive Version
void fetch(Node* root, int level, vector<int>& result) {
    if(root == nullptr) return;
    if(level == result.size()) {
        result.push_back(root->data);
    }
    fetch(root->left, level+1, result);
    fetch(root->right, level+1, result);
}

vector<int> leftView(Node *root)
{
    vector<int> result;
    if(root == nullptr) return result;
    fetch(root, 0, result);
    
    return result;
}

// Iterative Version(V.V.IMP)**
vector<int> leftView(Node *root)
{
    vector<int> result;
    if(root == nullptr) return result;
    
    Node* curr = root;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int qSize = q.size();
        for(int i=1;i<=qSize;i++) {
            curr = q.front();
            q.pop();
            if(i == 1) {
                result.push_back(curr->data);
            }
            
            if(curr->left) {
                q.push(curr->left);
            }
            
            if(curr->right) {
                q.push(curr->right);
            }
        }
    }
    
    return result;
}