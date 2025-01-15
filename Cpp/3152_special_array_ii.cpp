// https://leetcode.cn/problems/special-array-ii/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int pre = nums[0] % 2;
        for (int i = 1; i < n; ++i) {
            int cur = nums[i] % 2;
            if (pre + cur == 1) {
                dp[i] = dp[i-1] + 1;
            }
            pre = cur;
        }

        n = queries.size();
        vector<bool> res(n, false);
        for (int i = 0; i < n; ++i) {
            int left = queries[i][0], right = queries[i][1];
            if (dp[right] >= right - left + 1) {
                res[i] = true;
            }
        }
        return res;
    }
};
