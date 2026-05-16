/**
 * Day 001 - 2026-05-16
 * LeetCode #154 - Find Minimum in Rotated Sorted Array II
 * Difficulty: Hard
 * Topic: Binary Search, Array
 * Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
 *
 * Problem:
 *   Suppose an array of length n sorted in ascending order is rotated between
 *   1 and n times. Given the array nums (may contain duplicates), find and
 *   return the minimum element.
 *
 * Approach:
 *   Binary search variant. Compare nums[mid] with nums[r]:
 *   - If nums[mid] < nums[r]  => minimum is in left half (r = mid)
 *   - If nums[mid] > nums[r]  => minimum is in right half (l = mid + 1)
 *   - If nums[mid] == nums[r] => can't determine side, safely shrink r by 1
 *
 * Time Complexity:  O(log n) average, O(n) worst case (all duplicates)
 * Space Complexity: O(1)
 */

#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[r])
                r = mid;
            else if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r--;
        }
        return nums[l];
    }
};
