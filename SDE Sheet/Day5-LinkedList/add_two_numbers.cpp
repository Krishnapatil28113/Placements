/*
# Problem Statement: To add 2 numbers represented by linked list
---------------------------------------------------------------
# How to think: 
* Observe the addition taking place, the number getting generated and try to deduce a pattern
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        int carry = 0;
        int output = 0;
        long long sum = 0;

        while(l1 != nullptr && l2 != nullptr) {
            sum = (l1->val + l2->val + carry);
            carry = sum / 10;
            output = sum % 10;

            temp->next = new ListNode(output);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr) {
            sum = (l1->val + carry);

            carry = sum / 10;
            output = sum % 10;

            temp->next = new ListNode(output);
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2 != nullptr) {
            sum = (l2->val + carry);

            carry = sum / 10;
            output = sum % 10;

            temp->next = new ListNode(output);
            temp = temp->next;
            l2 = l2->next;
        }

        if(carry) {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }

        return head->next;
    }
};