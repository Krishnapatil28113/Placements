/*
# Question Link: https://leetcode.com/problems/reverse-linked-list/
# Problem Statement: To reverse the given linked list

# How to think:
* Now, if we want to reverse the linked list in a recursive manner, firstly
    --> Try to break the problem into smaller sub-parts and try to solve these smaller sub-parts
    --> To solve these smaller sub-parts, we will need to perform some logic which will be performed for every recursive function call
    --> For example, here the reversal logic is:
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;

# Time Complexity: O(n)
# Space Complexity: O(n) --> Recursion Stack internal space
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};