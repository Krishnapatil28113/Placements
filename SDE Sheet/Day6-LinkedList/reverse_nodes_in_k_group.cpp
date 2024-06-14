/*
# Problem Statement: To reverse nodes in k group
---------------------------------------------------------------
# How to think: 
* If we have to reverse a linked list, we can simply pass the starting point of that linked list to the reverse function
* But here, we have groups of linked lists to reverse, so we will have to break the linked list and then perform the reverse operation
* And then again link that reversed part of the linked list to the original linked list
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
    ListNode* findKthNode(ListNode* temp, int k) {
        k--;
        while (k) {
            k--;
            if (temp) {
                temp = temp->next;
            } else {
                break;
            }
        }

        return temp;
    }

    ListNode* reverse(ListNode* start, ListNode* end) {
        if (start == end) {
            return start;
        } else {
            ListNode* newHead = reverse(start->next, end);
            ListNode* front = start->next;
            front->next = start;
            start->next = nullptr;
            return newHead;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head->next == nullptr) {
            return head;
        }

        ListNode* aheadNode = head;
        ListNode* temp = aheadNode;
        ListNode* prevNode = temp;

        ListNode* curr = temp;

        while (curr != nullptr) {
            curr = findKthNode(temp, k);

            if (curr == nullptr) {
                break;
            }
            aheadNode = curr->next;
            curr->next = nullptr;

            curr = reverse(temp, curr);

            if (temp == head) {
                head = curr;
                prevNode = temp;
                temp = aheadNode;
            } else {
                prevNode->next = curr;
                prevNode = temp;
                temp = aheadNode;
            }
        }

        prevNode->next = aheadNode;

        return head;
    }
};