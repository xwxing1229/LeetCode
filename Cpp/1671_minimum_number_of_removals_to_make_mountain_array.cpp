// https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> prefix = getLongestIncreasingSubsequence(nums);
        vector<int> nums_reverse(nums.rbegin(), nums.rend());
        vector<int> suffix = getLongestIncreasingSubsequence(nums_reverse);
        reverse(suffix.begin(), suffix.end());

        int length = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int pre = prefix[i], suf = suffix[i];
            if (pre > 1 && suf > 1) {
                length = max(length, pre+suf-1);
            }
        }
        return nums.size() - length;
    }

    vector<int> getLongestIncreasingSubsequence(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return dp;
    }
};