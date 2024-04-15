/*
# Question Link: https://leetcode.com/problems/rotate-list/
# Problem Statement: Rotate Linked List By K Nodes

# How to think:
* We have been given k, so we will have to find the kth node from the end first
* Now, we have to rotate k number of nodes from the kth node
* These k nodes are getting placed in the front, so make the newHead to the kth node and perform other required operations

# Time Complexity: O(n)
# Space Complexity: O(1)
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

// Optimal Solution
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *temp = head;
        int n = 1;
        while (temp->next != nullptr)
        {
            n++;
            temp = temp->next;
        }

        k = k % n;

        temp->next = head;

        int count = n - k;
        ListNode *end = head;
        for (int i = 0; i < count - 1; i++)
        {
            end = end->next;
        }

        head = end->next;
        end->next = nullptr;

        return head;
    }
};