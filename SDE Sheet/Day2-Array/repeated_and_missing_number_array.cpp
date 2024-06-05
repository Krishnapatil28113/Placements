/*
# Problem Statement: To find repeated number and missing number in the array
---------------------------------------------------------------
# How to think:
1) Optimal Approach --> Basic Maths(V.Imp)
* We should divide the problem into 2 sub problems
    --> Finding missing number
    --> Finding repeating number
* So, to find the repeating number, we should think of some method
* The first optimal method that comes to our mind is to sum up all the elements of the array and compare them with the sum of the first n elements
* That might have given us the repeating number, but in this case, there is a missing number too; so we will be needing another equation to solve this problem
* Therefore, we should think of making 2 equations for 2 variables, i.e, 'Repeating' number and 'Missing' number

2) Optimal Approach --> XOR(V.V.Imp)**
* link --> https://www.youtube.com/watch?v=2D0D8HE6uak
* Watch the XOR implementation part(V.Imp)
---------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Better Approach --> O(2n), O(n)
vector<int> repeatedNumber(const vector<int> &nums)
{
    vector<int> result;

    int n = nums.size();
    int hash[n + 1];
    for (int i = 0; i <= n; i++)
    {
        hash[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
        {
            result.insert(result.begin(), i);
        }
        else if (hash[i] == 0)
        {
            result.push_back(i);
        }
    }

    return result;
}

// Optimal Approach 1 --> Basic Maths
vector<int> repeatedNumber(const vector<int> &nums)
{

    int n = nums.size();

    long long S = 0;
    for (int i = 0; i < n; i++)
    {
        S = S + nums[i];
    }

    long long Sn = (n * (n + 1)) * 0.5;

    long long Ssn = (n * (n + 1) * (2 * n + 1)) / 6;

    long long Ss = 0;
    for (int i = 0; i < n; i++)
    {
        Ss = Ss + (long long)nums[i] * (long long)nums[i];
    }

    int val1 = Sn - S;
    int val2 = Ssn - Ss;
    val2 = val2 / val1;

    long long x = 0;
    long long y = 0;
    y = (val1 + val2) / 2;
    x = y - val1;

    return {(int)x, (int)y};
}

// Optimal Approach --> XOR
vector<int> repeatedNumber(const vector<int> &arr)
{
    int n = arr.size();
    // calculating the xor
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }

    // xr = 100
    //  finding the differentiating bit --> i.e, 2nd bit(1)
    int bitNo = 0;
    while (1)
    {
        if ((xr & (1 << bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }

    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (1 << bitNo)) != 0)
        {
            one = one ^ arr[i];
        }
        else
        {
            zero = zero ^ arr[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << bitNo)) != 0)
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == one)
        {
            cnt++;
        }
    }

    if (cnt == 2)
    {
        return {one, zero};
    }
    else
    {
        return {zero, one};
    }
}
