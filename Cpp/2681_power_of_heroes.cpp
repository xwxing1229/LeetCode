// https://leetcode.cn/problems/power-of-heroes/
        
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        // Sort nums. Let dp[i] be the total value of the subsequences
        // that end with nums[i]. Then
        //   dp[i] = nums[i]^2 * (cur + nums[i]),
        // where
        //   cur = dp[i-1]/(nums[i-1]^2) + ... + dp[0]/(nums[0]^2).
        // Then res = sum(dp[i]) % 1000000007.
        int mod = 1000000007;

        sort(nums.begin(), nums.end());
        int res = 0;
        long cur = 0, cumsum = 0;
        for (int num: nums) {
            cur = cumsum + num;
            long val = (((long)num * num % mod) * cur) % mod;
            cumsum = (cumsum + cur) % mod;

            res = (val + res) % mod;
        }
        return res;
    }
};