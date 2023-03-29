// https://leetcode.cn/problems/count-sorted-vowel-strings/

class Solution {
public:
    int countVowelStrings(int n) {
        // dp[i][j]: number of valid strings of length i that end with the jth vowel
        // dp[i][0] = 1
        // dp[i][j] = dp[i-1][0] + dp[i-1][1] + ... + dp[i-1][j-1] + dp[i-1][j]
        vector<int> dp(5, 1);
        for (int i = 0; i < n-1; ++i) {
            int tmp = 1;
            for (int j = 1; j < 5; ++j) {
                tmp += dp[j];
                dp[j] = tmp;
            }
        }
        int res = 0;
        for (int cnt: dp) res += cnt;
        return res;
    }
};
