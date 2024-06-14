/*
# Problem Statement: To find whether the given linked list is palindrome or not
---------------------------------------------------------------
# How to think: 

1) Optimal Approach:
* Firstly, after the brute force approach, we will have to reduce the time and space complexity
* So, if we do not have to use extra space like vector or stack, we will have to do it in-place
* So, to do it in-place, we can think of comparing the back of the linked list with the front, but it is a singly linked list
* Therefore, we can think of reversing the linked list and checking if it is the same
* Instead of reversing the whole linked list, we can just reverse half of the linked list and then compare the first half with the second half
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
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        else
        {
            ListNode *newHead = reverse(head->next);
            ListNode *front = head->next;
            front->next = head;
            head->next = nullptr;
            return newHead;
        }
    }
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow)
        {
            slow->next = reverse(slow->next);
            slow = slow->next;
        }

        ListNode *temp = head;
        while (slow != nullptr)
        {
            if (temp->val == slow->val)
            {
                slow = slow->next;
                temp = temp->next;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};