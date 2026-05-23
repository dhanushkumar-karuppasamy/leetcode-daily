/**
 * Day 007 - 2026-05-23
 * LeetCode #1752 - Check if Array Is Sorted and Rotated
 * Difficulty: Easy
 * Topic: Array
 * Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 *
 * Problem:
 *   Given an array nums, return true if the array was originally sorted in
 *   non-decreasing order, then rotated some number of positions (including 0).
 *   Otherwise, return false.
 *
 * Approach:
 *   Count the number of "breaks" — positions where nums[i] > nums[(i+1) % n].
 *   In a sorted-and-rotated array, there can be at most one such break point
 *   (the rotation boundary). If breaks <= 1, the array satisfies the condition.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int breaks = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                breaks++;
            }
        }

        return breaks <= 1;
    }
};
