/**
 * Day 006 - 2026-05-22
 * LeetCode #33 - Search in Rotated Sorted Array
 * Difficulty: Medium
 * Topic: Array, Binary Search
 * Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * Problem:
 *   Given an integer array nums sorted in ascending order and then rotated at
 *   an unknown pivot, and a target value, return the index of target in nums,
 *   or -1 if not present. Must run in O(log n).
 *
 * Approach:
 *   Two-pass binary search:
 *   1. Find the rotation pivot (index of smallest element) by comparing
 *      nums[mid] with nums.back(). If nums[mid] > nums.back(), pivot is to
 *      the right; otherwise it is to the left (or at mid).
 *   2. Run a standard binary search on the "virtually unrotated" array by
 *      mapping each virtual index mid -> real index (mid + rot) % n.
 *      This lets us binary search without any branching on sorted halves.
 *
 * Time Complexity:  O(log n)
 * Space Complexity: O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        // Step 1: find rotation pivot
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums.back()) lo = mid + 1;
            else hi = mid;
        }

        int rot = lo;
        lo = 0, hi = n - 1;

        // Step 2: binary search on virtually unrotated array
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int real = (mid + rot) % n;

            if (nums[real] == target) return real;
            if (nums[real] < target)  lo = mid + 1;
            else                      hi = mid - 1;
        }

        return -1;
    }
};
