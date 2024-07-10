/*
# Problem Statement: To clone a linked list with random pointer
---------------------------------------------------------------
# How to think: 

1) Good Solution:
* As we start cloning the linked list step by step, we come across a situation in which we dont have a node to point to
* This suggest that we should create all the nodes at the beggining itself and store them in a map to access them later

2) Optimal Solution:
* Now, to optimize space, we will have to avoid the use of hashmap
* But, we have to store the nodes in order to access them later
* Therefore, we can only access them using the links we have in the original linked list
* This suggests that, we will have to manipulate the links of the original linked list
* Therefore, we can think of inserting the copy nodes in between the nodes of the original linked lists
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Good Solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return head;
        }
        else {

            unordered_map<Node*, Node*> mpp;
            //1. Creation of Nodes
            Node* temp = head;
            while(temp != nullptr) {
                Node* newNode = new Node(temp->val);
                mpp[temp] = newNode;
                temp = temp->next;
            }

            //2. Connecting the next and random pointers
            temp = head;
            while(temp != nullptr) {
                mpp[temp]->next = mpp[temp->next];
                mpp[temp]->random = mpp[temp->random];
                temp = temp->next;
            }

            return mpp[head];
        }
    }
};


// Optimal Solution(V.Imp)**
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return head;
        }
        else {
            Node* temp = head;
            
            //1. Copying the nodes
            while(temp != nullptr) {
                Node* newNode = new Node(temp->val);
                newNode->next = temp->next;
                temp->next = newNode;

                temp = temp->next->next;
            }

            //2. Connecting the random pointers
            temp = head;
            while(temp != nullptr) {
                if(temp->random) {
                    temp->next->random = temp->random->next;
                    temp = temp->next->next;
                }
                else {
                    temp->next->random = temp->random;
                    temp = temp->next->next;
                }
            }

            //3. Connecting the next pointers
            Node* dummyNode = new Node(0);
            Node* res = dummyNode;
            temp = head;

            while(temp != nullptr) {
                res->next = temp->next;
                res = res->next;
                temp->next = temp->next->next;

                temp = temp->next;
            }

            return dummyNode->next;
        }
    }
};
