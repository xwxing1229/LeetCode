// https://leetcode.cn/problems/distinct-subsequences-ii/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        // dp[i]: number of distinct subsequences that end with ch,
        // where ch = 'a', 'b', ..., 'z'.
        int mod = 1e9 + 7;
        vector<int> dp(26, 0);
        int total = 0;
        for (char ch: s) {
            int idx = ch - 'a';
            int others = (total - dp[idx] + mod) % mod;
            dp[idx] = 1 + total;
            total = (others + dp[idx]) % mod;
        }
        return total;
    }
};