/**
 * Day 010 - 2026-05-26
 * LeetCode #3120 - Count the Number of Special Characters I
 * Difficulty: Easy
 * Topic: Hash Table, String, Bit Manipulation
 * Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/
 *
 * Problem:
 *   A character is "special" if it appears in both lowercase and uppercase
 *   in the string. Given string word, return the count of special characters.
 *
 * Approach:
 *   Use two bitmasks (26 bits each) to track which lowercase and uppercase
 *   letters appear in the string. The bitwise AND of the two masks gives
 *   letters present in both cases. __builtin_popcount counts the set bits.
 *   This runs in a single pass with O(1) space.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

#include <string>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0;
        int upper = 0;

        for (char ch : word) {
            if (islower(ch))
                lower |= (1 << (ch - 'a'));
            else
                upper |= (1 << (ch - 'A'));
        }

        int common = lower & upper;
        return __builtin_popcount(common);
    }
};
