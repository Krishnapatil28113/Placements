/*
# Problem Statement: To count the maximum number of meetings that can be held in a meeting room
---------------------------------------------------------------
# How to think:
* The question demands to count the maximum number of meetings
* Therefore, it is an optimization problem, hence, we can apply greedy method or dynamic programming here
* Thinking greedily, we can think of the meetings which end early, hence, giving other meetings the opportunity to get executed
* In this way, the occurences of meetings can be maximised
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

class meeting{
    public:
    int start;
    int end;
};

class Solution
{
    public:
    
    bool static comp(meeting m1, meeting m2) {
        if(m1.end < m2.end) {
            return true;
        }
        return false;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        meeting arr[n];
        
        for(int i=0;i<n;i++) {
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        
        sort(arr, arr+n, comp);
        
        int count = 1;
        int endTime = arr[0].end;
        
        for(int i=1;i<n;i++) {
            if(arr[i].start > endTime) {
                count++;
                endTime = arr[i].end;
            }
        }
        
        return count;
    }
};