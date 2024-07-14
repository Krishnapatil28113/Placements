/*
# Problem Statement: To find all the paths from the root to the lead nodes of a BT
---------------------------------------------------------------
# How to think: 
* One thing that comes into the mind is to traverse all the nodes untill we encounter a node whose left and right both are nullptr
* Then, we will get a valid path, so we can store it in a vector, while popping back the value from the temporary vector in which we were storing the values
* Because, we dont want that value for the next iteration
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    void fetchPaths(Node *root, vector<int> &vec, vector<vector<int>> &answer)
    {
        if (root == nullptr)
        {
            return;
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            vec.push_back(root->data);
            answer.push_back(vec);
            vec.pop_back();
            return;
        }

        vec.push_back(root->data);
        fetchPaths(root->left, vec, answer);
        fetchPaths(root->right, vec, answer);

        vec.pop_back();
        return;
    }

    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> answer;
        vector<int> vec;

        fetchPaths(root, vec, answer);
        return answer;
    }
};