/**
 * Day 012 - 2026-06-01
 * LeetCode #2144 - Minimum Cost of Buying Candies With Discount
 * Difficulty: Easy
 * Topic: Array, Greedy, Sorting
 * Link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
 *
 * Problem:
 *   A store offers: buy 2 candies, get the 3rd one (of equal or lesser price)
 *   for free. Given cost[], return the minimum total cost to buy all candies.
 *
 * Approach:
 *   Greedy + Sorting. Sort in descending order. Process groups of 3:
 *   pay for the 1st and 2nd, get the 3rd (cheapest of the three) free.
 *   This maximises the value of each free candy.
 *
 * Time Complexity:  O(n log n)
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int total = 0;

        for (int i = cost.size() - 1; i >= 0; i -= 3) {
            total += cost[i];
            if (i - 1 >= 0) total += cost[i - 1];
            // cost[i - 2] is free — skip it
        }

        return total;
    }
};
