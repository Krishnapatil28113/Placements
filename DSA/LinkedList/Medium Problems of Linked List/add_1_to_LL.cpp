/*
# Question Link:
# Problem Statement:
# How to think:
# Time Complexity:
# Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *addOne(Node *head)
{
    if (head == nullptr)
    {
        return head;
    }
    // Write Your Code Here.
    Node *temp = head;
    stack<int> s1;
    stack<int> s2;

    while (temp->next != nullptr)
    {
        s1.push(temp->data);
        temp = temp->next;
    }

    s1.push(temp->data);

    int carry = 0;
    int actualElement;

    int element = s1.top();
    s1.pop();

    int result = element + 1;
    if (result < 10)
    {
        temp->data = result;
        return head;
    }
    else
    {
        carry = result / 10;
        actualElement = result % 10;
        s2.push(actualElement);

        while (!s1.empty())
        {
            element = s1.top();
            s1.pop();
            result = element + carry;
            carry = result / 10;
            actualElement = result % 10;
            s2.push(actualElement);
        }

        if (carry)
        {
            s2.push(carry);
        }

        temp = head;
        while (!s2.empty() && temp->next != nullptr)
        {
            temp->data = s2.top();
            s2.pop();
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            temp->data = s2.top();
            s2.pop();

            while (!s2.empty())
            {
                temp->next = new Node(s2.top());
                s2.pop();
                temp = temp->next;
            }
        }

        return head;
    }
}
