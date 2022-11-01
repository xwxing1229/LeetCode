// https://leetcode.cn/problems/distinct-subsequences-ii/

class Solution {
public:
    int distinctSubseqII(string s) {
        // dp[i]: number of distinct subsequences that end with s[i]
        // last[i]: index in s of the last occurrence of the ith letter in "abc...xyz"
        int n = s.size();
        vector<int> dp(n, 1), last(26, -1);
        for (int i = 0; i < n; ++i) {
            for (int idx: last) {
                if (idx != -1) {
                    dp[i] = (dp[i] + dp[idx]) % 1000000007;
                }
            }
            last[s[i] - 'a'] = i;
        }

        int res = 0;
        for (int idx: last) {
            if (idx != -1) {
                res = (res + dp[idx]) % 1000000007;
            }
        }
        return res;
    }
};
