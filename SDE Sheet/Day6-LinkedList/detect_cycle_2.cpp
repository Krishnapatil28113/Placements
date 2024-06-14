/*
# Problem Statement: To find the starting point of the loop in a linked list
---------------------------------------------------------------
# How to think: 
* Extension of Tortoise and Hare Algorithm
    --> After finding the intersection point of slow and fast, set the fast pointer to the head
    --> Move slow and fast simultaneously by 1 step until they reach a common point
    --> That common point is the intersection

---------------------------------------------------------------
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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        else
        {
            ListNode *slow = head;
            ListNode *fast = head;

            do
            {
                slow = slow->next;
                if (fast != nullptr && fast->next != nullptr)
                {
                    fast = fast->next->next;
                }
                else
                {
                    return nullptr;
                }
            } while (slow != fast);

            fast = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }
};