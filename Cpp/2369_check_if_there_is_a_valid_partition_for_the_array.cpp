// https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        if (n >= 2 && nums[0] == nums[1]) dp[1] = true;
        if (n >= 3 && valid3(nums[0], nums[1], nums[2])) dp[2] = true;
        if (n >= 4 && nums[0] == nums[1] && nums[2] == nums[3]) dp[3] = true;
        for (int i = 4; i < n; ++i) {
            if (dp[i-2] && nums[i-1] == nums[i]) {
                dp[i] = true;
            }
            else if (dp[i-3] && valid3(nums[i-2], nums[i-1], nums[i])) {
                dp[i] = true;
            }
        }
        return dp[n-1];
    }

    bool valid3(int num1, int num2, int num3) {
        if ((num1 == num2 && num2 == num3) || (num2 - num1 == 1 && num3 - num2 == 1)) {
            return true;
        }
        else {
            return false;
        }
    }
};