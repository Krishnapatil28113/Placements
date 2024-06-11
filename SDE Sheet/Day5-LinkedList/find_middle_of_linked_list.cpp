/*
# Problem Statement: To find the middle of a linked list
---------------------------------------------------------------
# How to think: 
* Simple Tortoise and Hare Algorithm
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

// Tortoise and Hare Algorithm
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        else {
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }

            return slow;
        }
    }
};