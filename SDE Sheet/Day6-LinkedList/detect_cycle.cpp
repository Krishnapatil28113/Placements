/*
# Problem Statement: To find if there exists a cycle or not
---------------------------------------------------------------
# How to think: 
* Tortoise and Hare Algorithm --> Need to know the algorithm
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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        do {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            } else {
                slow = slow->next;
                fast = fast->next->next;
            }
        } while (slow != fast);

        return true;
    }
};