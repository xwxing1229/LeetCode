// https://leetcode.cn/problems/number-of-sets-of-k-non-overlapping-line-segments/

#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int size = 1; size <= n; ++size) {
            dp[size][0] = 1;
        }
        for (int cnt = 1; cnt <= k; ++cnt) {
            int presum = 0;
            for (int size = cnt+1; size <= n; ++size) {
                presum = (presum + dp[size-1][cnt-1]) % mod;
                dp[size][cnt] = (dp[size-1][cnt] + presum) % mod;
            }
        }
        return dp[n][k];
    }
};