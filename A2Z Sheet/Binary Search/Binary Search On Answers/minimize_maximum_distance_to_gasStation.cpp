/*
# Question Link: https://www.naukri.com/code360/problems/minimise-max-distance_7541449
# Problem Statement: To find the least possible maximum distance between 2 gas stations after placing 'k' gas stations in between already existing gas stations

# How to think:
1. Brute Force:
* If we have to minimize the maximum distance between any 2 gas stations, we will first find the maximum distance between
    any 2 consecutive pairs of positions
* After finding the maximum distance, if we have to place the gas stations in a most optimal way; we can do it
    by placing them at equal intervals
* We will start placing these gas stations one at a time between the gas stations having maximum distance; trying to minimize it

* Time Complexity: O(k*n + n) --> Quadratic
* Space Complexity: O(1)

2. Better Approach(Important Concept):
* In order to keep track of the maximum distance between any 2 consecutive gas stations, we can use PRIORITY QUEUE
* Priority queue places the element with the maximum distance, i.e, the max value on the top
* priority_queue<pair<long double, int>> pq;
* Every time we need the maximum distance, we can access the priority queue

* Time Complexity: O(klogn) --> Pushing and retreiving elements from the pritority queue is of the order O(logn)
* Space Complexity: O(n-1)

3. Optimal Approach: (Binary Search)
* Wherever we see minimize the maximum or anything related to minimum and maximum, we can think of using binary search
* Here, we cannot use generic binary search, because the intervals can range upto 10^-6 decimal points
* So, we will have to modify it --> while(high-low > 10^-6)
* Here, we will count the number of gas stations that can be fitted for the respective maximum distance!

# Time Complexity:
# Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

// Better Approach --> Priority Queue
double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.

    int n = arr.size();
    priority_queue<pair<long double, int>> pq;

    // Every value initialized to 0
    vector<int> howMany(n - 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto tp = pq.top();
        pq.pop();

        int secIndex = tp.second;
        howMany[secIndex]++;

        long double iniDiff = arr[secIndex + 1] - arr[secIndex];
        long double secLen = iniDiff / (long double)(howMany[secIndex] + 1);

        pq.push({secLen, secIndex});
    }

    return pq.top().first;
}

// Optimal Approach --> Binary Search
long double findMaxDifference(vector<int> &arr)
{
    int n = arr.size();
    int diff = -1;
    for (int i = 0; i < n; i++)
    {
        if (diff < (long double)arr[i + 1] - arr[i])
        {
            diff = (long double)arr[i + 1] - arr[i];
        }
    }

    return diff;
}

int noOfGasStations(vector<int> &arr, int dist)
{
    int n = arr.size();

    int cnt = 0;
    int numberInBetween;

    for (int i = 0; i < n - 1; i++)
    {
        numberInBetween = ((arr[i + 1] - arr[i]) / dist);
        if ((arr[i + 1] - arr[i]) / dist == numberInBetween * dist)
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.

    long double low = 0;
    long double high = findMaxDifference(arr);

    long double mid;

    long double diff = 1.0e-6;
    int count;

    while (high - low > diff)
    {
        mid = (low + high) / 2.0;

        count = noOfGasStations(arr, mid);

        if (count > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}