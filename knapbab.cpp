//Author: Mihir Patel
//NOTE: Current Program Version does not take more than 50 items. Programmer must change value in code for future use. 
//      The default memory allocation can be turned into Dynamic array OR use vectors for better functionality of the program. 
//      This version just gives you the Max profit of the stored items.


#include <iostream>
#include <algorithm>
#include <queue>

using namespace std; 

int nodeCtr; 

struct Item
{
    int weight;
    int value;
}arr[50];

struct Node
{
    int level;
    int profit;
    int weight;
    int bound;

};

// for sorting the item using ratio
bool compareIt(Item a, Item b)
{
    int val1 =  a.value / a.weight;
    int val2 =  b.value / b.weight;

    return val1 > val2;
}

int bound(Node u, int n, int maxWeight, Item arr[])
{
    if(u.weight >= maxWeight)
        return 0;

    // bound is current profit.
    // J is next level item index
    int newBound = u.profit;
    int j = u.level +1;
    int totalWeight = u.weight;

    // Check weight capacity in the sack
    while((j < n) && (totalWeight + arr[j].weight <= maxWeight))
    {
        totalWeight += arr[j].weight;
        newBound += arr[j].value;
        j++;
    }

    if (j < n)
    {
        newBound += (maxWeight - totalWeight) * (arr[j].value / arr[j].weight);
    }
    
    return newBound;
}


int knapsack(int W, Item arr[], int n)
{
    int maxProfit = 0;
    
    sort(arr, arr +n , compareIt);
    queue<Node> Q;
    Node u,v;

    v.level = -1;
    v.profit = v.weight = 0;
    Q.push(v);

    while(!Q.empty()) 
    {
        nodeCtr++;
        v = Q.front();
        Q.pop();

        if(v.level == -1)
        {
            u.level = 0;
        }

        if(v.level == n-1)
        {
            continue;
        }

        u.level = v.level +1;
        u.weight = v.weight + arr[u.level].weight;
        u.profit = v.profit + arr[u.level].value; 

        if(u.weight <= W && u.profit > maxProfit)
        {
            // cout << "\nValue is " <<arr[u.level].value;
            // cout << "\nWeight is " <<arr[u.level].weight << endl;
            
            // cout << "\nWeight total is " << u.weight << endl;
            maxProfit = u.profit;
            
        }

        u.bound = bound(u, n, W, arr);

        if(u.bound > maxProfit)
        {
            Q.push(u);
        }

        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = bound(u, n, W, arr);

        if(u.bound > maxProfit)
        {
            Q.push(u);
        }

    }

    return maxProfit;

}

// Knapsack using Branch and bound
int main() 
{ 
    int maxWeight; 
    int numOfItem;

    cout << "What is the Max Weight of the Sack: ";
    cin >> maxWeight;
    
    cout << "How many number of items do you want to store: ";
    cin >> numOfItem;

    for(int j =0; j < numOfItem; j++)
    {
            cout << "Enter the Weight of the item: ";
            cin >> arr[j].weight;
    
            cout << "Enter the Value of the item: ";
            cin >> arr[j].value;
     
    }
    
    // for (int i =0; i < numOfItem; i++)
    // {
    //     cout << "\nValue = " << arr[i].value << "\tWeight = " << arr[i].weight;
    // }
    
    int maxProfitReturn = knapsack(maxWeight, arr, numOfItem); 
    
    cout << "\nMax Profit achieved is " << maxProfitReturn << endl;
    
    cout << "\nMax nodes achieved is " << nodeCtr << endl;

    return 0; 
} 
