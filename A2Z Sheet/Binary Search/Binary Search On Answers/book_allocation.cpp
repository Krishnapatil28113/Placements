/*
# Question Link: https://www.naukri.com/code360/problems/allocate-books_1090540
# Problem Statement: To find the minimum of the maximum books allocated to a particular student

# How to think:
1. Brute Force:
* We will have to go through all the cases by checking each and every element from 1 to the element which we will get as the answer
* What we will have to check?
    --> Whether we can distribute the now considered number of books in such a way that the number of students it is getting assigned to is m itself


2. Optimal Approach:
* As the problem states to find out the minimum of the maximum, the most optimal approach we can think of is binary search
* As, we have to find the element and we can figure out a range in which that element may lie, our work is done
* low -> max_element(arr) , high -> sum(arr)
* For every mid element, i.e, the number of pages; we will check whether we can assign these many pages to a student so that it satisfies all the conditions mentioned in the question or not
* And accordingly, we will move the left and right pointers!

# Time Complexity: O(nlogn)
# Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int canWeAssign(vector<int> &arr, int pages)
{
    int n = arr.size();

    long long pagesCount = 0;
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        if (pagesCount + arr[i] <= pages)
        {
            pagesCount += arr[i];
        }
        else
        {
            pagesCount = arr[i];
            count++;
        }
    }
    return count;
}

int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.

    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        int count = canWeAssign(arr, mid);
        if (count > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}