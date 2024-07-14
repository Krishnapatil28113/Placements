/*
# Problem Statement: To find inorder, preorder, postorder in a single traversal
---------------------------------------------------------------
# How to think: 
* Need to know the algorithm
* link -> https://www.youtube.com/watch?v=ySp2epYvgTE
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    vector<vector<int>> answer;

    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            // preorder
            preorder.push_back(st.top().first->data);
            st.top().second++;

            if (st.top().first->left)
            {
                st.push({st.top().first->left, 1});
            }
        }
        else if (st.top().second == 2)
        {
            // inorder
            inorder.push_back(st.top().first->data);
            st.top().second++;

            if (st.top().first->right)
            {
                st.push({st.top().first->right, 1});
            }
        }
        else
        {
            // postorder
            postorder.push_back(st.top().first->data);
            st.pop();
        }
    }

    answer.push_back(inorder);
    answer.push_back(preorder);
    answer.push_back(postorder);

    return answer;
}