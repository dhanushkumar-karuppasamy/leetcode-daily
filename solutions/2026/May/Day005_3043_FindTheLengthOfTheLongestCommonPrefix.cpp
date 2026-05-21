/**
 * Day 005 - 2026-05-21
 * LeetCode #3043 - Find the Length of the Longest Common Prefix
 * Difficulty: Medium
 * Topic: Array, Hash Table, String, Trie
 * Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
 *
 * Problem:
 *   Given two integer arrays arr1 and arr2, return the length of the longest
 *   common prefix among all pairs (x, y) where x is in arr1 and y is in arr2,
 *   when their integer representations are treated as strings.
 *
 * Approach:
 *   1. For every number in arr1, store all its prefixes (obtained by repeatedly
 *      dividing by 10) in a hash map.
 *   2. For every number in arr2, check each of its prefixes against the map.
 *      If found, count the number of digits in that prefix and track the max.
 *   This avoids string conversion and works entirely with integer arithmetic.
 *
 * Time Complexity:  O((m + n) * log10(maxVal))
 * Space Complexity: O(m * log10(maxVal))  — prefix entries for arr1
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<long long, bool> Map;

        for (int i = 0; i < (int)arr1.size(); i++) {
            while (arr1[i]) {
                Map[arr1[i]] = true;
                arr1[i] /= 10;
            }
        }

        long long ans = 0;
        for (int i = 0; i < (int)arr2.size(); i++) {
            while (arr2[i]) {
                if (Map[arr2[i]]) {
                    long long num = arr2[i];
                    long long len = 0;
                    while (num) {
                        len++;
                        num /= 10;
                    }
                    ans = max(ans, len);
                }
                arr2[i] /= 10;
            }
        }
        return (int)ans;
    }
};
