/*
# Problem Statement: To set the row and column values of an element which contains the value 0, to 0

# How to think:
----------------------------------------------------------------------
1) Brute Force:
* First thing that comes to our mind is to traverse the matrix and convert all the elements to zero
* But, here comes the problem;
    --> If we convert the rows and columns to 0, there will be occurence of unnecessary 0's which will again lead to unnecessary 0's
    --> So, to avoid that, we can convert the row values and column values of the 0 element to be -1(ONLY AND ONLY IF THE ELEMENTS IN THE MATRIX ARE BINARY)
    --> After completing this iteration, we can again iterate to change the occurences of -1 to 0
* Time complexity: ~O(n^3)
* Space complexity: O(1)

2) Better Approach:
* Another approach we can think of is to keep track of the occurences of 0's
* After documenting all the occurences, we can convert the respective elements to 0

* Time complexity: O(n^2) --> Not requiring to change the columns and rows for every element
* Space complexity: O(n + m) --> Two vectors, 1 for rows and 1 for columns

3) Optimal Approach: (Code remaining)
* We can think of reducing the space, because the time cannot be further reduced
* We are using 2 vector's space to store the occurences, so we can think of eliminating the need of utilizing these 2 vectors
* There comes the idea of utilizing the 1st row and 1st column of the matrix to be the column and row vector respectively

* Time Complexity: O(n^2)
* Space Complexity: O(1)
----------------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int rows[n];
        int cols[m];

        for(int i=0;i<n;i++) {
            rows[i] = 0;
        }
        for(int i=0;i<m;i++) {
            cols[i] = 0;
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(arr[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(rows[i] == 1 || cols[j] == 1) {
                    arr[i][j] = 0;
                }
            }
        }
    }
};