/*
# Problem Statement: To find the zig zag level order traversal
---------------------------------------------------------------
# How to think: 
* Now, one thing we can think of is to use a flag for changing decisions
* But, that doesn't serve well, if we have to store all the values in a 'single' vector
* So, as we have to change decisions(or basically change the traversal direction), everytime we change direction, we will need the elements in a reverse order
* So, after taking 2 queues, 1 stack and 1 queue, we will finally come up with a solution involving 2 stacks 
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> result;
        
        if(root == nullptr) {
            return result;
        }
        stack<Node*> s1;
        s1.push(root);
        stack<Node*> s2;
        
        Node* curr = nullptr;
        
        while(s1.empty() == false || s2.empty() == false) {
            
            while(!s1.empty()) {
                curr = s1.top();
                s1.pop();
                
                result.push_back(curr->data);
                
                if(curr->left) {
                    s2.push(curr->left);
                }
                if(curr->right) {
                    s2.push(curr->right);
                }
            }
            
            while(!s2.empty()) {
                curr = s2.top();
                s2.pop();
                
                result.push_back(curr->data);
                
                if(curr->right) {
                    s1.push(curr->right);
                }
                
                if(curr->left) {
                    s1.push(curr->left);
                }
            }
        }
        
        return result;
    }
};