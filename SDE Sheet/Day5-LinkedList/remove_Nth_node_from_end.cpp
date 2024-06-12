/*
# Problem Statement: To remove the nth node from the end of the linked list
---------------------------------------------------------------
# How to think: 

1) Optimal Approach
* We know that we have to travel till the nth from the end
* So, we will need to travel (len-n) nodes from the beginning, len is the length of the linked list
* Now, we don't know the length of the linked list and we also do not have to traverse the linked list again
* So, what we can do is
    --> We can use a fast pointer for traversing n nodes
    --> Now, if the fast pointer traverses the rest of the nodes, i.e, (len-n), it will reach the end node
    --> Therefore, we can assign a slow pointer pointing to the head
    --> These slow and fast pointer will traverse (len-n) nodes together, hence slow reaching the node previous to the node to be deleted and fast reaching the end node
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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;

        for(int i=0;i<k;i++) {
            fast = fast->next;
        }

        if(fast == nullptr) return head->next;
        ListNode* slow = head;
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        if(fast == nullptr) {
            return head->next;
        }

        ListNode* delNode = slow->next;
        if(slow) {
            slow->next = slow->next->next;
        }

        return head;
    }
};