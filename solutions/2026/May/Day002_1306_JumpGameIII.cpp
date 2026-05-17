/**
 * Day 002 - 2026-05-17
 * LeetCode #1306 - Jump Game III
 * Difficulty: Medium
 * Topic: Breadth-First Search, Depth-First Search, Array
 * Link: https://leetcode.com/problems/jump-game-iii/
 *
 * Approach:
 *   Treat each index as a node in a graph. From index i, we can move to
 *   i + arr[i] or i - arr[i]. Use BFS with a visited array to avoid cycles.
 *   If we reach any index with value 0, return true.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i < 0 || i >= n || visited[i])
                continue;

            if (arr[i] == 0)
                return true;

            visited[i] = true;

            q.push(i + arr[i]);
            q.push(i - arr[i]);
        }

        return false;
    }
};
