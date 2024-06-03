/*
# Problem Statement: To merge overlapping intervals
---------------------------------------------------------------
# How to think:
* First of all, we should plot all the points of the intervals on a paper looking for overlapping intervals
* Once we plot it, we can clearly merge the overlapping intervals by observing
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{

    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return arr;
        }
        else
        {

            sort(arr.begin(), arr.end(), compare);
            vector<vector<int>> result;
            vector<int> key = arr[0];
            for (int i = 1; i < n; i++)
            {
                if (arr[i][0] <= key[1])
                {

                    if (arr[i][1] > key[1])
                    {
                        key = {key[0], arr[i][1]};
                    }
                }
                else
                {
                    result.push_back(key);
                    key = arr[i];
                }
            }

            result.push_back(key);

            return result;
        }
    }
};