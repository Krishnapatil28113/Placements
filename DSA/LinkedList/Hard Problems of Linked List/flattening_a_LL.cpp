/*
# Question Link: https://www.naukri.com/code360/problems/flatten-a-linked-list_1112655
# Problem Statement: Flatten a given Linked List

# How to think:
* Firstly, we should think about solving a smaller part of the problem, like, flattening a smaller part of the linked list, in this case
* After we have figured out how to flatten a smaller part of a linked list, then we should think about applying that logic
    to the rest of the linked list
* For example, here what we did was merged 2 portions of a linked list in a sorted order and converted them into one
* After that, we performed the same operation considering this merged linked list to be 1 portion of the 2, recursively

# Time Complexity: O(n) * O(2*m) --> O(n*m)
# Space Complexity: O(n) --> Recursion stack space
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node *mergeLinkedList(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }

    if (list1)
    {
        res->child = list1;
    }
    else
    {
        res->child = list2;
    }

    return dummyNode->child;
}

Node *flattenLinkedList(Node *head)
{
    // Write your code here
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *newHead = flattenLinkedList(head->next);
    head = mergeLinkedList(head, newHead);
    return head;
}