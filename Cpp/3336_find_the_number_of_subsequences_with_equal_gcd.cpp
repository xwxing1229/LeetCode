// https://leetcode.cn/problems/find-the-number-of-subsequences-with-equal-gcd/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int mod = 1e9 + 7;
        int max_ = nums[0];
        for (int num: nums) {
            max_ = max(max_, num);
        }

        vector<vector<int>> dp(max_+1, vector<int>(max_+1, 0));
        dp[0][0] = 1;
        for (int num: nums) {
            vector<vector<int>> dp_next(max_+1, vector<int>(max_+1));
            for (int j = 0; j <= max_; ++j) {
                int gcd_1 = gcd(j, num);
                for (int k = 0; k <= max_; ++k) {
                    if (dp[j][k] == 0) continue;
                    int gcd_2 = gcd(k, num);
                    dp_next[j][k] = (dp_next[j][k] + dp[j][k]) % mod;
                    dp_next[gcd_1][k] = (dp_next[gcd_1][k] + dp[j][k]) % mod;
                    dp_next[j][gcd_2] = (dp_next[j][gcd_2] + dp[j][k]) % mod;
                }
            }
            dp = move(dp_next);
        }

        int res = 0;
        for (int j = 1; j <= max_; ++j) {
            res = (res + dp[j][j]) % mod;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,4};
    cout << sol.subsequencePairCount(nums) << '\n';
    return 0;
}