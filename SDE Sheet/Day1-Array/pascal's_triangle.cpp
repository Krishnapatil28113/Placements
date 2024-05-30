/*
# Problem Statement: To print pascal's traingle
---------------------------------------------------------------
# How to think:
1) Brute Force:
* Try to identify the pattern getting generated
* After identifying the pattern, try to figure out the formulae being used to calculate the entries of the pattern
* After figuring out the formulae, calculate every element by using that formulae and print it

2) Optimal Approach:
* For every iteration, i.e, for each row of the pascal's triangle, try to observe the pattern getting generated
* After observing the pattern, we see that, the subsequent values are getting multiplied by a consistent manner
* i.e; multiplied by (i-j)/j;
* So, we dont need to apply the formulae for calculating each entry and increase the time complexity
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calc(int n, int r) {
        int resultVal = 1;

        for (int i = 1; i < r; i++) {
            resultVal = resultVal * (n - i);
            resultVal = resultVal / i;
        }

        return resultVal;
    }
    
    vector<vector<int>> generate(int n) {
        vector<vector<int>> answer;
        vector<int> result;
        int val;
        for (int i = 0; i < n; i++) {            

            val = 1;
            result.push_back(val);
            for (int j = 1; j <= i; j++) {
                val = val * (i - j+1) / j;
                result.push_back(val);
            }

            answer.push_back(result);
            result.clear();
        }
        return answer;
    }
};