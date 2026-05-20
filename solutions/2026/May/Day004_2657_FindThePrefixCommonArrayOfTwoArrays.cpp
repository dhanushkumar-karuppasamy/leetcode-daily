/**
 * Day 004 - 2026-05-20
 * LeetCode #2657 - Find the Prefix Common Array of Two Arrays
 * Difficulty: Medium
 * Topic: Array, Hash Table, Bit Manipulation
 * Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 *
 * Problem:
 *   Given two 0-indexed integer permutations A and B of [1, n], the prefix
 *   common array C is defined as C[i] = count of integers that are present
 *   in both the prefix A[0..i] and B[0..i].
 *   Return the prefix common array C.
 *
 * Approach:
 *   Use a frequency array of size n+1. For each index i, increment freq for
 *   A[i] and B[i]. If any element's frequency reaches 2, it means that element
 *   has appeared in both prefixes up to i — increment count. ans[i] = count.
 *   This avoids using a set and runs in a single O(n) pass.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(n)
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans(n);
        int count = 0;

        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            if (freq[A[i]] == 2) count++;

            freq[B[i]]++;
            if (freq[B[i]] == 2) count++;

            ans[i] = count;
        }
        return ans;
    }
};
