/*
# Question Link: https://leetcode.com/problems/linked-list-cycle/
# Problem Statement: To detect loop in linked list
# How to think:
# Time Complexity:
# Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> mySet;
        ListNode *temp = head;

        while (temp != nullptr)
        {
            if (mySet.find(temp) == mySet.end())
            {
                mySet.insert(temp);
                temp = temp->next;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};