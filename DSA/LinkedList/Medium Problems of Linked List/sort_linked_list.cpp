/*
# Question Link: https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937
# Problem Statement: To sort Linked List by changing links
# How to think: 
* Firstly, we will think of the brute force approach and then after analyzing the time and space complexity,
    we will get to know what do we have to optimize and then how do we have to optimize

# Time Complexity: Better Approach -> O(2n), Optimal Approach -> O(n)
# Space Complexity: Better Approach -> O(1), Optimal Approach -> O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


// Brute Force Approach -> Linked List to Vector, Sort Vector, Regenerate Linked List
Node* sortList(Node *head){
    // Write your code here.
    vector<int> res;
    Node* temp = head;
    while(temp != nullptr) {
        res.push_back(temp->data);
        temp = temp->next;
    }

    sort(res.begin(),res.end());

    Node* newHead = new Node(res[0]);
    temp = newHead;
    int n = res.size();
    for(int i=1;i<n;i++) {
        temp->next = new Node(res[i]);
        temp = temp->next;
    }

    return newHead;
}

// Better Approach -> Count number of 0's, 1's and 2's, Change the values based on the counts in the original LL
Node* sortList(Node *head){
    // Write your code here.
    int cnt0=0;
    int cnt1=0;
    int cnt2=0;

    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == 0) {
            cnt0++;
        }
        else if(temp->data == 1) {
            cnt1++;
        }
        else {
            cnt2++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr) {
        if(cnt0) {
            temp->data = 0;
            cnt0--;
            temp = temp->next;
        }
        else if(cnt1) {
            temp->data = 1;
            cnt1--;
            temp = temp->next;
        }
        else {
            temp->data = 2;
            cnt2--;
            temp = temp->next;
        }
    }

    return head;
}

// Optimal Approach -> Traverse LL and link them based on the data in the original linked list
// *Note: This approach does not involve any creation of linked list; we are just assigning the links accordingly
Node* sortList(Node *head){
    // Write your code here.
    Node* head0 = new Node(-1);
    Node* head1 = new Node(-1);
    Node* head2 = new Node(-1);

    Node* temp0 = head0;
    Node* temp1 = head1;
    Node* temp2 = head2;

    Node* temp = head;
    while(temp != nullptr) {
        if(temp->data == 0) {
            temp0->next =temp;
            temp0 = temp0->next;
            temp = temp->next;
        }
        else if(temp->data == 1) {
            temp1->next =temp;
            temp1 = temp1->next;
            temp = temp->next;
        }
        else {
            temp2->next =temp;
            temp2 = temp2->next;
            temp = temp->next;
        }
    }

    temp0->next = head1->next;
    temp1->next = head2->next;
    temp2->next = nullptr;

    return head0->next;
}