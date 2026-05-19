/**
 * Day 003 - 2026-05-19
 * LeetCode #2540 - Minimum Common Value
 * Difficulty: Easy
 * Topic: Array, Hash Table, Two Pointers, Binary Search
 * Link: https://leetcode.com/problems/minimum-common-value/
 *
 * Problem:
 *   Given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 *   return the minimum integer common to both arrays. If there is no common
 *   integer, return -1.
 *
 * Approach:
 *   Iterate over the smaller array. For each element, use lower_bound on the
 *   remaining suffix of the larger array (tracked via prev pointer) to find a
 *   match. If found return immediately (arrays are sorted so first match = min).
 *   The prev pointer ensures we never scan already-passed elements, keeping the
 *   overall complexity optimal.
 *
 * Time Complexity:  O(n1 * log(n2))  where n1 <= n2
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) {
            swap(nums1, nums2);
            swap(n1, n2);
        }
        int prev = 0;
        for (int i = 0; i < n1; i++) {
            int x = nums1[i];
            int j = lower_bound(nums2.begin() + prev, nums2.end(), x) - nums2.begin();
            if (j == n2) return -1;
            else if (x == nums2[j]) return x;
            else // x < nums2[j]
                prev = j;
        }
        return -1;
    }
};
