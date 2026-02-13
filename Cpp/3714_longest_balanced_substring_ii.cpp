// https://leetcode.cn/problems/longest-balanced-substring-ii/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        auto longestBalancedOneChar = [&]() {
            int res = 0;
            int n = s.size(), left = 0;
            while (left < n) {
                int right = left;
                while (right < n && s[right] == s[left]) {
                    right += 1;
                }
                res = max(res, right - left);
                left = right;
            }
            return res;
        };

        auto longestBalancedTwoChars = [&](const char ch1, const char ch2) {
            int res = 0;
            int n = s.size(), i = 0;
            while (i < n) {
                int diff = 0;
                unordered_map<int, int> record {{diff, i-1}};
                while (i < n && (s[i] == ch1 || s[i] == ch2)) {
                    if (s[i] == ch1) diff += 1;
                    else diff -= 1;
                    if (record.count(diff)) {
                        res = max(res, i - record[diff]);
                    }
                    else {
                        record[diff] = i;
                    }
                    i += 1;
                }
                i += 1;
            }
            return res;
        };

        auto longestBalancedThreeChars = [&]() {
            int res = 0;
            int n = s.size();
            // Convert (diff_1, diff_2) to (diff_1 + n) << 32 | (diff_2 + n).
            long long diff = ((long long)n << 32) | n;
            unordered_map<long long, int> record {{diff, -1}};
            unordered_map<char, int> cnt;
            for (int i = 0; i < n; ++i) {
                cnt[s[i]] += 1;
                int diff_1 = cnt['a'] - cnt['b'], diff_2 = cnt['a'] - cnt['c'];
                diff = ((long long)(diff_1 + n) << 32) | (diff_2 + n);
                if (record.count(diff)) {
                    res = max(res, i - record[diff]);
                }
                else {
                    record[diff] = i;
                }
            }
            return res;
        };

        int res = longestBalancedOneChar();
        res = max(res, longestBalancedTwoChars('a', 'b'));
        res = max(res, longestBalancedTwoChars('a', 'c'));
        res = max(res, longestBalancedTwoChars('b', 'c'));
        res = max(res, longestBalancedThreeChars());
        return res;
    }
};

int main() {
    Solution sol;
    // string s = "abbac";
    string s = "abc";
    cout << sol.longestBalanced(s) << '\n';
    return 0;
}