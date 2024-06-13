/*
# Problem Statement: To find intersection point of 2 linked lists
---------------------------------------------------------------
# How to think:

1) Optimal Approach 1:
* First thing that comes into mind is to move the pointers simultaneously and find the intersection point
* But, the lists are of unequal lengths, therefore, it might not meet at the intersection point
* So, we will have to make the length of the lists same, by traversing the difference in the 2 linked lists

2) Optimal Approach 2:
* Previously, we solved a question, 'Remove Nth Node from the end'
* In that approach, we wanted to access the Nth node from the back, so we traversed fast pointer n times and then simultaneously traversed the slow pointer (len-n) times
* Similarly, here, we are not given with the position of the node, but we can use the 2 lists to find it

**Intuition:
--> We know, if we traverse the linked lists simultaneously, 1 of them will get empty first, provided they are of unequal lengths
--> And the other linked list will be yet to cover the 'difference' in the nodes of the 2 linked lists
--> And the difference is the one to be covered
--> So, why not put the pointer(null) of the first linked list to the second linked list(as it is greater in length)
--> As, it will travel the difference nodes(i.e, 2) until the second list's pointer reaches null

--> Hence, by these operations, we will eliminate the difference in the nodes
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
    ListNode* getIntersectionNode(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while (temp1 != temp2) {
            if (temp1 == nullptr && temp2 == nullptr) {
                return nullptr;
            } else if (temp1 == nullptr) {
                temp1 = l2;
            } else if (temp2 == nullptr) {
                temp2 = l1;
            } else {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }

        return temp1;
    }
};