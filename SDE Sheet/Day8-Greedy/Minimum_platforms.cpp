/*
# Problem Statement: To count the minimum number of railway platforms required to host all the trains
---------------------------------------------------------------
# How to think: 
* The most basic way to approach the question is to observe the arrival and departure of the train as the time passes by
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int count = 0;
        int maxCount = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }

            maxCount = max(count, maxCount);
        }

        return maxCount;
    }
};

/* Approach using priority queue --> Time limit exceeded*/

/*
bool static comparator(Time t1, Time t2) {
    if(t1.arr < t2.arr) {
        return true;
    }
    else return false;
}

*/
// if(n == 1) {
//     return n;
// }
// else {
//     Time arr[n];
//     for(int i=0;i<n;i++) {
//         arr[i].arr = arrival[i];
//         arr[i].dep = departure[i];
//     }

//     sort(arr, arr+n, comparator);

//     priority_queue<int, vector<int>, greater<int>> pq;
//     int minCount = 1;
//     int count = 1;
//     pq.push(arr[0].dep);

//     for(int i=1;i<n;i++) {

//         if(arr[i].arr > pq.top()) {
//             minCount = max(count, minCount);

//             while(arr[i].arr > pq.top() || pq.empty() == false) {
//                 pq.pop();
//                 count--;
//             }

//             pq.push(arr[i].dep);
//             count++;
//         }
//         else {
//             count++;
//             pq.push(arr[i].dep);
//         }
//     }

//     minCount = max(count, minCount);

//     return minCount;
// }