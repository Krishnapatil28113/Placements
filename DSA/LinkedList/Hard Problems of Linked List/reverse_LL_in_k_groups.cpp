/*
# Question Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
# Problem Statement: To reverse linked list in groups of k

# How to think:
* First thing we can think of is:
    --> To start with the linked list and then find the kth node and then reverse it
    --> But, we can't reverse some part of a linked list, so we will have to break the linked list at the kth node
    --> But, if we break the linked list, we won't be able to join the linked list after reversing
    --> So, we will have to store the nextNode of the linked list before breaking the link for reversal
    --> Can proceed to think in this direction

# Time Complexity: O(N) + O(N) --> Reversing entire linked list + Finding kth Node
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
class Solution
{
public:
    ListNode *getkthNode(ListNode *head, int k)
    {
        k--;
        while (k)
        {
            k--;
            if (head)
            {
                head = head->next;
            }
            else
            {
                return head;
            }
        }

        return head;
    }

    ListNode *reverseLinkedList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *newHead = reverseLinkedList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        else
        {
            ListNode *kthNode;
            ListNode *nextNode;
            ListNode *prevNode;
            ListNode *newHead;

            ListNode *temp = head;

            while (temp != nullptr)
            {
                kthNode = getkthNode(temp, k);
                if (kthNode)
                {
                    nextNode = kthNode->next;
                    kthNode->next = nullptr;
                }
                else
                {
                    prevNode->next = temp;
                    break;
                }

                newHead = reverseLinkedList(temp);

                if (temp == head)
                {
                    head = newHead;
                    prevNode = temp;
                    temp = nextNode;
                }
                else
                {
                    prevNode->next = newHead;
                    prevNode = temp;
                    temp = nextNode;
                }
            }

            return head;
        }
        return head;
    }
};