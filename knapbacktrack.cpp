//Author: Mihir Patel
//NOTE: Current Program Version does not take more than 50 items. Programmer must change value in code for future use. 
//      The default memory allocation can be turned into Dynamic array OR use vectors for better functionality of the program. 
//      This version just gives you the Max profit of the stored items. 


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxProfit = 0;
int numOfItem = 0;
int maxWeight = 0;
int numBest = 0;
int nodeCounter= 1;
int include[50];
int bestSet[50];



// Each item has a profit & weight and will be stored within vectors
struct Item
{
    int profit;
    int weight;
    
} arr[50]; // Created the array at start just for now. can be replaced by dynamic array OR Vectors. 


// Sorting from Max to Min. 
bool compareIt(Item a, Item b)
{
    int val1 =  a.profit / a.weight;
    int val2 =  b.profit / b.weight;

    return val1 > val2;
}

// Finding the next promising node in tree for knapsack.
bool promising(int i, int profit, int weight)
{
    int j, k;
    int totalWeight;
    double bound;

    if (weight >= maxWeight)
    {
        return false;
    }
    else
    {
        j = i+1;
        bound = profit;
        totalWeight = weight;

        while(j <= numOfItem && ((totalWeight + arr[j].weight) <= maxWeight) )
        {
            totalWeight = totalWeight + arr[j].weight;
            bound = bound + arr[j].profit;
            j++;
        }
        k =j;

        if(k <= numOfItem)
        {
            bound = bound + (maxWeight - totalWeight) * (arr[j].profit / arr[j].weight);
        }
    }
    
    return bound > maxProfit;
}


// Knapsack algorithm.
void knapsack(int i, int profit, int weight)
{   
   
        nodeCounter++; 
        if(weight <= maxWeight && profit >= maxProfit)
        {
            maxProfit = profit;
            numBest = i; // what is this numBest supposed to be for? 
            copy(begin(include), end(include), begin(bestSet));
        }
      
        if(promising(i, profit, weight))
        {
        
            include[i + 1] = 1;
            knapsack(i+1, profit + arr[i+1].profit ,  weight + arr[i+1].weight );
            include[i + 1] = 0;
            knapsack(i+1, profit, weight);
            
        }
    
    
}


int main() 
{ 

    cout << "What is the Max Weight of the Sack: ";
    cin >> maxWeight;
    
    cout << "How many number of items do you want to store: ";
    cin >> numOfItem;

    for(int j =0; j < numOfItem; j++)
    {
            cout << "Enter the Weight of the item: ";
            cin >> arr[j].weight;
    
            cout << "Enter the Value of the item: ";
            cin >> arr[j].profit;
     
    }
    
    sort(arr, arr + numOfItem , compareIt);
    
        knapsack(0, arr[0].profit, arr[0].weight); 
    
    cout << "\nMax Profit achieved is " << maxProfit;
    
   
    cout << endl;
    cout << "Nodes counted " << nodeCounter;
    return 0; 

} 
