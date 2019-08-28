// Author Mihir Patel 

import java.util.*;

class Knapbrute 
{ 
	// Counts how many nodes will be used for the tree.
	public static int nodeCtr = 0;

	// Used for sorting from max to min
	static int max(int a, int b) { 
		return (a > b)? a : b; 
	} 
	
	
	// Knapsack algorithm from bottom up 
	static int knapSack(int W, int wt[], int val[], int n) 
	{ 
		int i, w; 
		int sack[][] = new int[n+1][W+1]; 
	
	for (i = 0; i <= n; i++) 
	{ 
		for (w = 0; w <= W; w++) 
		{ 
			if (i==0 || w==0) 
				sack[i][w] = 0; 
			else if (wt[i-1] <= w) 
				sack[i][w] = max(val[i-1] + sack[i-1][w-wt[i-1]], sack[i-1][w]); 
			else
				sack[i][w] = sack[i-1][w]; 

			nodeCtr++;
		} 
	} 
	
	return sack[n][W]; 
	} 

	// Main asks user to input the desired ammount of data.
	// Program prints out Max profit achived and max nodes being used. 
	public static void main(String args[]) 
	{ 
        int maxWeight; 
        int numOfItem;
        Scanner in = new Scanner(System.in);

        System.out.print("What is the Max Weight of the Sack: ");
        maxWeight = in.nextInt();

        System.out.print("How many number of items do you want to store: ");
        numOfItem = in.nextInt();
        

        int val[] = new int[numOfItem]; 
        int wt[] = new int[numOfItem];
        
        for (int i =0; i < numOfItem ; i++){
            System.out.print("Enter Value of the item: ");
            val[i] = in.nextInt();
            System.out.print("Enter Weight of the item: ");
            wt[i] = in.nextInt(); 

        }
        in.close();
		System.out.println("Max profit is " + knapSack(maxWeight, wt, val, numOfItem)); 
		
		System.out.println("Max nodes " + nodeCtr);
	} 
} 
