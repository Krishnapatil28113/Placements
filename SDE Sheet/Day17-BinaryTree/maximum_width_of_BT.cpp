/*
# Problem Statement: To find the max width of BT
---------------------------------------------------------------
# How to think: 
* The first thing that comes to our mind is to do a level order traversal and store all the nodes in the queue
* After that, we can calculate the maximum width by figuring out the difference between the indexes in the first and last in a particular level
* But, there are null values too, which we can't insert in the queue, nor using some data structure like array
* So, we can't store, but we can certainly keep track of the indexes of occurences of these nodes in the BT
* We can do that by applying the concept:
    --> Every nodes left node's index is (2i+1) and right node's index is (2i+2)

* Note: To reduce the chances of overflow, we are always converting the value of 'i' for every node by subtracting it with the minimum value of the corresponding level
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int width = 1;
        TreeNode* curr = nullptr;
        int first;
        int last;

        int min;
        int currId;
        while (!q.empty()) {
            min = q.front().second;
            int size = q.size();

            for (int i = 1; i <= size; i++) {
                curr = q.front().first;

                currId = q.front().second - min;
                // currId = q.front().second;

                q.pop();

                if (i == 1) {
                    first = currId;
                }
                if (i == size) {
                    last = currId;
                }

                if (curr->left) {
                    q.push({curr->left, (long long)2 * currId + 1});
                }

                if (curr->right) {
                    q.push({curr->right, (long long)2 * currId + 2});
                }
            }

            width = max(width, last - first + 1);
        }

        return width;
    }
};