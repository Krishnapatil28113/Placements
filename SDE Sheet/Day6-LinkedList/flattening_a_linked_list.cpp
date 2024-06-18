/*
# Problem Statement: To flatten a linked list
---------------------------------------------------------------
# How to think:
* We can sort the linked list manually and then compare the sorted linked list and the original linked list
* Based on this observation, we will be able to figure out that, we have to sort this using the bottom pointer

* Now, if we have to sort the whole linked list, we won't be able to sort the linked list in one go
* We will have to find a way to sort a sub part of the problem, i.e, 2 linked list; and then we can apply this logic to other linked lists as well

* Time Complexity: O(All elements)
* Space Complexity: O(1)
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *curr, Node *ahead)
{
    Node *res = new Node(0);
    Node *temp = res;

    while (curr != nullptr && ahead != nullptr)
    {
        if (curr->data <= ahead->data)
        {
            temp->bottom = curr;
            temp = temp->bottom;
            curr = curr->bottom;
        }
        else
        {
            temp->bottom = ahead;
            temp = temp->bottom;
            ahead = ahead->bottom;
        }
    }

    if (curr != nullptr)
    {
        temp->bottom = curr;
    }
    else
    {
        temp->bottom = ahead;
    }

    res->bottom->next = nullptr;
    return res->bottom;
}

Node *flatten(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    else
    {
        Node *toBeMerged = flatten(head->next);
        Node *afterMerge = merge(head, toBeMerged);
        return afterMerge;
    }
}