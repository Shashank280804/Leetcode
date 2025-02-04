/*
Step 1: Initialize profit = 0.
Step 2: Iterate from i = 1 to prices.size() - 1.
Step 3: If prices[i] > prices[i-1], add prices[i] - prices[i-1] to profit.
Step 4: Repeat until the end of the array.
Step 5: Return profit.

*/

#include <bits/stdc++.h>  // Include all standard C++ libraries
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;  // Initialize total profit to 0

        for (int i = 1; i < prices.size(); i++) {  // Loop through the array starting from index 1
            if (prices[i] > prices[i - 1]) {  // If the current price is greater than the previous day's price
                profit += (prices[i] - prices[i - 1]);  // Add the profit from this transaction
            }
        }

        return profit;  // Return the total profit
    }
};
