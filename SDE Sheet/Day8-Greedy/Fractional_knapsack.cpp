/*
# Problem Statement: To maximize the value that the knapsack with a fixed weight can be filled with
---------------------------------------------------------------
# How to think: 
* We gotta maximize the value, therefore, it is an optimization problem, therefore, we can use the greedy method
* Now, there can be 2 concerning situations
    --> One item having greater profit, but at the same time have greater weight!
    --> One item having lesser profit, but at the same time the weight is less too!
* Therefore, we can consider items, by considering the higher value per weight of an item
---------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution {
  public:
    
    bool static comparator(Item item1, Item item2) {
        double r1 = (double)item1.value / (double)(item1.weight);
        double r2 = (double)(item2.value) / (double)(item2.weight);
        
        return r1 > r2;
    }
    
    double fractionalKnapsack(int w, Item item[], int n) {
        double totalValue = 0.0;
        
        sort(item, item+n, comparator);
        
        for(int i=0;i<n;i++) {
            if(item[i].weight <= w) {
                totalValue += item[i].value;
                w -= item[i].weight;
            }
            else {
                totalValue += (item[i].value/(double)item[i].weight) * (double)w;
                break;
            }
        }
        
        return totalValue;
        
    }
};