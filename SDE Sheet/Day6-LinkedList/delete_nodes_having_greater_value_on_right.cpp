/*
# Problem Statement: To delete the nodes which have greater value on the right
---------------------------------------------------------------
# How to think:
* One thing we can observe is:
    --> if we want to see whether the current element should be deleted or not, we will have to traverse all the other elements to find just a single element greater than the current element
    --> One thing that comes in our mind is, if we can find just 1 element and then based on that, we can decide whether to delete element or not
    --> We can do that if we traverse the linked list in a reverse manner
* Therefore, it suggests us to reverse the linked list
* After reversing, we can keep track of the current maximum;
    --> And if the current element is lesser than the current maximum, it will be deleted
    --> Else, if the current element is greater than or equal to the current maximum, it will be the new maximum
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Optimal Solution
class Solution
{
public:
    Node *reverseList(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        Node *newHead = reverseList(head->next);
        Node *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }

    Node *compute(Node *head)
    {
        Node *newHead = reverseList(head);

        if (newHead->next == nullptr)
        {
            return newHead;
        }
        else
        {
            int maxEle = newHead->data;
            Node *temp = newHead->next;
            Node *prev = newHead;
            while (temp != nullptr)
            {
                if (temp->data < maxEle)
                {
                    prev->next = temp->next;
                    temp = temp->next;
                }
                else
                {
                    maxEle = temp->data;
                    prev = temp;
                    temp = temp->next;
                }
            }

            return reverseList(newHead);
        }
    }
};