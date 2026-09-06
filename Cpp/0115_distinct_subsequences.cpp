// https://leetcode.cn/problems/distinct-subsequences/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.size(), nt = t.size();
        if (ns < nt) return 0;
        vector<vector<unsigned>> dp(ns+1, vector<unsigned>(nt+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= ns; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= min(i, nt); ++j) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1]) {
                    dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        return dp[ns][nt];
    }
};