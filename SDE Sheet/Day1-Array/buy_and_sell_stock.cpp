/*
# Problem Statement: To find the maximum profit that can be achieved by buying and selling stocks
---------------------------------------------------------------
# How to think:
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &arr)
    {
        int n = arr.size();
        int maxProfit = 0;

        int minimum = arr[0];
        int cost = 0;
        for (int i = 1; i < n; i++)
        {
            cost = arr[i] - minimum;
            maxProfit = max(maxProfit, cost);

            minimum = min(minimum, arr[i]);
        }

        return maxProfit;
    }
};