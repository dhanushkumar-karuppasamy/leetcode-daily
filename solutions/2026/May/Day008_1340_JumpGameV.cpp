/**
 * Day 008 - 2026-05-24
 * LeetCode #1340 - Jump Game V
 * Difficulty: Hard
 * Topic: Array, Dynamic Programming, Memoization
 * Link: https://leetcode.com/problems/jump-game-v/
 *
 * Problem:
 *   Given an integer array arr and an integer d, you can jump from index i to
 *   index j if |i - j| <= d AND arr[j] < arr[i] AND all elements between i
 *   and j are also strictly less than arr[i]. Return the maximum number of
 *   indices you can visit starting from any index.
 *
 * Approach:
 *   DFS with memoization (top-down DP). From each index i, try jumping right
 *   and left up to d steps, stopping as soon as a taller-or-equal element
 *   blocks the path (since we can't jump over it). Cache results in dp[] to
 *   avoid recomputation. Final answer is the max over all starting indices.
 *
 * Time Complexity:  O(n * d)
 * Space Complexity: O(n)  — dp array + recursion stack
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];

        int best = 1;
        int n = arr.size();

        for (int nxt = i + 1; nxt <= min(n - 1, i + d); nxt++) {
            if (arr[nxt] >= arr[i]) break;
            best = max(best, 1 + dfs(nxt, arr, d, dp));
        }

        for (int nxt = i - 1; nxt >= max(0, i - d); nxt--) {
            if (arr[nxt] >= arr[i]) break;
            best = max(best, 1 + dfs(nxt, arr, d, dp));
        }

        return dp[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d, dp));
        }

        return ans;
    }
};
