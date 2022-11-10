/*
 * RJOrdway
 * 1st Solution, LeetCode 121: Best Time to Buy and Sell Stock
 * 
 * Method:  Memory optimized, few additional data structures used
 * 
 * Concern: Runtime takes a hit
 * 
 * Started:     9/5/22
 * Submitted:   9/5/22
 */
#include <iostream>
#include <vector>
#include <algorithm> // for max()

using namespace std;

int maxProfit(vector<int>& prices) {
        int low = prices[0];
        int high = prices[0];
        int mp = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < low) {
                low = prices[i];
                high = low;
            }
            else {
                if (prices[i] > high) {
                    high = prices[i];
                    mp = (mp < high-low)*(high-low)+(mp >= high-low)*mp;
                }
            }
        }
        return mp;
}