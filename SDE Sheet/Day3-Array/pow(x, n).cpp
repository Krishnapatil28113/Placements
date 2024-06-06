/*
# Problem Statement: To find the nth power of x
---------------------------------------------------------------
# How to think:
1) Brute Force:
* Multiply x, n times

2) Optimal Approach:
* Analyse the time complexity of the brute force approach --> O(n)
* Now, if we have to reduce the time complexity, we will have to reduce it to O(logn)
* To reduce the complexity to O(logn), we can think of using binary search or dividing n by 2 multiple times
* Now, dividing the value of n by 2 makes more sense here, rather than using binary search
* For ex: 2^10
    --> We can split 2^10 in (2*2)^5; i.e, (4)^5
    --> Now, we will have to further reduce n and increase the value of x, but here n is odd
    --> So, we can write it as: 4 * (4)^4
    --> Now, we will store this extra '4' in the 'ans' variable as it is going to store the entire multiplication value
    --> And, if the n is even, the x will keep on getting bigger and bigger and n will keep on getting smaller and smaller
    --> And, whenever we encounter an odd n, we will convert it to even n, and store the extra value multiplied to the ans variable
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int nn) {
        double ans = 1.0;
        long long n = nn;

        if(n < 0) n = n*-1;
        while (n) {
            if (n % 2 == 0) {
                // even
                x = x * x;
                n = n / 2;
            } else {
                ans = ans * x;
                n = n - 1;
            }
        }

        if(nn < 0) {
            return (1/ans);
        }
        else {
            return ans;
        }
    }
};