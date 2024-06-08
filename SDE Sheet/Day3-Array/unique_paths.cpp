/*
# Problem Statement: To find all the unique paths that can be formed to reach the goal
---------------------------------------------------------------
# How to think: 
1) Recursion
* We can trace down all the possible moves the robot can take at any given stage
* Determine whether the robot can reach to the final state and increment the count

* Note: It takes a lot of time(TLE)

2) Memoization(DP)**
* While making recursive calls, we come across repetitive function calls, which have already been calculated
* So, once we get a result, we can store that result by using some suitable data structure
* And, every time, we are about to make a function call, we can check whether we already have the value or not

* Note: This eradicates the need of making unnecessary function calls and saves time

3) Optimal Approach(Combinatorics)**
* By some observation, we can figure out that the maximum number of moves(right OR down), can be (m+n-2)
* And, if we traverse any of the column completely(m-1) or if we traverse any of the row completely(n-1), in any possible way, we can generate a solution
* Therefore, we can calculate the combinatorics having 'N' as (m+n-2) and 'R' as (m-1) or (n-1)
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

// Recursion Using Memoization --> DP
class Solution {
public:
    int Count(int i, int j, int M, int N, vector<vector<int>>& dpMap) {
        int cnt = 0;
        if (i > M || j > N) {
            return 0;
        } else if (i == M && j == N) {
            return 1;
        } else {
            if (dpMap[i][j] == -1) {
                cnt += Count(i + 1, j, M, N, dpMap);

                cnt += Count(i, j + 1, M, N, dpMap);

                dpMap[i][j] = cnt;
                return cnt;
            } else {
                return dpMap[i][j];
            }
        }
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dpMap(m, vector<int>(n, -1));
        return Count(0, 0, m - 1, n - 1, dpMap);
    }
};

// Optimal Solution --> Combinatorics
class Solution {
public:

    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int R = n-1;

        double ans = 1;
        for(int j = 1 ; j <= R ; j++) {
            ans = ans * (N-R+j)/j;
        }

        return (int)ans;
    }
};