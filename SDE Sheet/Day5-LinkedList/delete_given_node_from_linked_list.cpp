/*
# Problem Statement: To delete a node from the linked list without traversing the linked list(Just the pointer to the node to be deleted is given)
                     --> Every element is unique
                     --> The node to be deleted is not the last node
---------------------------------------------------------------
# How to think: 
* "Every element is unique", signifies that, we will have to do something with the value of the nodes
* Now, if we just have to deal with values and not addresses, we can just change values to remove some element with a value x
* Now, to change the value, we don't exactly know what value should it be replaced with because if we replace it with some random value, it might break the uniqueness of the linked list
* So, it suggests that, we will have to use the values in the linked list itself, to replace it with
* So, then we can come up with a idea to copy all the values from the nodes ahead of the given node and then delete the last node
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = node;
        ListNode* temp = node->next;
        while(temp != nullptr) {
            node->val = temp->val;
            prev = node;
            node = temp;
            temp = temp->next;
        }

        if(prev) {
            prev->next = node->next;
        }
    }
};