/*
Question: https://www.codingninjas.com/studio/problems/selection-sort_624469

Problem Statement:
Implement Greedy Search Algorithm for:
1) Selection Sort
*/

/*
Explanation:

# Greedy Algorithm
--> The main concept of greedy algorithm is to solve the problem by choosing the best possible option available at the moment
--> It does not reverse its decision once its taken, even if it turns out to be wrong.
--> It does not always result in an optimal solution because it focuses on the local best solution to produce the global optimal solution

# Selection Sort
--> This sorting algorithm uses Greedy Approach to sort the array
--> Process:
    It proceeds by selecting the best possible option available at the time, i.e, it selects the first element of the array to be the minimum
    and compares it with all the remaining elements of the array.
    After each iteration, we get an element which is the minimum in the now available array(excluding the elements which are already sorted in previous iterations)
    After doing that for all the elements of the array, we get the sorted array.

--> Time Complexity: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

void swapNumbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n)
{
    int min_index;
    for (int i = 0; i < n; i++)
    {
        min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swapNumbers(&arr[i], &arr[min_index]);
        }
    }
}

void selectionSortRecursive(vector<int> &arr, int index)
{
    int n = arr.size();
    if (index == n - 1)
    {
        return;
    }
    int min_index = index;
    for (int j = index + 1; j < n; j++)
    {
        if (arr[j] < arr[min_index])
        {
            min_index = j;
        }
    }

    if (min_index != index)
    {
        swapNumbers(&arr[index], &arr[min_index]);
    }
    selectionSortRecursive(arr, index + 1);
}

int main()
{
    // int arr[5] = {5, 2, 9, 1, 7};
    // selectionSort(arr, 5);

    vector<int> arr = {5, 2, 9, 3, 7};

    selectionSortRecursive(arr, 0);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
