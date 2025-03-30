//
// Created by Singh, Nitesh on 30/03/25.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
Best Time to Buy and Sell Stock -

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
-----------
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
-----------
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.


Constraints:
-------------
1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

int maxProfitBruteForce(vector<int>& prices)
{
    // initialize max profit to 0
    int max_profit = 0;

    // loop through prices array for buying
    for (int i = 0; i <prices.size(); i++)
    {
        // loop again through prices array for selling, as selling should be done only after buying(not on same day as profit would be 0)
        // j(selling day) = i(buying day) + 1
        for (int j = i+1; j <prices.size(); j++)
        {
            // Calculate profit if we buy on day i and sell on day j
            int profit = prices[j] - prices[i];

            // Update maximum profit if this profit is greater than the previous maximum
            max_profit = max(max_profit, profit);
        }
    }

    // Return the maximum profit found (or 0 if no profit is possible)
    return max_profit;
}

int maxProfitOptimal(vector<int>& prices)
{
    // initialize min stock price to track the cheapest/min stock price, can assume it to be 1st element of the prices array
    int min_price = prices[0];

    // initialize max_profit to track max profit
    int max_profit = 0;

    // get max profit

    // loop through the prices array, to check for min price and max profit
    for (int i = 0; i < prices.size(); i++)
    {
        min_price = min(min_price, prices[i]);
        int profit = prices[i] - min_price;
        max_profit = max(max_profit, profit);
    }
    return max_profit;
}

int main()
{
    // initialize prices array
    vector<int>& prices = {7, 1, 5, 3, 6, 4};

    // call max profit brute force
    int resultBrute = maxProfitBruteForce(prices);

    // print max profit brute
    cout << "Max brute profit is : " << resultBrute << endl;

    // call max profit optimal
    int resultOptimal = maxProfitOptimal(prices);

    // print max profit optimal
    cout << "Max optimal profit is : " << resultOptimal << endl;

    return 0;
}