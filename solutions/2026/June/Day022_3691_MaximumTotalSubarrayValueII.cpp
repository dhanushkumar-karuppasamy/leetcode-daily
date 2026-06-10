/**
 * Day 022 - 2026-06-10
 * LeetCode #3691 - Maximum Total Subarray Value II
 * Difficulty: Hard
 * Topic: Array, Greedy, Heap (Priority Queue), Sparse Table
 * Link: https://leetcode.com/problems/maximum-total-subarray-value-ii/
 *
 * Problem:
 *   Given an integer array nums and an integer k, return the maximum sum of
 *   values obtained by selecting exactly k subarrays (with repetition allowed),
 *   where the value of a subarray [l, r] = max(nums[l..r]) - min(nums[l..r]).
 *
 * Approach:
 *   Sparse Table for O(1) range max/min queries.
 *   Max-heap (priority queue) seeded with [l, n-1] for every l.
 *   Greedily pick the top k intervals: after picking [l, r], push [l, r-1]
 *   (shrink from right). This ensures all candidates are explored in order.
 *
 * Time Complexity:  O((n + k) log n)
 * Space Complexity: O(n log n)  — sparse table
 */

#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    long long getValue(int l, int r) {
        int p = lg[r - l + 1];
        int mx = max(stMax[p][l], stMax[p][r - (1 << p) + 1]);
        int mn = min(stMin[p][l], stMin[p][r - (1 << p) + 1]);
        return 1LL * mx - mn;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        lg.resize(n + 1);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        int LOG = lg[n] + 1;
        stMax.assign(LOG, vector<int>(n));
        stMin.assign(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) { stMax[0][i] = nums[i]; stMin[0][i] = nums[i]; }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[j][i] = max(stMax[j-1][i], stMax[j-1][i + (1 << (j-1))]);
                stMin[j][i] = min(stMin[j-1][i], stMin[j-1][i + (1 << (j-1))]);
            }
        }

        using T = tuple<long long, int, int>;
        priority_queue<T> pq;
        for (int l = 0; l < n; l++) pq.push({getValue(l, n - 1), l, n - 1});

        long long ans = 0;
        while (k--) {
            auto [val, l, r] = pq.top(); pq.pop();
            ans += val;
            if (r > l) pq.push({getValue(l, r - 1), l, r - 1});
        }
        return ans;
    }
};
