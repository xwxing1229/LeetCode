// https://leetcode.cn/problems/greatest-sum-divisible-by-three/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp[i][j]: maximum sum of elements chosen from nums[0], ..., nums[i-1]
        //           with sum % 3 = j.
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            int rem = nums[i] % 3;
            for (int j = 0; j < 3; ++j) {
                int match = (3 + j - rem) % 3;
                if (dp[i][match] >= 0) {
                    dp[i+1][j] = max(dp[i][j], dp[i][match] + nums[i]);
                }
                else {
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        return dp[n][0];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,6,5,1,8};
    cout << sol.maxSumDivThree(nums) << '\n';
    return 0;
}