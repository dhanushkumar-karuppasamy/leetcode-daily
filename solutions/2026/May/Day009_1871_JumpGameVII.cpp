/**
 * Day 009 - 2026-05-25
 * LeetCode #1871 - Jump Game VII
 * Difficulty: Medium
 * Topic: String, Dynamic Programming, Prefix Sum, Sliding Window
 * Link: https://leetcode.com/problems/jump-game-vii/
 *
 * Problem:
 *   Given a binary string s and integers minJump and maxJump, you start at
 *   index 0 (which is '0'). In one move you can jump from index i to any
 *   index j where i + minJump <= j <= i + maxJump and s[j] == '0'.
 *   Return true if you can reach the last index.
 *
 * Approach:
 *   Sliding window DP. dp[i] = true if index i is reachable.
 *   Maintain a counter `reachable` = number of true dp values inside the
 *   window [i - maxJump, i - minJump]. As i advances:
 *     - Add dp[i - minJump] entering the right edge of the window.
 *     - Remove dp[i - maxJump - 1] leaving the left edge.
 *   dp[i] is true iff s[i]=='0' and reachable > 0.
 *   This avoids an O(n * (maxJump - minJump)) inner loop.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        int reachable = 0;

        for (int i = 1; i < n; i++) {
            // new index entering the window on the right
            if (i - minJump >= 0 && dp[i - minJump])
                reachable++;

            // old index leaving the window on the left
            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1])
                reachable--;

            dp[i] = (reachable > 0 && s[i] == '0');
        }

        return dp[n - 1];
    }
};
