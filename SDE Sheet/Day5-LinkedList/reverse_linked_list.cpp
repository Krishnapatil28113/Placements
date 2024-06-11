/*
# Problem Statement: To reverse a linked list
---------------------------------------------------------------
# How to think: 

1) Recursive
* Now, if we want to reverse the linked list in a recursive manner, firstly
    --> Try to break the problem into smaller sub-parts and try to solve these smaller sub-parts
    --> To solve these smaller sub-parts, we will need to perform some logic which will be performed for every recursive function call
    --> For example, here the reversal logic is:
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;

2) Iterative
* We can start thinking by considering 2 nodes at a time
* For ex: 1->2->3->4->5
* Now, we can consider 1 and 2
    --> Now, to reverse 1 and 2, we will have to access 1, as well as 2
    --> Now, if we reverse 1 and 2, we will not have access to 3, so we will need another pointer pointing to 3, and so on...
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

// Iterative Version -> Sliding Window(3 pointers)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        else {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            ListNode* ahead = head->next;

            while(curr != nullptr && curr->next != nullptr) {
                curr->next = prev;
                prev = curr;
                curr = ahead;
                ahead = ahead->next;
            }

            curr->next = prev;

            return curr;
        }
    }
};

// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        else {
            ListNode* newHead = reverseList(head->next);
            ListNode* front = head->next;
            front->next = head;
            head->next = nullptr;
            return newHead;
        }
    }
};