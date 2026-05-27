/**
 * Day 011 - 2026-05-27
 * LeetCode #3121 - Count the Number of Special Characters II
 * Difficulty: Medium
 * Topic: String, Hash Table
 * Link: https://leetcode.com/problems/count-the-number-of-special-characters-ii/
 *
 * Problem:
 *   A letter is "special" if it appears in both lowercase and uppercase,
 *   and every lowercase occurrence appears before the first uppercase occurrence.
 *
 * Approach:
 *   Store the last index of each lowercase letter and the first index of each
 *   uppercase letter. A character is special if both exist and:
 *   lastLower[i] < firstUpper[i]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> mpl(26, -1);
        vector<int> mpu(26, -1);
        int n = word.size();

        for (int i = 0; i < n; i++) {
            char a = word[i];
            if (islower(a)) {
                mpl[a - 'a'] = i;
            } else {
                if (mpu[a - 'A'] == -1) {
                    mpu[a - 'A'] = i;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (mpu[i] != -1 && mpl[i] != -1 && mpl[i] < mpu[i]) {
                ans++;
            }
        }
        return ans;
    }
};
