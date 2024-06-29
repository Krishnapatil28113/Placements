/*
# Problem Statement: Job Sequencing Problem
---------------------------------------------------------------
# How to think: 
* If we consider jobs with higher deadlines, we should'nt assign them in the beginning, instead we should assign them as far as possible
* This is because, if the higher deadlines are assigned earlier, the jobs with lower deadlines may not get assigned, even if they have higher profit
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    bool static comparator(Job &j1, Job &j2) {
        if(j1.profit > j2.profit) {
            return true;
        }
        return false;
    }
    
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr, arr+n, comparator);
        int maxDead = INT_MIN;
        for(int i=0;i<n;i++) {
            if(arr[i].dead > maxDead) {
                maxDead = arr[i].dead;
            }
        }
        
        bool flag[maxDead+1] = {0};
        flag[0] = -1;
        
        int count = 0;
        int sum = 0;
        
        for(int i=0;i<n;i++) {
            if(flag[arr[i].dead] == 0) {
                flag[arr[i].dead] = -1;
                count++;
                sum += arr[i].profit;
            }
            else {
                int temp = arr[i].dead;
                while(flag[temp] != 0 && temp>=1) {
                    temp--;
                }
                
                if(temp < 1) {
                    continue;
                }
                else {
                    flag[temp] = -1;
                    count++;
                    sum += arr[i].profit;
                }
            }
        }
        
        return {count, sum};
    }
};